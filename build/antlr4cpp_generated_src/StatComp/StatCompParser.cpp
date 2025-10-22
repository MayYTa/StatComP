
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
      "prog", "stmt", "expr", "arrayInit", "num", "decltype", "pos"
    },
    std::vector<std::string>{
      "", "';'", "'^'", "'+'", "'-'", "'*'", "'/'", "'//'", "'%'", "'='", 
      "'('", "')'", "':'", "'{'", "'}'", "'['", "']'", "','", "'int'", "'float'", 
      "'array'"
    },
    std::vector<std::string>{
      "", "", "POW", "ADD", "SUB", "MUL", "DIV", "INTDIV", "MOD", "ASSIGN", 
      "LPAR", "RPAR", "COLON", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA", 
      "TINT", "TFLOAT", "ARRAY", "ID", "INT", "FLOAT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,24,88,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	5,0,16,8,0,10,0,12,0,19,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,3,1,37,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,3,2,53,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,
  	2,64,8,2,10,2,12,2,67,9,2,1,3,1,3,1,3,1,3,5,3,73,8,3,10,3,12,3,76,9,3,
  	3,3,78,8,3,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,6,0,1,4,7,0,2,4,6,8,10,12,
  	0,4,1,0,5,8,1,0,3,4,1,0,22,23,1,0,18,19,92,0,17,1,0,0,0,2,36,1,0,0,0,
  	4,52,1,0,0,0,6,68,1,0,0,0,8,81,1,0,0,0,10,83,1,0,0,0,12,85,1,0,0,0,14,
  	16,3,2,1,0,15,14,1,0,0,0,16,19,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,
  	1,1,0,0,0,19,17,1,0,0,0,20,21,3,4,2,0,21,22,5,1,0,0,22,37,1,0,0,0,23,
  	24,3,10,5,0,24,25,5,21,0,0,25,26,5,9,0,0,26,27,3,4,2,0,27,28,5,1,0,0,
  	28,37,1,0,0,0,29,30,5,20,0,0,30,31,3,10,5,0,31,32,5,21,0,0,32,33,5,9,
  	0,0,33,34,3,6,3,0,34,35,5,1,0,0,35,37,1,0,0,0,36,20,1,0,0,0,36,23,1,0,
  	0,0,36,29,1,0,0,0,37,3,1,0,0,0,38,39,6,2,-1,0,39,40,5,4,0,0,40,53,3,4,
  	2,8,41,42,5,10,0,0,42,43,3,4,2,0,43,44,5,11,0,0,44,53,1,0,0,0,45,53,3,
  	8,4,0,46,53,5,21,0,0,47,48,5,21,0,0,48,49,5,15,0,0,49,50,3,12,6,0,50,
  	51,5,16,0,0,51,53,1,0,0,0,52,38,1,0,0,0,52,41,1,0,0,0,52,45,1,0,0,0,52,
  	46,1,0,0,0,52,47,1,0,0,0,53,65,1,0,0,0,54,55,10,7,0,0,55,56,5,2,0,0,56,
  	64,3,4,2,8,57,58,10,6,0,0,58,59,7,0,0,0,59,64,3,4,2,7,60,61,10,5,0,0,
  	61,62,7,1,0,0,62,64,3,4,2,6,63,54,1,0,0,0,63,57,1,0,0,0,63,60,1,0,0,0,
  	64,67,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,5,1,0,0,0,67,65,1,0,0,0,
  	68,77,5,13,0,0,69,74,3,8,4,0,70,71,5,17,0,0,71,73,3,8,4,0,72,70,1,0,0,
  	0,73,76,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,
  	0,77,69,1,0,0,0,77,78,1,0,0,0,78,79,1,0,0,0,79,80,5,14,0,0,80,7,1,0,0,
  	0,81,82,7,2,0,0,82,9,1,0,0,0,83,84,7,3,0,0,84,11,1,0,0,0,85,86,5,22,0,
  	0,86,13,1,0,0,0,7,17,36,52,63,65,74,77
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
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16516112) != 0)) {
      setState(14);
      stmt();
      setState(19);
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
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StatCompParser::SUB:
      case StatCompParser::LPAR:
      case StatCompParser::ID:
      case StatCompParser::INT:
      case StatCompParser::FLOAT: {
        _localctx = _tracker.createInstance<StatCompParser::PrintExprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(20);
        expr(0);
        setState(21);
        match(StatCompParser::T__0);
        break;
      }

      case StatCompParser::TINT:
      case StatCompParser::TFLOAT: {
        _localctx = _tracker.createInstance<StatCompParser::UpdateSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(23);
        decltype_();
        setState(24);
        match(StatCompParser::ID);
        setState(25);
        match(StatCompParser::ASSIGN);
        setState(26);
        expr(0);
        setState(27);
        match(StatCompParser::T__0);
        break;
      }

      case StatCompParser::ARRAY: {
        _localctx = _tracker.createInstance<StatCompParser::ArrayDeclContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(29);
        match(StatCompParser::ARRAY);
        setState(30);
        decltype_();
        setState(31);
        match(StatCompParser::ID);
        setState(32);
        match(StatCompParser::ASSIGN);
        setState(33);
        arrayInit();
        setState(34);
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
    setState(52);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprNegContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(39);
      match(StatCompParser::SUB);
      setState(40);
      expr(8);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprParContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(41);
      match(StatCompParser::LPAR);
      setState(42);
      expr(0);
      setState(43);
      match(StatCompParser::RPAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(45);
      num();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(46);
      match(StatCompParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprArrayAccessContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(47);
      match(StatCompParser::ID);
      setState(48);
      match(StatCompParser::LBRACK);
      setState(49);
      pos();
      setState(50);
      match(StatCompParser::RBRACK);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(65);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(63);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprPowContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(54);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(55);
          match(StatCompParser::POW);
          setState(56);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprMulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(57);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(58);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 480) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(59);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(60);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(61);
          _la = _input->LA(1);
          if (!(_la == StatCompParser::ADD

          || _la == StatCompParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(62);
          expr(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(67);
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

std::vector<StatCompParser::NumContext *> StatCompParser::ArrayInitContext::num() {
  return getRuleContexts<StatCompParser::NumContext>();
}

StatCompParser::NumContext* StatCompParser::ArrayInitContext::num(size_t i) {
  return getRuleContext<StatCompParser::NumContext>(i);
}

std::vector<tree::TerminalNode *> StatCompParser::ArrayInitContext::COMMA() {
  return getTokens(StatCompParser::COMMA);
}

tree::TerminalNode* StatCompParser::ArrayInitContext::COMMA(size_t i) {
  return getToken(StatCompParser::COMMA, i);
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
  enterRule(_localctx, 6, StatCompParser::RuleArrayInit);
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
    setState(68);
    match(StatCompParser::LBRACE);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StatCompParser::INT

    || _la == StatCompParser::FLOAT) {
      setState(69);
      num();
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == StatCompParser::COMMA) {
        setState(70);
        match(StatCompParser::COMMA);
        setState(71);
        num();
        setState(76);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(79);
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
  enterRule(_localctx, 8, StatCompParser::RuleNum);
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
    setState(81);
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
  enterRule(_localctx, 10, StatCompParser::RuleDecltype);
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
    setState(83);
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
  enterRule(_localctx, 12, StatCompParser::RulePos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
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
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);

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
