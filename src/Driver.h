#ifndef DRIVER_H
#define DRIVER_H

#include "StatCompBaseVisitor.h"
#include "StatCompParser.h"
#include "StatCompLexer.h"

// Headers de LLVM
#include "llvm/ADT/APFloat.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

// Headers para JIT
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Utils/Cloning.h"

#include <any>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace antlr4;
using namespace llvm;
using namespace std;

class Driver : public StatCompBaseVisitor {
private:
    std::unique_ptr<LLVMContext> context;
    std::unique_ptr<Module> module;
    std::unique_ptr<IRBuilder<>> irBuilder;
    
    Value* formatStr;
    FunctionCallee printfFunc;
    
    Value* tableHeaderFormat;
    Value* tableLineFormat;
    Value* tableRelFreqFormat;
    Value* tableRelFreqHeaderFormat;
    Value* tableFooterFormat;
    Value* barChartHeaderFormat;
    Value* barChartBarFormat;
    Value* barChartHashFormat;
    
    std::map<std::string, AllocaInst*> namedValues;
    std::map<std::string, std::pair<AllocaInst*, int>> namedArrays;

    // ============================================
    // HELPER: Obtener valores de un array completo
    // ============================================
    vector<Value*> getArrayValues(const string& arrayName) {
        vector<Value*> values;
        
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] Array '" << arrayName << "' no encontrado" << endl;
            return values;
        }
        
        AllocaInst *arrayAlloca = namedArrays[arrayName].first;
        int arraySize = namedArrays[arrayName].second;
        Type *DoubleTy = Type::getDoubleTy(*context);
        
        for (int i = 0; i < arraySize; i++) {
            Value *indexValue = ConstantInt::get(Type::getInt32Ty(*context), i);
            Value *elementPtr = irBuilder->CreateGEP(DoubleTy, arrayAlloca, indexValue);
            Value *loadedValue = irBuilder->CreateLoad(DoubleTy, elementPtr);
            values.push_back(loadedValue);
        }
        
        return values;
    }

    // ============================================
    // HELPER: Suma de un array
    // ============================================
    Value* calculateSum(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        
        Value *sum = ConstantFP::get(*context, APFloat(0.0));
        for (Value *val : values) {
            sum = irBuilder->CreateFAdd(sum, val, "sum");
        }
        return sum;
    }

      // ============================================
      // HELPER: Media de un array
      // ============================================
      Value* calculateMean(const vector<Value*>& values) {
          if (values.empty()) return nullptr;
          
          Value *sum = calculateSum(values);
          Value *count = ConstantFP::get(*context, APFloat((double)values.size()));
          return irBuilder->CreateFDiv(sum, count, "mean");
      }

      // ============================================
      // HELPER: Mínimo de un array
      // ============================================
      Value* calculateMin(const vector<Value*>& values) {
          if (values.empty()) return nullptr;
          
          Value *minVal = values[0];
          for (size_t i = 1; i < values.size(); i++) {
              Value *cmp = irBuilder->CreateFCmpOLT(minVal, values[i], "cmp");
              minVal = irBuilder->CreateSelect(cmp, minVal, values[i], "min");
          }
          return minVal;
      }

      // ============================================
      // HELPER: Máximo de un array
      // ============================================
      Value* calculateMax(const vector<Value*>& values) {
          if (values.empty()) return nullptr;
          
          Value *maxVal = values[0];
          for (size_t i = 1; i < values.size(); i++) {
              Value *cmp = irBuilder->CreateFCmpOGT(maxVal, values[i], "cmp");
              maxVal = irBuilder->CreateSelect(cmp, maxVal, values[i], "max");
          }
          return maxVal;
      }

      // ============================================
      // HELPER: Varianza de un array
      // ============================================
      Value* calculateVariance(const vector<Value*>& values) {
          if (values.empty()) return nullptr;
          
          Value *mean = calculateMean(values);
          Value *sumSquares = ConstantFP::get(*context, APFloat(0.0));
          
          for (Value *val : values) {
              Value *diff = irBuilder->CreateFSub(val, mean, "diff");
              Value *square = irBuilder->CreateFMul(diff, diff, "square");
              sumSquares = irBuilder->CreateFAdd(sumSquares, square, "sumSquares");
          }
          
          Value *count = ConstantFP::get(*context, APFloat((double)values.size()));
          Value *variance = irBuilder->CreateFDiv(sumSquares, count, "variance");
          
          return variance;
      }

    // ============================================
    // HELPER: Desviación estándar de un array
    // ============================================
    Value* calculateStdev(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        
        Value *variance = calculateVariance(values);
        auto sqrtFunc = Intrinsic::getOrInsertDeclaration(
            module. get(), 
            Intrinsic::sqrt, 
            {Type::getDoubleTy(*context)}
        );
        
        Value *stdev = irBuilder->CreateCall(sqrtFunc, {variance}, "stdev");
        return stdev;
    }

    // ============================================
    // HELPER: Mediana de un array (aproximada)
    // ============================================
    Value* calculateMedian(const vector<Value*>& values) {
        if (values. empty()) return nullptr;
        
        Value *minVal = calculateMin(values);
        Value *maxVal = calculateMax(values);
        Value *sum = irBuilder->CreateFAdd(minVal, maxVal, "sum_minmax");
        Value *two = ConstantFP::get(*context, APFloat(2.0));
        Value *median = irBuilder->CreateFDiv(sum, two, "median_approx");
        
        return median;
    }

    // ============================================
    // HELPER: Moda de un array (aproximada)
    // ============================================
    Value* calculateMode(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        return values[0];
    }

    // ============================================
    // HELPER: Coeficiente de Variación (CV%)
    // CV = (Stdev / Mean) * 100
    // ============================================
    Value* calculateCoeffVar(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        
        Value *mean = calculateMean(values);
        Value *stdev = calculateStdev(values);
        
        // CV = (stdev / mean) * 100
        Value *cv = irBuilder->CreateFDiv(stdev, mean, "cv_ratio");
        Value *hundred = ConstantFP::get(*context, APFloat(100.0));
        Value *cvPercent = irBuilder->CreateFMul(cv, hundred, "cv_percent");
        
        return cvPercent;
    }

    // ============================================
    // HELPER: Asimetría (Skewness)
    // Skewness = E[((X - mean) / stdev)^3]
    // ============================================
    Value* calculateSkewness(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        
        Value *mean = calculateMean(values);
        Value *stdev = calculateStdev(values);
        
        // Suma de ((x - mean) / stdev)^3
        Value *sumCubes = ConstantFP::get(*context, APFloat(0.0));
        
        for (Value *val : values) {
            // z = (x - mean) / stdev
            Value *diff = irBuilder->CreateFSub(val, mean, "diff");
            Value *z = irBuilder->CreateFDiv(diff, stdev, "z_score");
            
            // z^3
            Value *z_squared = irBuilder->CreateFMul(z, z, "z_sq");
            Value *z_cubed = irBuilder->CreateFMul(z_squared, z, "z_cubed");
            
            sumCubes = irBuilder->CreateFAdd(sumCubes, z_cubed, "sum_cubes");
        }
        
        // Dividir por n
        Value *n = ConstantFP::get(*context, APFloat((double)values.size()));
        Value *skewness = irBuilder->CreateFDiv(sumCubes, n, "skewness");
        
        return skewness;
    }

    // ============================================
    // HELPER: Rango Intercuartílico (IQR)
    // IQR = Q3 - Q1 (aproximado como percentiles)
    // ============================================
    Value* calculateIQR(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        
        // Aproximación simple: IQR ≈ Range * 0.5
        // En una distribución normal, IQR ≈ 1.35 * σ
        // Para propósitos didácticos usamos Q3-Q1 aproximado
        
        Value *minVal = calculateMin(values);
        Value *maxVal = calculateMax(values);
        Value *range = irBuilder->CreateFSub(maxVal, minVal, "range");
        
        // Aproximación: IQR ≈ 0.5 * Range (simplificado)
        Value *halfFactor = ConstantFP::get(*context, APFloat(0.5));
        Value *iqr = irBuilder->CreateFMul(range, halfFactor, "iqr_approx");
        
        return iqr;
    }

    // ============================================
    // HELPER: Curtosis (Kurtosis)
    // Kurtosis = E[((X - mean) / stdev)^4] - 3
    // ============================================
    Value* calculateKurtosis(const vector<Value*>& values) {
        if (values.empty()) return nullptr;
        
        Value *mean = calculateMean(values);
        Value *stdev = calculateStdev(values);
        
        // Suma de ((x - mean) / stdev)^4
        Value *sumFourth = ConstantFP::get(*context, APFloat(0.0));
        
        for (Value *val : values) {
            // z = (x - mean) / stdev
            Value *diff = irBuilder->CreateFSub(val, mean, "diff");
            Value *z = irBuilder->CreateFDiv(diff, stdev, "z_score");
            
            // z^4
            Value *z_squared = irBuilder->CreateFMul(z, z, "z_sq");
            Value *z_fourth = irBuilder->CreateFMul(z_squared, z_squared, "z_fourth");
            
            sumFourth = irBuilder->CreateFAdd(sumFourth, z_fourth, "sum_fourth");
        }
        
        // Dividir por n y restar 3 (excess kurtosis)
        Value *n = ConstantFP::get(*context, APFloat((double)values.size()));
        Value *rawKurtosis = irBuilder->CreateFDiv(sumFourth, n, "raw_kurtosis");
        Value *three = ConstantFP::get(*context, APFloat(3.0));
        Value *excessKurtosis = irBuilder->CreateFSub(rawKurtosis, three, "excess_kurtosis");
        
        return excessKurtosis;
    }

    // ============================================
    // HELPER: Imprimir tabla de frecuencias (valores únicos)
    // ============================================
    void printFrequencyTable(const string& arrayName, const string& tableType) {
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] Array '" << arrayName << "' no encontrado" << endl;
            return;
        }
        
        int arraySize = namedArrays[arrayName].second;
        Type *Int32Ty = Type::getInt32Ty(*context);
        Type *Int1Ty = Type::getInt1Ty(*context);
        Type *DoubleTy = Type::getDoubleTy(*context);
        
        vector<Value*> values = getArrayValues(arrayName);
        
        // Usar header diferente según el tipo de tabla
        if (tableType == "RelFreq") {
            irBuilder->CreateCall(printfFunc, {tableRelFreqHeaderFormat});
        } else {
            irBuilder->CreateCall(printfFunc, {tableHeaderFormat});
        }
        
        for (int i = 0; i < arraySize; i++) {
            Value *currentValue = values[i];
            
            Value *alreadyPrinted = ConstantInt::get(Int1Ty, 0);
            
            for (int j = 0; j < i; j++) {
                Value *previousValue = values[j];
                Value *isEqual = irBuilder->CreateFCmpOEQ(currentValue, previousValue, "check_duplicate");
                alreadyPrinted = irBuilder->CreateOr(alreadyPrinted, isEqual, "already_printed");
            }
            
            Function *currentFunc = irBuilder->GetInsertBlock()->getParent();
            
            BasicBlock *printBlock = BasicBlock::Create(*context, "print_value_" + to_string(i), currentFunc);
            BasicBlock *skipBlock = BasicBlock::Create(*context, "skip_value_" + to_string(i), currentFunc);
            
            Value *shouldPrint = irBuilder->CreateNot(alreadyPrinted, "should_print");
            irBuilder->CreateCondBr(shouldPrint, printBlock, skipBlock);
            
            irBuilder->SetInsertPoint(printBlock);
            
            Value *count = ConstantInt::get(Int32Ty, 0);
            
            for (int j = 0; j < arraySize; j++) {
                Value *compareValue = values[j];
                Value *isEqual = irBuilder->CreateFCmpOEQ(currentValue, compareValue, "cmp_eq");
                Value *increment = irBuilder->CreateSelect(isEqual, ConstantInt::get(Int32Ty, 1), ConstantInt::get(Int32Ty, 0), "increment");
                count = irBuilder->CreateAdd(count, increment, "count");
            }
            
            if (tableType == "Freq" || tableType == "AbsFreq") {
                irBuilder->CreateCall(printfFunc, {tableLineFormat, currentValue, count});
            }
            else if (tableType == "RelFreq") {
                Value *countDouble = irBuilder->CreateSIToFP(count, DoubleTy, "count_double");
                Value *total = ConstantFP::get(*context, APFloat((double)arraySize));
                Value *relFreq = irBuilder->CreateFDiv(countDouble, total, "relfreq");
                irBuilder->CreateCall(printfFunc, {tableRelFreqFormat, currentValue, relFreq});
            }
            
            irBuilder->CreateBr(skipBlock);
            irBuilder->SetInsertPoint(skipBlock);
        }
        
        irBuilder->CreateCall(printfFunc, {tableFooterFormat});
    }

    // ============================================
    // HELPER: Gráfico de Barras
    // ============================================
    void printBarChart(const string& arrayName) {
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] Array '" << arrayName << "' no encontrado" << endl;
            return;
        }
        
        int arraySize = namedArrays[arrayName].second;
        Type *Int32Ty = Type::getInt32Ty(*context);
        Type *Int1Ty = Type::getInt1Ty(*context);
        Type *DoubleTy = Type::getDoubleTy(*context);
        
        vector<Value*> values = getArrayValues(arrayName);
        
        // Imprimir header
        irBuilder->CreateCall(printfFunc, {barChartHeaderFormat});
        
        // Para cada valor único, contar frecuencia y dibujar barra
        for (int i = 0; i < arraySize; i++) {
            Value *currentValue = values[i];
            
            // Verificar si ya fue procesado
            Value *alreadyPrinted = ConstantInt::get(Int1Ty, 0);
            for (int j = 0; j < i; j++) {
                Value *previousValue = values[j];
                Value *isEqual = irBuilder->CreateFCmpOEQ(currentValue, previousValue, "check_dup");
                alreadyPrinted = irBuilder->CreateOr(alreadyPrinted, isEqual, "already_printed");
            }
            
            Function *currentFunc = irBuilder->GetInsertBlock()->getParent();
            BasicBlock *printBlock = BasicBlock::Create(*context, "print_bar_" + to_string(i), currentFunc);
            BasicBlock *skipBlock = BasicBlock::Create(*context, "skip_bar_" + to_string(i), currentFunc);
            
            Value *shouldPrint = irBuilder->CreateNot(alreadyPrinted, "should_print");
            irBuilder->CreateCondBr(shouldPrint, printBlock, skipBlock);
            
            irBuilder->SetInsertPoint(printBlock);
            
            // Contar frecuencia
            Value *count = ConstantInt::get(Int32Ty, 0);
            for (int j = 0; j < arraySize; j++) {
                Value *compareValue = values[j];
                Value *isEqual = irBuilder->CreateFCmpOEQ(currentValue, compareValue, "cmp_eq");
                Value *increment = irBuilder->CreateSelect(isEqual, ConstantInt::get(Int32Ty, 1), ConstantInt::get(Int32Ty, 0), "inc");
                count = irBuilder->CreateAdd(count, increment, "count");
            }
            
            // Imprimir valor
            irBuilder->CreateCall(printfFunc, {barChartBarFormat, currentValue});
            
            // Imprimir barras (# symbols) - loop de 0 a count
            BasicBlock *loopCondBB = BasicBlock::Create(*context, "loop_cond_" + to_string(i), currentFunc);
            BasicBlock *loopBodyBB = BasicBlock::Create(*context, "loop_body_" + to_string(i), currentFunc);
            BasicBlock *loopEndBB = BasicBlock::Create(*context, "loop_end_" + to_string(i), currentFunc);
            
            // Inicializar contador de loop
            AllocaInst *loopVar = irBuilder->CreateAlloca(Int32Ty, nullptr, "loop_var");
            irBuilder->CreateStore(ConstantInt::get(Int32Ty, 0), loopVar);
            irBuilder->CreateBr(loopCondBB);
            
            // Condición del loop
            irBuilder->SetInsertPoint(loopCondBB);
            Value *loopCounter = irBuilder->CreateLoad(Int32Ty, loopVar, "loop_counter");
            Value *loopCond = irBuilder->CreateICmpSLT(loopCounter, count, "loop_cond");
            irBuilder->CreateCondBr(loopCond, loopBodyBB, loopEndBB);
            
            // Cuerpo del loop - imprimir '#'
            irBuilder->SetInsertPoint(loopBodyBB);
            irBuilder->CreateCall(printfFunc, {barChartHashFormat});
            Value *nextCounter = irBuilder->CreateAdd(loopCounter, ConstantInt::get(Int32Ty, 1), "next_counter");
            irBuilder->CreateStore(nextCounter, loopVar);
            irBuilder->CreateBr(loopCondBB);
            
            // Después del loop - imprimir frecuencia y newline
            irBuilder->SetInsertPoint(loopEndBB);
            Constant *countFormatStr = ConstantDataArray::getString(*context, " (%d)\n");
            GlobalVariable *countFormatVar = new GlobalVariable(*module, countFormatStr->getType(), true, GlobalValue::PrivateLinkage, countFormatStr, ".str_count_fmt");
            Value *countFormat = irBuilder->CreateInBoundsGEP(countFormatStr->getType(), countFormatVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});
            irBuilder->CreateCall(printfFunc, {countFormat, count});
            
            irBuilder->CreateBr(skipBlock);
            irBuilder->SetInsertPoint(skipBlock);
        }
        
        irBuilder->CreateCall(printfFunc, {tableFooterFormat});
    }

public:
    Driver() {
        context = std::make_unique<LLVMContext>();
        module = std::make_unique<Module>("StatCompModule", *context);
        irBuilder = std::make_unique<IRBuilder<>>(*context);
    }

    Module* getModule() {
        return module.get();
    }

    Value* getVal(std::any v) {
        try {
            if (v.has_value()) {
                return std::any_cast<Value*>(v);
            }
        } catch (...) {}
        return nullptr;
    }

    // ============================================
    // VISITOR: Programa Principal
    // ============================================
    virtual std::any visitProg(StatCompParser::ProgContext *ctx) override {
        Type *Int32Ty = Type::getInt32Ty(*context);
        FunctionType *mainFuncType = FunctionType::get(Int32Ty, false);
        Function *mainFunc = Function::Create(mainFuncType, Function::ExternalLinkage, "main", module.get());

        BasicBlock *entryBB = BasicBlock::Create(*context, "entry", mainFunc);
        irBuilder->SetInsertPoint(entryBB);
        
        Constant *s = ConstantDataArray::getString(*context, "Result: %f\n");
        GlobalVariable *gVar = new GlobalVariable(*module, s->getType(), true, GlobalValue::PrivateLinkage, s, ". str");
        formatStr = irBuilder->CreateInBoundsGEP(s->getType(), gVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *headerStr = ConstantDataArray::getString(*context, "\n===== TABLA DE FRECUENCIAS =====\nValor    Frecuencia\n--------------------------------\n");
        GlobalVariable *headerVar = new GlobalVariable(*module, headerStr->getType(), true, GlobalValue::PrivateLinkage, headerStr, ".str_header");
        tableHeaderFormat = irBuilder->CreateInBoundsGEP(headerStr->getType(), headerVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *lineStr = ConstantDataArray::getString(*context, "%.2f        %d\n");
        GlobalVariable *lineVar = new GlobalVariable(*module, lineStr->getType(), true, GlobalValue::PrivateLinkage, lineStr, ".str_line");
        tableLineFormat = irBuilder->CreateInBoundsGEP(lineStr->getType(), lineVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *relFreqStr = ConstantDataArray::getString(*context, "%.2f        %.4f\n");
        GlobalVariable *relFreqVar = new GlobalVariable(*module, relFreqStr->getType(), true, GlobalValue::PrivateLinkage, relFreqStr, ".str_relfreq");
        tableRelFreqFormat = irBuilder->CreateInBoundsGEP(relFreqStr->getType(), relFreqVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *relFreqHeaderStr = ConstantDataArray::getString(*context, "\n===== TABLA DE FRECUENCIAS =====\nValor    Freq. Relativa\n--------------------------------\n");
        GlobalVariable *relFreqHeaderVar = new GlobalVariable(*module, relFreqHeaderStr->getType(), true, GlobalValue::PrivateLinkage, relFreqHeaderStr, ".str_relfreq_header");
        tableRelFreqHeaderFormat = irBuilder->CreateInBoundsGEP(relFreqHeaderStr->getType(), relFreqHeaderVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *footerStr = ConstantDataArray::getString(*context, "================================\n\n");
        GlobalVariable *footerVar = new GlobalVariable(*module, footerStr->getType(), true, GlobalValue::PrivateLinkage, footerStr, ".str_footer");
        tableFooterFormat = irBuilder->CreateInBoundsGEP(footerStr->getType(), footerVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        // Formatos para gráfico de barras
        Constant *barHeaderStr = ConstantDataArray::getString(*context, "\n===== GRAFICO DE BARRAS =====\n");
        GlobalVariable *barHeaderVar = new GlobalVariable(*module, barHeaderStr->getType(), true, GlobalValue::PrivateLinkage, barHeaderStr, ".str_bar_header");
        barChartHeaderFormat = irBuilder->CreateInBoundsGEP(barHeaderStr->getType(), barHeaderVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *barFormatStr = ConstantDataArray::getString(*context, "%.2f | ");
        GlobalVariable *barFormatVar = new GlobalVariable(*module, barFormatStr->getType(), true, GlobalValue::PrivateLinkage, barFormatStr, ".str_bar_format");
        barChartBarFormat = irBuilder->CreateInBoundsGEP(barFormatStr->getType(), barFormatVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        Constant *hashStr = ConstantDataArray::getString(*context, "#");
        GlobalVariable *hashVar = new GlobalVariable(*module, hashStr->getType(), true, GlobalValue::PrivateLinkage, hashStr, ".str_hash");
        barChartHashFormat = irBuilder->CreateInBoundsGEP(hashStr->getType(), hashVar, {ConstantInt::get(Int32Ty, 0), ConstantInt::get(Int32Ty, 0)});

        std::vector<Type*> printfArgs = {PointerType::getUnqual(*context)};
        FunctionType *printfType = FunctionType::get(Int32Ty, printfArgs, true);
        printfFunc = module->getOrInsertFunction("printf", printfType);

        // Visitar cada statement del programa explícitamente
        for (auto stmt : ctx->stmt()) {
            visit(stmt);
        }

        irBuilder->CreateRet(ConstantInt::get(Int32Ty, 0));
        verifyFunction(*mainFunc);
        return std::any();
    }

    // ============================================
    // VISITOR: Imprimir
    // ============================================
    virtual std::any visitPrintExpr(StatCompParser::PrintExprContext *ctx) override {
        Value *val = getVal(visit(ctx->expr()));
        if (val) {
            std::vector<Value*> args;
            
            // Detectar si es string (puntero a i8) o número
            if (val->getType()->isPointerTy()) {
                // Es un string - usar formato %s
                Constant *strFormat = ConstantDataArray::getString(*context, "%s\n", true);
                GlobalVariable *formatVar = new GlobalVariable(
                    *module, 
                    strFormat->getType(), 
                    true, 
                    GlobalValue::PrivateLinkage, 
                    strFormat, 
                    ".str_fmt"
                );
                Type *Int32Ty = Type::getInt32Ty(*context);
                Value *zero = ConstantInt::get(Int32Ty, 0);
                Value *formatPtr = irBuilder->CreateInBoundsGEP(
                    strFormat->getType(), 
                    formatVar, 
                    {zero, zero}
                );
                args.push_back(formatPtr);
                args.push_back(val);
            } else {
                // Es un número - usar formato %f
                if (val->getType()->isIntegerTy()) {
                    val = irBuilder->CreateSIToFP(val, Type::getDoubleTy(*context), "cast_to_double");
                }
                args.push_back(formatStr);
                args.push_back(val);
            }
            
            irBuilder->CreateCall(printfFunc, args);
        }
        return std::any();
    }

    // ============================================
    // VISITOR: Literales
    // ============================================
    virtual std::any visitExprLiteral(StatCompParser::ExprLiteralContext *ctx) override {
        string text = ctx->getText();
        double value = std::stod(text);
        return (Value*)ConstantFP::get(*context, APFloat(value));
    }

    virtual std::any visitExprPar(StatCompParser::ExprParContext *ctx) override {
        return visit(ctx->expr());
    }

    virtual std::any visitExprNeg(StatCompParser::ExprNegContext *ctx) override {
        Value *val = getVal(visit(ctx->expr()));
        if (! val) return nullptr;
        return (Value*)irBuilder->CreateFNeg(val, "negtmp");
    }

    // ============================================
    // VISITOR: Operaciones aritméticas
    // ============================================
    virtual std::any visitExprAddSub(StatCompParser::ExprAddSubContext *ctx) override {
        Value *L = getVal(visit(ctx->expr(0)));
        Value *R = getVal(visit(ctx->expr(1)));
        if (!L || !R) return nullptr;
        if (ctx->ADD()) return (Value*)irBuilder->CreateFAdd(L, R, "addtmp");
        if (ctx->SUB()) return (Value*)irBuilder->CreateFSub(L, R, "subtmp");
        return nullptr;
    }

    virtual std::any visitExprMulDiv(StatCompParser::ExprMulDivContext *ctx) override {
        Value *L = getVal(visit(ctx->expr(0)));
        Value *R = getVal(visit(ctx->expr(1)));
        if (!L || !R) return nullptr;
        string op = ctx->children[1]->getText();
        if (op == "*") return (Value*)irBuilder->CreateFMul(L, R, "multmp");
        if (op == "/") return (Value*)irBuilder->CreateFDiv(L, R, "divtmp");
        if (op == "//") {
            Value *divResult = irBuilder->CreateFDiv(L, R, "fdivtmp");
            auto truncFunc = Intrinsic::getOrInsertDeclaration(module.get(), Intrinsic::trunc, {Type::getDoubleTy(*context)});
            return (Value*)irBuilder->CreateCall(truncFunc, {divResult}, "inttmp");
        }
        if (op == "%") return (Value*)irBuilder->CreateFRem(L, R, "modtmp");
        return nullptr;
    }

    virtual std::any visitExprPow(StatCompParser::ExprPowContext *ctx) override {
        Value *base = getVal(visit(ctx->expr(0)));
        Value *exp = getVal(visit(ctx->expr(1)));
        if (!base || !exp) return nullptr;
        auto powFunc = Intrinsic::getOrInsertDeclaration(module.get(), Intrinsic::pow, {Type::getDoubleTy(*context)});
        return (Value*)irBuilder->CreateCall(powFunc, {base, exp}, "powtmp");
    }

    // ============================================
    // VISITOR: Variables
    // ============================================
    virtual std::any visitUpdateSymbol(StatCompParser::UpdateSymbolContext *ctx) override {
        string varName = ctx->ID()->getText();
        Value *initValue = getVal(visit(ctx->expr()));
        if (!initValue) {
            cerr << "[ERROR] No se pudo evaluar la expresión para " << varName << endl;
            return nullptr;
        }
        Function *currentFunc = irBuilder->GetInsertBlock()->getParent();
        IRBuilder<> tmpBuilder(&currentFunc->getEntryBlock(), currentFunc->getEntryBlock(). begin());
        AllocaInst *alloca = tmpBuilder.CreateAlloca(Type::getDoubleTy(*context), nullptr, varName);
        namedValues[varName] = alloca;
        irBuilder->CreateStore(initValue, alloca);
        return initValue;
    }

    virtual std::any visitExprVar(StatCompParser::ExprVarContext *ctx) override {
        string varName = ctx->ID()->getText();
        if (namedValues.find(varName) == namedValues.end()) {
            cerr << "[ERROR] Variable '" << varName << "' no definida" << endl;
            return nullptr;
        }
        AllocaInst *alloca = namedValues[varName];
        Value *loadedValue = irBuilder->CreateLoad(Type::getDoubleTy(*context), alloca, varName + "_val");
        return (Value*)loadedValue;
    }

    // ============================================
    // VISITOR: Arrays
    // ============================================
    virtual std::any visitArrayDecl(StatCompParser::ArrayDeclContext *ctx) override {
        string arrayName = ctx->ID()->getText();
        vector<double> numbers;
        if (ctx->arrayInit() && ctx->arrayInit()->numlist()) {
            auto numlist = ctx->arrayInit()->numlist();
            for (auto numCtx : numlist->num()) {
                string text = numCtx->getText();
                double value = std::stod(text);
                numbers.push_back(value);
            }
        }
        int arraySize = numbers.size();
        if (arraySize == 0) {
            cerr << "[ERROR] Array '" << arrayName << "' está vacío" << endl;
            return nullptr;
        }
        Function *currentFunc = irBuilder->GetInsertBlock()->getParent();
        IRBuilder<> tmpBuilder(&currentFunc->getEntryBlock(), currentFunc->getEntryBlock().begin());
        Type *DoubleTy = Type::getDoubleTy(*context);
        AllocaInst *arrayAlloca = tmpBuilder.CreateAlloca(DoubleTy, ConstantInt::get(Type::getInt32Ty(*context), arraySize), arrayName);
        namedArrays[arrayName] = {arrayAlloca, arraySize};
        for (int i = 0; i < arraySize; i++) {
            Value *indexValue = ConstantInt::get(Type::getInt32Ty(*context), i);
            Value *elementPtr = irBuilder->CreateGEP(DoubleTy, arrayAlloca, indexValue, arrayName + "[" + to_string(i) + "]");
            Value *valueToStore = ConstantFP::get(*context, APFloat(numbers[i]));
            irBuilder->CreateStore(valueToStore, elementPtr);
        }
        cout << "[INFO] Array '" << arrayName << "' declarado con " << arraySize << " elementos" << endl;
        return nullptr;
    }

    virtual std::any visitExprArrayAccess(StatCompParser::ExprArrayAccessContext *ctx) override {
        string arrayName = ctx->ID()->getText();
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] Array '" << arrayName << "' no definido" << endl;
            return nullptr;
        }
        Value *indexValue = getVal(visit(ctx->expr()));
        if (!indexValue) {
            cerr << "[ERROR] Índice inválido para array '" << arrayName << "'" << endl;
            return nullptr;
        }
        if (indexValue->getType()->isDoubleTy()) {
            indexValue = irBuilder->CreateFPToSI(indexValue, Type::getInt32Ty(*context), "index_int");
        }
        AllocaInst *arrayAlloca = namedArrays[arrayName]. first;
        Type *DoubleTy = Type::getDoubleTy(*context);
        Value *elementPtr = irBuilder->CreateGEP(DoubleTy, arrayAlloca, indexValue, arrayName + "_elem");
        Value *loadedValue = irBuilder->CreateLoad(DoubleTy, elementPtr, arrayName + "_val");
        return (Value*)loadedValue;
    }

    // ============================================
    // VISITOR: Funciones estadísticas
    // ============================================
    virtual std::any visitExprStatFunc(StatCompParser::ExprStatFuncContext *ctx) override {
        string funcName = ctx->statFunc()->getText();
        if (! ctx->arglist() || ctx->arglist()->expr(). empty()) {
            cerr << "[ERROR] Función '" << funcName << "' requiere argumentos" << endl;
            return nullptr;
        }
        auto firstExpr = ctx->arglist()->expr(0);
        if (funcName == "Square_root") {
            Value *val = getVal(visit(firstExpr));
            if (val) {
                auto sqrtFunc = Intrinsic::getOrInsertDeclaration(module.get(), Intrinsic::sqrt, {Type::getDoubleTy(*context)});
                Value *result = irBuilder->CreateCall(sqrtFunc, {val}, "sqrt");
                cout << "[INFO] Calculando Square_root" << endl;
                return (Value*)result;
            }
            cerr << "[ERROR] No se pudo evaluar argumento de Square_root" << endl;
            return nullptr;
        }
        string arrayName = firstExpr->getText();
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] '" << arrayName << "' no es un array definido" << endl;
            return nullptr;
        }
        vector<Value*> values = getArrayValues(arrayName);
        if (values. empty()) {
            cerr << "[ERROR] Array vacío en función '" << funcName << "'" << endl;
            return nullptr;
        }
        Value *result = nullptr;
        if (funcName == "Mean") {
            result = calculateMean(values);
            cout << "[INFO] Calculando Mean(" << arrayName << ")" << endl;
        } 
        else if (funcName == "Sum") {
            result = calculateSum(values);
            cout << "[INFO] Calculando Sum(" << arrayName << ")" << endl;
        }
        else if (funcName == "Min") {
            result = calculateMin(values);
            cout << "[INFO] Calculando Min(" << arrayName << ")" << endl;
        }
        else if (funcName == "Max") {
            result = calculateMax(values);
            cout << "[INFO] Calculando Max(" << arrayName << ")" << endl;
        }
        else if (funcName == "Count") {
            result = ConstantFP::get(*context, APFloat((double)values.size()));
            cout << "[INFO] Calculando Count(" << arrayName << ")" << endl;
        }
        else if (funcName == "Var") {
            result = calculateVariance(values);
            cout << "[INFO] Calculando Var(" << arrayName << ")" << endl;
        }
        else if (funcName == "Stdev") {
            result = calculateStdev(values);
            cout << "[INFO] Calculando Stdev(" << arrayName << ")" << endl;
        }
        else if (funcName == "Median") {
            result = calculateMedian(values);
            cout << "[INFO] Calculando Median(" << arrayName << ") [aproximación]" << endl;
        }
        else if (funcName == "Mode") {
            result = calculateMode(values);
            cout << "[INFO] Calculando Mode(" << arrayName << ") [aproximación]" << endl;
        }
        else if (funcName == "Range") {
            Value *minVal = calculateMin(values);
            Value *maxVal = calculateMax(values);
            result = irBuilder->CreateFSub(maxVal, minVal, "range");
            cout << "[INFO] Calculando Range(" << arrayName << ")" << endl;
        }
        else if (funcName == "CoeffVar") {
            result = calculateCoeffVar(values);
            cout << "[INFO] Calculando CoeffVar(" << arrayName << ")" << endl;
        }
        else if (funcName == "Skewness") {
            result = calculateSkewness(values);
            cout << "[INFO] Calculando Skewness(" << arrayName << ")" << endl;
        }
        else if (funcName == "IQR") {
            result = calculateIQR(values);
            cout << "[INFO] Calculando IQR(" << arrayName << ")" << endl;
        }
        else if (funcName == "Kurtosis") {
            result = calculateKurtosis(values);
            cout << "[INFO] Calculando Kurtosis(" << arrayName << ")" << endl;
        }
        else {
            cerr << "[ERROR] Función '" << funcName << "' no implementada aún" << endl;
            return nullptr;
        }
        return (Value*)result;
    }

    // ============================================
    // VISITOR: Tablas de frecuencia
    // ============================================
    virtual std::any visitExprTableFunc(StatCompParser::ExprTableFuncContext *ctx) override {
        string funcName = ctx->tableFunc()->getText();
        if (!ctx->arglist() || ctx->arglist()->expr().empty()) {
            cerr << "[ERROR] Función '" << funcName << "' requiere argumentos" << endl;
            return nullptr;
        }
        auto firstExpr = ctx->arglist()->expr(0);
        string arrayName = firstExpr->getText();
        if (namedArrays.find(arrayName) == namedArrays.end()) {
            cerr << "[ERROR] '" << arrayName << "' no es un array definido" << endl;
            return nullptr;
        }
        if (funcName == "Freq" || funcName == "AbsFreq") {
            printFrequencyTable(arrayName, funcName);
        }
        else if (funcName == "RelFreq") {
            printFrequencyTable(arrayName, funcName);
        }
        else if (funcName == "BarChart") {
            printBarChart(arrayName);
        }
        else if (funcName == "AbsFreqCum" || funcName == "RelFreqCum") {
            cerr << "[WARN] " << funcName << " no implementada aún" << endl;
        }
        else {
            cerr << "[ERROR] Función de tabla '" << funcName << "' no implementada" << endl;
        }
        // Retornar un valor constante para que sea una expresión válida
        return (Value*)ConstantFP::get(*context, APFloat(0.0));
    }

    // ============================================
    // FUNCIONES NO IMPLEMENTADAS
    // ============================================
    virtual std::any visitExprString(StatCompParser::ExprStringContext *ctx) override {
        string text = ctx->getText();
        // Remover comillas del inicio y final
        if (text.length() >= 2 && text.front() == '"' && text.back() == '"') {
            text = text.substr(1, text.length() - 2);
        }
        
        // Procesar secuencias de escape
        string processed;
        for (size_t i = 0; i < text.length(); ++i) {
            if (text[i] == '\\' && i + 1 < text.length()) {
                switch (text[i + 1]) {
                    case 'n': processed += '\n'; i++; break;
                    case 't': processed += '\t'; i++; break;
                    case 'r': processed += '\r'; i++; break;
                    case '\\': processed += '\\'; i++; break;
                    case '"': processed += '"'; i++; break;
                    default: processed += text[i]; break;
                }
            } else {
                processed += text[i];
            }
        }
        
        // Crear string constante global
        Constant *strConstant = ConstantDataArray::getString(*context, processed, true);
        GlobalVariable *strGlobal = new GlobalVariable(
            *module, 
            strConstant->getType(), 
            true, 
            GlobalValue::PrivateLinkage, 
            strConstant, 
            ".str"
        );
        
        // Retornar puntero al string
        Type *Int32Ty = Type::getInt32Ty(*context);
        Value *zero = ConstantInt::get(Int32Ty, 0);
        return (Value*)irBuilder->CreateInBoundsGEP(
            strConstant->getType(), 
            strGlobal, 
            {zero, zero}
        );
    }
    virtual std::any visitStatFunc(StatCompParser::StatFuncContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitTableFunc(StatCompParser::TableFuncContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitArglist(StatCompParser::ArglistContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitArrayInit(StatCompParser::ArrayInitContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitNumlist(StatCompParser::NumlistContext *ctx) override { return visitChildren(ctx); }
    virtual std::any visitDecltype(StatCompParser::DecltypeContext *ctx) override { return visitChildren(ctx); }

    // ============================================
    // EJECUTAR CÓDIGO GENERADO CON JIT
    // ============================================
    void executeCode() {
        InitializeNativeTarget();
        InitializeNativeTargetAsmPrinter();
        InitializeNativeTargetAsmParser();

        std::unique_ptr<Module> clonedModule = CloneModule(*module);

        string errorStr;
        EngineBuilder builder(std::move(clonedModule));
        builder.setErrorStr(&errorStr);
        builder.setEngineKind(EngineKind::JIT);
        
        ExecutionEngine *executionEngine = builder.create();
        
        if (!executionEngine) {
            cerr << "[ERROR] No se pudo crear ExecutionEngine: " << errorStr << endl;
            return;
        }

        executionEngine->finalizeObject();

        Function *mainFunc = executionEngine->FindFunctionNamed("main");
        
        if (!mainFunc) {
            cerr << "[ERROR] No se encontró la función main" << endl;
            delete executionEngine;
            return;
        }

        vector<GenericValue> noargs;
        executionEngine->runFunction(mainFunc, noargs);

        delete executionEngine;
    }
};

#endif // DRIVER_H