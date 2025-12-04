
// Generated from /home/mayta/Desktop/CompilersTheory/StatComP/StatComp.g4 by ANTLR 4.13.2


#include "StatCompVisitor.h"

#include "StatCompParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct StatCompParserStaticData final {
  StatCompParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  StatCompParserStaticData(const StatCompParserStaticData&) = delete;
  StatCompParserStaticData(StatCompParserStaticData&&) = delete;
  StatCompParserStaticData& operator=(const StatCompParserStaticData&) = delete;
  StatCompParserStaticData& operator=(StatCompParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag statcompParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<StatCompParserStaticData> statcompParserStaticData = nullptr;

void statcompParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (statcompParserStaticData != nullptr) {
    return;
  }
#else
  assert(statcompParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<StatCompParserStaticData>(
    std::vector<std::string>{
      "prog", "stmt", "expr", "statFunc", "tableFunc", "arrayInit", "numlist", 
      "row", "num", "decltype", "pos"
    },
    std::vector<std::string>{
      "", "';'", "'Mean'", "'Median'", "'Mode'", "'Stdev'", "'Var'", "'Square_root'", 
      "'Freq'", "'AbsFreq'", "'RelFreq'", "'AbsFreqCum'", "'RelFreqCum'", 
      "'^'", "'+'", "'-'", "'*'", "'/'", "'//'", "'%'", "'='", "'('", "')'", 
      "':'", "'{'", "'}'", "'['", "']'", "','", "'int'", "'float'", "'array'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "POW", "ADD", 
      "SUB", "MUL", "DIV", "INTDIV", "MOD", "ASSIGN", "LPAR", "RPAR", "COLON", 
      "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA", "TINT", "TFLOAT", 
      "ARRAY", "ID", "INT", "FLOAT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,35,124,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,5,0,24,8,0,10,0,12,0,27,9,0,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,45,8,1,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,71,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,5,2,82,8,2,10,2,12,2,85,9,2,1,3,1,3,1,4,1,4,1,5,1,5,3,5,93,8,5,1,
  	5,1,5,1,6,1,6,1,6,5,6,100,8,6,10,6,12,6,103,9,6,1,7,1,7,1,7,1,7,5,7,109,
  	8,7,10,7,12,7,112,9,7,3,7,114,8,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,
  	10,0,1,4,11,0,2,4,6,8,10,12,14,16,18,20,0,6,1,0,16,19,1,0,14,15,1,0,2,
  	7,1,0,8,12,1,0,33,34,1,0,29,30,128,0,25,1,0,0,0,2,44,1,0,0,0,4,70,1,0,
  	0,0,6,86,1,0,0,0,8,88,1,0,0,0,10,90,1,0,0,0,12,96,1,0,0,0,14,104,1,0,
  	0,0,16,117,1,0,0,0,18,119,1,0,0,0,20,121,1,0,0,0,22,24,3,2,1,0,23,22,
  	1,0,0,0,24,27,1,0,0,0,25,23,1,0,0,0,25,26,1,0,0,0,26,1,1,0,0,0,27,25,
  	1,0,0,0,28,29,3,4,2,0,29,30,5,1,0,0,30,45,1,0,0,0,31,32,3,18,9,0,32,33,
  	5,32,0,0,33,34,5,20,0,0,34,35,3,4,2,0,35,36,5,1,0,0,36,45,1,0,0,0,37,
  	38,5,31,0,0,38,39,3,18,9,0,39,40,5,32,0,0,40,41,5,20,0,0,41,42,3,10,5,
  	0,42,43,5,1,0,0,43,45,1,0,0,0,44,28,1,0,0,0,44,31,1,0,0,0,44,37,1,0,0,
  	0,45,3,1,0,0,0,46,47,6,2,-1,0,47,48,5,15,0,0,48,71,3,4,2,10,49,50,5,21,
  	0,0,50,51,3,4,2,0,51,52,5,22,0,0,52,71,1,0,0,0,53,71,3,16,8,0,54,71,5,
  	32,0,0,55,56,5,32,0,0,56,57,5,26,0,0,57,58,3,20,10,0,58,59,5,27,0,0,59,
  	71,1,0,0,0,60,61,3,6,3,0,61,62,5,21,0,0,62,63,3,4,2,0,63,64,5,22,0,0,
  	64,71,1,0,0,0,65,66,3,8,4,0,66,67,5,21,0,0,67,68,3,4,2,0,68,69,5,22,0,
  	0,69,71,1,0,0,0,70,46,1,0,0,0,70,49,1,0,0,0,70,53,1,0,0,0,70,54,1,0,0,
  	0,70,55,1,0,0,0,70,60,1,0,0,0,70,65,1,0,0,0,71,83,1,0,0,0,72,73,10,9,
  	0,0,73,74,5,13,0,0,74,82,3,4,2,10,75,76,10,8,0,0,76,77,7,0,0,0,77,82,
  	3,4,2,9,78,79,10,7,0,0,79,80,7,1,0,0,80,82,3,4,2,8,81,72,1,0,0,0,81,75,
  	1,0,0,0,81,78,1,0,0,0,82,85,1,0,0,0,83,81,1,0,0,0,83,84,1,0,0,0,84,5,
  	1,0,0,0,85,83,1,0,0,0,86,87,7,2,0,0,87,7,1,0,0,0,88,89,7,3,0,0,89,9,1,
  	0,0,0,90,92,5,24,0,0,91,93,3,12,6,0,92,91,1,0,0,0,92,93,1,0,0,0,93,94,
  	1,0,0,0,94,95,5,25,0,0,95,11,1,0,0,0,96,101,3,16,8,0,97,98,5,28,0,0,98,
  	100,3,16,8,0,99,97,1,0,0,0,100,103,1,0,0,0,101,99,1,0,0,0,101,102,1,0,
  	0,0,102,13,1,0,0,0,103,101,1,0,0,0,104,113,5,24,0,0,105,110,3,16,8,0,
  	106,107,5,28,0,0,107,109,3,16,8,0,108,106,1,0,0,0,109,112,1,0,0,0,110,
  	108,1,0,0,0,110,111,1,0,0,0,111,114,1,0,0,0,112,110,1,0,0,0,113,105,1,
  	0,0,0,113,114,1,0,0,0,114,115,1,0,0,0,115,116,5,25,0,0,116,15,1,0,0,0,
  	117,118,7,4,0,0,118,17,1,0,0,0,119,120,7,5,0,0,120,19,1,0,0,0,121,122,
  	5,33,0,0,122,21,1,0,0,0,9,25,44,70,81,83,92,101,110,113
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  statcompParserStaticData = std::move(staticData);
}

}

StatCompParser::StatCompParser(TokenStream *input) : StatCompParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

StatCompParser::StatCompParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  StatCompParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *statcompParserStaticData->atn, statcompParserStaticData->decisionToDFA, statcompParserStaticData->sharedContextCache, options);
}

StatCompParser::~StatCompParser() {
  delete _interpreter;
}

const atn::ATN& StatCompParser::getATN() const {
  return *statcompParserStaticData->atn;
}

std::string StatCompParser::getGrammarFileName() const {
  return "StatComp.g4";
}

const std::vector<std::string>& StatCompParser::getRuleNames() const {
  return statcompParserStaticData->ruleNames;
}

const dfa::Vocabulary& StatCompParser::getVocabulary() const {
  return statcompParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView StatCompParser::getSerializedATN() const {
  return statcompParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

StatCompParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StatCompParser::StmtContext *> StatCompParser::ProgContext::stmt() {
  return getRuleContexts<StatCompParser::StmtContext>();
}

StatCompParser::StmtContext* StatCompParser::ProgContext::stmt(size_t i) {
  return getRuleContext<StatCompParser::StmtContext>(i);
}


size_t StatCompParser::ProgContext::getRuleIndex() const {
  return StatCompParser::RuleProg;
}


std::any StatCompParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::ProgContext* StatCompParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, StatCompParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 33825005564) != 0)) {
      setState(22);
      stmt();
      setState(27);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

StatCompParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StatCompParser::StmtContext::getRuleIndex() const {
  return StatCompParser::RuleStmt;
}

void StatCompParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UpdateSymbolContext ------------------------------------------------------------------

StatCompParser::DecltypeContext* StatCompParser::UpdateSymbolContext::decltype_() {
  return getRuleContext<StatCompParser::DecltypeContext>(0);
}

tree::TerminalNode* StatCompParser::UpdateSymbolContext::ID() {
  return getToken(StatCompParser::ID, 0);
}

tree::TerminalNode* StatCompParser::UpdateSymbolContext::ASSIGN() {
  return getToken(StatCompParser::ASSIGN, 0);
}

StatCompParser::ExprContext* StatCompParser::UpdateSymbolContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

StatCompParser::UpdateSymbolContext::UpdateSymbolContext(StmtContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::UpdateSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitUpdateSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayDeclContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ArrayDeclContext::ARRAY() {
  return getToken(StatCompParser::ARRAY, 0);
}

StatCompParser::DecltypeContext* StatCompParser::ArrayDeclContext::decltype_() {
  return getRuleContext<StatCompParser::DecltypeContext>(0);
}

tree::TerminalNode* StatCompParser::ArrayDeclContext::ID() {
  return getToken(StatCompParser::ID, 0);
}

tree::TerminalNode* StatCompParser::ArrayDeclContext::ASSIGN() {
  return getToken(StatCompParser::ASSIGN, 0);
}

StatCompParser::ArrayInitContext* StatCompParser::ArrayDeclContext::arrayInit() {
  return getRuleContext<StatCompParser::ArrayInitContext>(0);
}

StatCompParser::ArrayDeclContext::ArrayDeclContext(StmtContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ArrayDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitArrayDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

StatCompParser::ExprContext* StatCompParser::PrintExprContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

StatCompParser::PrintExprContext::PrintExprContext(StmtContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
StatCompParser::StmtContext* StatCompParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 2, StatCompParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StatCompParser::T__1:
      case StatCompParser::T__2:
      case StatCompParser::T__3:
      case StatCompParser::T__4:
      case StatCompParser::T__5:
      case StatCompParser::T__6:
      case StatCompParser::T__7:
      case StatCompParser::T__8:
      case StatCompParser::T__9:
      case StatCompParser::T__10:
      case StatCompParser::T__11:
      case StatCompParser::SUB:
      case StatCompParser::LPAR:
      case StatCompParser::ID:
      case StatCompParser::INT:
      case StatCompParser::FLOAT: {
        _localctx = _tracker.createInstance<StatCompParser::PrintExprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(28);
        expr(0);
        setState(29);
        match(StatCompParser::T__0);
        break;
      }

      case StatCompParser::TINT:
      case StatCompParser::TFLOAT: {
        _localctx = _tracker.createInstance<StatCompParser::UpdateSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(31);
        decltype_();
        setState(32);
        match(StatCompParser::ID);
        setState(33);
        match(StatCompParser::ASSIGN);
        setState(34);
        expr(0);
        setState(35);
        match(StatCompParser::T__0);
        break;
      }

      case StatCompParser::ARRAY: {
        _localctx = _tracker.createInstance<StatCompParser::ArrayDeclContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(37);
        match(StatCompParser::ARRAY);
        setState(38);
        decltype_();
        setState(39);
        match(StatCompParser::ID);
        setState(40);
        match(StatCompParser::ASSIGN);
        setState(41);
        arrayInit();
        setState(42);
        match(StatCompParser::T__0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

StatCompParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StatCompParser::ExprContext::getRuleIndex() const {
  return StatCompParser::RuleExpr;
}

void StatCompParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprNegContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprNegContext::SUB() {
  return getToken(StatCompParser::SUB, 0);
}

StatCompParser::ExprContext* StatCompParser::ExprNegContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

StatCompParser::ExprNegContext::ExprNegContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprNegContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprNeg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprTableFuncContext ------------------------------------------------------------------

StatCompParser::TableFuncContext* StatCompParser::ExprTableFuncContext::tableFunc() {
  return getRuleContext<StatCompParser::TableFuncContext>(0);
}

tree::TerminalNode* StatCompParser::ExprTableFuncContext::LPAR() {
  return getToken(StatCompParser::LPAR, 0);
}

StatCompParser::ExprContext* StatCompParser::ExprTableFuncContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

tree::TerminalNode* StatCompParser::ExprTableFuncContext::RPAR() {
  return getToken(StatCompParser::RPAR, 0);
}

StatCompParser::ExprTableFuncContext::ExprTableFuncContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprTableFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprTableFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprParContext::LPAR() {
  return getToken(StatCompParser::LPAR, 0);
}

StatCompParser::ExprContext* StatCompParser::ExprParContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

tree::TerminalNode* StatCompParser::ExprParContext::RPAR() {
  return getToken(StatCompParser::RPAR, 0);
}

StatCompParser::ExprParContext::ExprParContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddSubContext ------------------------------------------------------------------

std::vector<StatCompParser::ExprContext *> StatCompParser::ExprAddSubContext::expr() {
  return getRuleContexts<StatCompParser::ExprContext>();
}

StatCompParser::ExprContext* StatCompParser::ExprAddSubContext::expr(size_t i) {
  return getRuleContext<StatCompParser::ExprContext>(i);
}

tree::TerminalNode* StatCompParser::ExprAddSubContext::ADD() {
  return getToken(StatCompParser::ADD, 0);
}

tree::TerminalNode* StatCompParser::ExprAddSubContext::SUB() {
  return getToken(StatCompParser::SUB, 0);
}

StatCompParser::ExprAddSubContext::ExprAddSubContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVarContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprVarContext::ID() {
  return getToken(StatCompParser::ID, 0);
}

StatCompParser::ExprVarContext::ExprVarContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprPowContext ------------------------------------------------------------------

std::vector<StatCompParser::ExprContext *> StatCompParser::ExprPowContext::expr() {
  return getRuleContexts<StatCompParser::ExprContext>();
}

StatCompParser::ExprContext* StatCompParser::ExprPowContext::expr(size_t i) {
  return getRuleContext<StatCompParser::ExprContext>(i);
}

tree::TerminalNode* StatCompParser::ExprPowContext::POW() {
  return getToken(StatCompParser::POW, 0);
}

StatCompParser::ExprPowContext::ExprPowContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprPowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprPow(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLiteralContext ------------------------------------------------------------------

StatCompParser::NumContext* StatCompParser::ExprLiteralContext::num() {
  return getRuleContext<StatCompParser::NumContext>(0);
}

StatCompParser::ExprLiteralContext::ExprLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprArrayAccessContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprArrayAccessContext::ID() {
  return getToken(StatCompParser::ID, 0);
}

tree::TerminalNode* StatCompParser::ExprArrayAccessContext::LBRACK() {
  return getToken(StatCompParser::LBRACK, 0);
}

StatCompParser::PosContext* StatCompParser::ExprArrayAccessContext::pos() {
  return getRuleContext<StatCompParser::PosContext>(0);
}

tree::TerminalNode* StatCompParser::ExprArrayAccessContext::RBRACK() {
  return getToken(StatCompParser::RBRACK, 0);
}

StatCompParser::ExprArrayAccessContext::ExprArrayAccessContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprArrayAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprArrayAccess(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMulDivContext ------------------------------------------------------------------

std::vector<StatCompParser::ExprContext *> StatCompParser::ExprMulDivContext::expr() {
  return getRuleContexts<StatCompParser::ExprContext>();
}

StatCompParser::ExprContext* StatCompParser::ExprMulDivContext::expr(size_t i) {
  return getRuleContext<StatCompParser::ExprContext>(i);
}

tree::TerminalNode* StatCompParser::ExprMulDivContext::MUL() {
  return getToken(StatCompParser::MUL, 0);
}

tree::TerminalNode* StatCompParser::ExprMulDivContext::DIV() {
  return getToken(StatCompParser::DIV, 0);
}

tree::TerminalNode* StatCompParser::ExprMulDivContext::INTDIV() {
  return getToken(StatCompParser::INTDIV, 0);
}

tree::TerminalNode* StatCompParser::ExprMulDivContext::MOD() {
  return getToken(StatCompParser::MOD, 0);
}

StatCompParser::ExprMulDivContext::ExprMulDivContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprMulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprMulDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStatFuncContext ------------------------------------------------------------------

StatCompParser::StatFuncContext* StatCompParser::ExprStatFuncContext::statFunc() {
  return getRuleContext<StatCompParser::StatFuncContext>(0);
}

tree::TerminalNode* StatCompParser::ExprStatFuncContext::LPAR() {
  return getToken(StatCompParser::LPAR, 0);
}

StatCompParser::ExprContext* StatCompParser::ExprStatFuncContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

tree::TerminalNode* StatCompParser::ExprStatFuncContext::RPAR() {
  return getToken(StatCompParser::RPAR, 0);
}

StatCompParser::ExprStatFuncContext::ExprStatFuncContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprStatFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprStatFunc(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::ExprContext* StatCompParser::expr() {
   return expr(0);
}

StatCompParser::ExprContext* StatCompParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  StatCompParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  StatCompParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, StatCompParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(70);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprNegContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(47);
      match(StatCompParser::SUB);
      setState(48);
      expr(10);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprParContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(49);
      match(StatCompParser::LPAR);
      setState(50);
      expr(0);
      setState(51);
      match(StatCompParser::RPAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(53);
      num();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(54);
      match(StatCompParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprArrayAccessContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(55);
      match(StatCompParser::ID);
      setState(56);
      match(StatCompParser::LBRACK);
      setState(57);
      pos();
      setState(58);
      match(StatCompParser::RBRACK);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprStatFuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(60);
      statFunc();
      setState(61);
      match(StatCompParser::LPAR);
      setState(62);
      expr(0);
      setState(63);
      match(StatCompParser::RPAR);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprTableFuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(65);
      tableFunc();
      setState(66);
      match(StatCompParser::LPAR);
      setState(67);
      expr(0);
      setState(68);
      match(StatCompParser::RPAR);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(83);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(81);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprPowContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(72);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(73);
          match(StatCompParser::POW);
          setState(74);
          expr(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprMulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(75);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(76);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 983040) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(77);
          expr(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(78);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(79);
          _la = _input->LA(1);
          if (!(_la == StatCompParser::ADD

          || _la == StatCompParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(80);
          expr(8);
          break;
        }

        default:
          break;
        } 
      }
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatFuncContext ------------------------------------------------------------------

StatCompParser::StatFuncContext::StatFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StatCompParser::StatFuncContext::getRuleIndex() const {
  return StatCompParser::RuleStatFunc;
}


std::any StatCompParser::StatFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitStatFunc(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::StatFuncContext* StatCompParser::statFunc() {
  StatFuncContext *_localctx = _tracker.createInstance<StatFuncContext>(_ctx, getState());
  enterRule(_localctx, 6, StatCompParser::RuleStatFunc);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 252) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableFuncContext ------------------------------------------------------------------

StatCompParser::TableFuncContext::TableFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StatCompParser::TableFuncContext::getRuleIndex() const {
  return StatCompParser::RuleTableFunc;
}


std::any StatCompParser::TableFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitTableFunc(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::TableFuncContext* StatCompParser::tableFunc() {
  TableFuncContext *_localctx = _tracker.createInstance<TableFuncContext>(_ctx, getState());
  enterRule(_localctx, 8, StatCompParser::RuleTableFunc);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7936) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayInitContext ------------------------------------------------------------------

StatCompParser::ArrayInitContext::ArrayInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StatCompParser::ArrayInitContext::LBRACE() {
  return getToken(StatCompParser::LBRACE, 0);
}

tree::TerminalNode* StatCompParser::ArrayInitContext::RBRACE() {
  return getToken(StatCompParser::RBRACE, 0);
}

StatCompParser::NumlistContext* StatCompParser::ArrayInitContext::numlist() {
  return getRuleContext<StatCompParser::NumlistContext>(0);
}


size_t StatCompParser::ArrayInitContext::getRuleIndex() const {
  return StatCompParser::RuleArrayInit;
}


std::any StatCompParser::ArrayInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitArrayInit(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::ArrayInitContext* StatCompParser::arrayInit() {
  ArrayInitContext *_localctx = _tracker.createInstance<ArrayInitContext>(_ctx, getState());
  enterRule(_localctx, 10, StatCompParser::RuleArrayInit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(StatCompParser::LBRACE);
    setState(92);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StatCompParser::INT

    || _la == StatCompParser::FLOAT) {
      setState(91);
      numlist();
    }
    setState(94);
    match(StatCompParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumlistContext ------------------------------------------------------------------

StatCompParser::NumlistContext::NumlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StatCompParser::NumContext *> StatCompParser::NumlistContext::num() {
  return getRuleContexts<StatCompParser::NumContext>();
}

StatCompParser::NumContext* StatCompParser::NumlistContext::num(size_t i) {
  return getRuleContext<StatCompParser::NumContext>(i);
}

std::vector<tree::TerminalNode *> StatCompParser::NumlistContext::COMMA() {
  return getTokens(StatCompParser::COMMA);
}

tree::TerminalNode* StatCompParser::NumlistContext::COMMA(size_t i) {
  return getToken(StatCompParser::COMMA, i);
}


size_t StatCompParser::NumlistContext::getRuleIndex() const {
  return StatCompParser::RuleNumlist;
}


std::any StatCompParser::NumlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitNumlist(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::NumlistContext* StatCompParser::numlist() {
  NumlistContext *_localctx = _tracker.createInstance<NumlistContext>(_ctx, getState());
  enterRule(_localctx, 12, StatCompParser::RuleNumlist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    num();
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StatCompParser::COMMA) {
      setState(97);
      match(StatCompParser::COMMA);
      setState(98);
      num();
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RowContext ------------------------------------------------------------------

StatCompParser::RowContext::RowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StatCompParser::RowContext::LBRACE() {
  return getToken(StatCompParser::LBRACE, 0);
}

tree::TerminalNode* StatCompParser::RowContext::RBRACE() {
  return getToken(StatCompParser::RBRACE, 0);
}

std::vector<StatCompParser::NumContext *> StatCompParser::RowContext::num() {
  return getRuleContexts<StatCompParser::NumContext>();
}

StatCompParser::NumContext* StatCompParser::RowContext::num(size_t i) {
  return getRuleContext<StatCompParser::NumContext>(i);
}

std::vector<tree::TerminalNode *> StatCompParser::RowContext::COMMA() {
  return getTokens(StatCompParser::COMMA);
}

tree::TerminalNode* StatCompParser::RowContext::COMMA(size_t i) {
  return getToken(StatCompParser::COMMA, i);
}


size_t StatCompParser::RowContext::getRuleIndex() const {
  return StatCompParser::RuleRow;
}


std::any StatCompParser::RowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitRow(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::RowContext* StatCompParser::row() {
  RowContext *_localctx = _tracker.createInstance<RowContext>(_ctx, getState());
  enterRule(_localctx, 14, StatCompParser::RuleRow);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(StatCompParser::LBRACE);
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StatCompParser::INT

    || _la == StatCompParser::FLOAT) {
      setState(105);
      num();
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == StatCompParser::COMMA) {
        setState(106);
        match(StatCompParser::COMMA);
        setState(107);
        num();
        setState(112);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(115);
    match(StatCompParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumContext ------------------------------------------------------------------

StatCompParser::NumContext::NumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StatCompParser::NumContext::INT() {
  return getToken(StatCompParser::INT, 0);
}

tree::TerminalNode* StatCompParser::NumContext::FLOAT() {
  return getToken(StatCompParser::FLOAT, 0);
}


size_t StatCompParser::NumContext::getRuleIndex() const {
  return StatCompParser::RuleNum;
}


std::any StatCompParser::NumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitNum(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::NumContext* StatCompParser::num() {
  NumContext *_localctx = _tracker.createInstance<NumContext>(_ctx, getState());
  enterRule(_localctx, 16, StatCompParser::RuleNum);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    _la = _input->LA(1);
    if (!(_la == StatCompParser::INT

    || _la == StatCompParser::FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecltypeContext ------------------------------------------------------------------

StatCompParser::DecltypeContext::DecltypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StatCompParser::DecltypeContext::TINT() {
  return getToken(StatCompParser::TINT, 0);
}

tree::TerminalNode* StatCompParser::DecltypeContext::TFLOAT() {
  return getToken(StatCompParser::TFLOAT, 0);
}


size_t StatCompParser::DecltypeContext::getRuleIndex() const {
  return StatCompParser::RuleDecltype;
}


std::any StatCompParser::DecltypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitDecltype(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::DecltypeContext* StatCompParser::decltype_() {
  DecltypeContext *_localctx = _tracker.createInstance<DecltypeContext>(_ctx, getState());
  enterRule(_localctx, 18, StatCompParser::RuleDecltype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    _la = _input->LA(1);
    if (!(_la == StatCompParser::TINT

    || _la == StatCompParser::TFLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PosContext ------------------------------------------------------------------

StatCompParser::PosContext::PosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StatCompParser::PosContext::INT() {
  return getToken(StatCompParser::INT, 0);
}


size_t StatCompParser::PosContext::getRuleIndex() const {
  return StatCompParser::RulePos;
}


std::any StatCompParser::PosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitPos(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::PosContext* StatCompParser::pos() {
  PosContext *_localctx = _tracker.createInstance<PosContext>(_ctx, getState());
  enterRule(_localctx, 20, StatCompParser::RulePos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(StatCompParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool StatCompParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool StatCompParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

void StatCompParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  statcompParserInitialize();
#else
  ::antlr4::internal::call_once(statcompParserOnceFlag, statcompParserInitialize);
#endif
}
