
// Generated from /home/mayta/Desktop/CompilersTheory/StatComP/StatComp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  StatCompParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, POW = 13, ADD = 14, 
    SUB = 15, MUL = 16, DIV = 17, INTDIV = 18, MOD = 19, ASSIGN = 20, LPAR = 21, 
    RPAR = 22, COLON = 23, LBRACE = 24, RBRACE = 25, LBRACK = 26, RBRACK = 27, 
    COMMA = 28, TINT = 29, TFLOAT = 30, ARRAY = 31, ID = 32, INT = 33, FLOAT = 34, 
    WS = 35
  };

  enum {
    RuleProg = 0, RuleStmt = 1, RuleExpr = 2, RuleStatFunc = 3, RuleTableFunc = 4, 
    RuleArrayInit = 5, RuleNumlist = 6, RuleRow = 7, RuleNum = 8, RuleDecltype = 9, 
    RulePos = 10
  };

  explicit StatCompParser(antlr4::TokenStream *input);

  StatCompParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~StatCompParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgContext;
  class StmtContext;
  class ExprContext;
  class StatFuncContext;
  class TableFuncContext;
  class ArrayInitContext;
  class NumlistContext;
  class RowContext;
  class NumContext;
  class DecltypeContext;
  class PosContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UpdateSymbolContext : public StmtContext {
  public:
    UpdateSymbolContext(StmtContext *ctx);

    DecltypeContext *decltype_();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayDeclContext : public StmtContext {
  public:
    ArrayDeclContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *ARRAY();
    DecltypeContext *decltype_();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ArrayInitContext *arrayInit();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrintExprContext : public StmtContext {
  public:
    PrintExprContext(StmtContext *ctx);

    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprNegContext : public ExprContext {
  public:
    ExprNegContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *SUB();
    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprTableFuncContext : public ExprContext {
  public:
    ExprTableFuncContext(ExprContext *ctx);

    TableFuncContext *tableFunc();
    antlr4::tree::TerminalNode *LPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprParContext : public ExprContext {
  public:
    ExprParContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *LPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprAddSubContext : public ExprContext {
  public:
    ExprAddSubContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprVarContext : public ExprContext {
  public:
    ExprVarContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprPowContext : public ExprContext {
  public:
    ExprPowContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *POW();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprLiteralContext : public ExprContext {
  public:
    ExprLiteralContext(ExprContext *ctx);

    NumContext *num();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprArrayAccessContext : public ExprContext {
  public:
    ExprArrayAccessContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LBRACK();
    PosContext *pos();
    antlr4::tree::TerminalNode *RBRACK();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprMulDivContext : public ExprContext {
  public:
    ExprMulDivContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *INTDIV();
    antlr4::tree::TerminalNode *MOD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprStatFuncContext : public ExprContext {
  public:
    ExprStatFuncContext(ExprContext *ctx);

    StatFuncContext *statFunc();
    antlr4::tree::TerminalNode *LPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  StatFuncContext : public antlr4::ParserRuleContext {
  public:
    StatFuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatFuncContext* statFunc();

  class  TableFuncContext : public antlr4::ParserRuleContext {
  public:
    TableFuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TableFuncContext* tableFunc();

  class  ArrayInitContext : public antlr4::ParserRuleContext {
  public:
    ArrayInitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    NumlistContext *numlist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayInitContext* arrayInit();

  class  NumlistContext : public antlr4::ParserRuleContext {
  public:
    NumlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NumContext *> num();
    NumContext* num(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumlistContext* numlist();

  class  RowContext : public antlr4::ParserRuleContext {
  public:
    RowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<NumContext *> num();
    NumContext* num(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RowContext* row();

  class  NumContext : public antlr4::ParserRuleContext {
  public:
    NumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumContext* num();

  class  DecltypeContext : public antlr4::ParserRuleContext {
  public:
    DecltypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TINT();
    antlr4::tree::TerminalNode *TFLOAT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DecltypeContext* decltype_();

  class  PosContext : public antlr4::ParserRuleContext {
  public:
    PosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PosContext* pos();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

