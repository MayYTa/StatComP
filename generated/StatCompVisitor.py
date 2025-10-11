# Generated from StatComp.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .StatCompParser import StatCompParser
else:
    from StatCompParser import StatCompParser

# This class defines a complete generic visitor for a parse tree produced by StatCompParser.

class StatCompVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by StatCompParser#prog.
    def visitProg(self, ctx:StatCompParser.ProgContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#printExpr.
    def visitPrintExpr(self, ctx:StatCompParser.PrintExprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#updateSymbol.
    def visitUpdateSymbol(self, ctx:StatCompParser.UpdateSymbolContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#arrayDecl.
    def visitArrayDecl(self, ctx:StatCompParser.ArrayDeclContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#exprNeg.
    def visitExprNeg(self, ctx:StatCompParser.ExprNegContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#exprPar.
    def visitExprPar(self, ctx:StatCompParser.ExprParContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#exprAddSub.
    def visitExprAddSub(self, ctx:StatCompParser.ExprAddSubContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#exprVar.
    def visitExprVar(self, ctx:StatCompParser.ExprVarContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#exprPow.
    def visitExprPow(self, ctx:StatCompParser.ExprPowContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#exprLiteral.
    def visitExprLiteral(self, ctx:StatCompParser.ExprLiteralContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#exprArrayAccess.
    def visitExprArrayAccess(self, ctx:StatCompParser.ExprArrayAccessContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#exprMulDiv.
    def visitExprMulDiv(self, ctx:StatCompParser.ExprMulDivContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#arrayInit.
    def visitArrayInit(self, ctx:StatCompParser.ArrayInitContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#num.
    def visitNum(self, ctx:StatCompParser.NumContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by StatCompParser#decltype.
    def visitDecltype(self, ctx:StatCompParser.DecltypeContext):
        return self.visitChildren(ctx)



del StatCompParser