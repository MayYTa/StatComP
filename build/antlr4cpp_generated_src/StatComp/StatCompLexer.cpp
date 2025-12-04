
// Generated from /home/mayta/Desktop/CompilersTheory/StatComP/StatComp.g4 by ANTLR 4.13.2


#include "StatCompLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct StatCompLexerStaticData final {
  StatCompLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  StatCompLexerStaticData(const StatCompLexerStaticData&) = delete;
  StatCompLexerStaticData(StatCompLexerStaticData&&) = delete;
  StatCompLexerStaticData& operator=(const StatCompLexerStaticData&) = delete;
  StatCompLexerStaticData& operator=(StatCompLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag statcomplexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<StatCompLexerStaticData> statcomplexerLexerStaticData = nullptr;

void statcomplexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (statcomplexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(statcomplexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<StatCompLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "POW", "ADD", "SUB", "MUL", "DIV", "INTDIV", 
      "MOD", "ASSIGN", "LPAR", "RPAR", "COLON", "LBRACE", "RBRACE", "LBRACK", 
      "RBRACK", "COMMA", "TINT", "TFLOAT", "ARRAY", "ID", "INT", "FLOAT", 
      "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,35,234,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,
  	1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,
  	3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,17,
  	1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,
  	1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,31,1,31,5,31,207,8,31,10,31,
  	12,31,210,9,31,1,32,4,32,213,8,32,11,32,12,32,214,1,33,4,33,218,8,33,
  	11,33,12,33,219,1,33,1,33,4,33,224,8,33,11,33,12,33,225,1,34,4,34,229,
  	8,34,11,34,12,34,230,1,34,1,34,0,0,35,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,
  	8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,
  	20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,
  	63,32,65,33,67,34,69,35,1,0,4,3,0,65,90,95,95,97,122,4,0,48,57,65,90,
  	95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,238,0,1,1,0,0,0,0,3,1,0,0,
  	0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,
  	0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,
  	0,69,1,0,0,0,1,71,1,0,0,0,3,73,1,0,0,0,5,78,1,0,0,0,7,85,1,0,0,0,9,90,
  	1,0,0,0,11,96,1,0,0,0,13,100,1,0,0,0,15,112,1,0,0,0,17,117,1,0,0,0,19,
  	125,1,0,0,0,21,133,1,0,0,0,23,144,1,0,0,0,25,155,1,0,0,0,27,157,1,0,0,
  	0,29,159,1,0,0,0,31,161,1,0,0,0,33,163,1,0,0,0,35,165,1,0,0,0,37,168,
  	1,0,0,0,39,170,1,0,0,0,41,172,1,0,0,0,43,174,1,0,0,0,45,176,1,0,0,0,47,
  	178,1,0,0,0,49,180,1,0,0,0,51,182,1,0,0,0,53,184,1,0,0,0,55,186,1,0,0,
  	0,57,188,1,0,0,0,59,192,1,0,0,0,61,198,1,0,0,0,63,204,1,0,0,0,65,212,
  	1,0,0,0,67,217,1,0,0,0,69,228,1,0,0,0,71,72,5,59,0,0,72,2,1,0,0,0,73,
  	74,5,77,0,0,74,75,5,101,0,0,75,76,5,97,0,0,76,77,5,110,0,0,77,4,1,0,0,
  	0,78,79,5,77,0,0,79,80,5,101,0,0,80,81,5,100,0,0,81,82,5,105,0,0,82,83,
  	5,97,0,0,83,84,5,110,0,0,84,6,1,0,0,0,85,86,5,77,0,0,86,87,5,111,0,0,
  	87,88,5,100,0,0,88,89,5,101,0,0,89,8,1,0,0,0,90,91,5,83,0,0,91,92,5,116,
  	0,0,92,93,5,100,0,0,93,94,5,101,0,0,94,95,5,118,0,0,95,10,1,0,0,0,96,
  	97,5,86,0,0,97,98,5,97,0,0,98,99,5,114,0,0,99,12,1,0,0,0,100,101,5,83,
  	0,0,101,102,5,113,0,0,102,103,5,117,0,0,103,104,5,97,0,0,104,105,5,114,
  	0,0,105,106,5,101,0,0,106,107,5,95,0,0,107,108,5,114,0,0,108,109,5,111,
  	0,0,109,110,5,111,0,0,110,111,5,116,0,0,111,14,1,0,0,0,112,113,5,70,0,
  	0,113,114,5,114,0,0,114,115,5,101,0,0,115,116,5,113,0,0,116,16,1,0,0,
  	0,117,118,5,65,0,0,118,119,5,98,0,0,119,120,5,115,0,0,120,121,5,70,0,
  	0,121,122,5,114,0,0,122,123,5,101,0,0,123,124,5,113,0,0,124,18,1,0,0,
  	0,125,126,5,82,0,0,126,127,5,101,0,0,127,128,5,108,0,0,128,129,5,70,0,
  	0,129,130,5,114,0,0,130,131,5,101,0,0,131,132,5,113,0,0,132,20,1,0,0,
  	0,133,134,5,65,0,0,134,135,5,98,0,0,135,136,5,115,0,0,136,137,5,70,0,
  	0,137,138,5,114,0,0,138,139,5,101,0,0,139,140,5,113,0,0,140,141,5,67,
  	0,0,141,142,5,117,0,0,142,143,5,109,0,0,143,22,1,0,0,0,144,145,5,82,0,
  	0,145,146,5,101,0,0,146,147,5,108,0,0,147,148,5,70,0,0,148,149,5,114,
  	0,0,149,150,5,101,0,0,150,151,5,113,0,0,151,152,5,67,0,0,152,153,5,117,
  	0,0,153,154,5,109,0,0,154,24,1,0,0,0,155,156,5,94,0,0,156,26,1,0,0,0,
  	157,158,5,43,0,0,158,28,1,0,0,0,159,160,5,45,0,0,160,30,1,0,0,0,161,162,
  	5,42,0,0,162,32,1,0,0,0,163,164,5,47,0,0,164,34,1,0,0,0,165,166,5,47,
  	0,0,166,167,5,47,0,0,167,36,1,0,0,0,168,169,5,37,0,0,169,38,1,0,0,0,170,
  	171,5,61,0,0,171,40,1,0,0,0,172,173,5,40,0,0,173,42,1,0,0,0,174,175,5,
  	41,0,0,175,44,1,0,0,0,176,177,5,58,0,0,177,46,1,0,0,0,178,179,5,123,0,
  	0,179,48,1,0,0,0,180,181,5,125,0,0,181,50,1,0,0,0,182,183,5,91,0,0,183,
  	52,1,0,0,0,184,185,5,93,0,0,185,54,1,0,0,0,186,187,5,44,0,0,187,56,1,
  	0,0,0,188,189,5,105,0,0,189,190,5,110,0,0,190,191,5,116,0,0,191,58,1,
  	0,0,0,192,193,5,102,0,0,193,194,5,108,0,0,194,195,5,111,0,0,195,196,5,
  	97,0,0,196,197,5,116,0,0,197,60,1,0,0,0,198,199,5,97,0,0,199,200,5,114,
  	0,0,200,201,5,114,0,0,201,202,5,97,0,0,202,203,5,121,0,0,203,62,1,0,0,
  	0,204,208,7,0,0,0,205,207,7,1,0,0,206,205,1,0,0,0,207,210,1,0,0,0,208,
  	206,1,0,0,0,208,209,1,0,0,0,209,64,1,0,0,0,210,208,1,0,0,0,211,213,7,
  	2,0,0,212,211,1,0,0,0,213,214,1,0,0,0,214,212,1,0,0,0,214,215,1,0,0,0,
  	215,66,1,0,0,0,216,218,7,2,0,0,217,216,1,0,0,0,218,219,1,0,0,0,219,217,
  	1,0,0,0,219,220,1,0,0,0,220,221,1,0,0,0,221,223,5,46,0,0,222,224,7,2,
  	0,0,223,222,1,0,0,0,224,225,1,0,0,0,225,223,1,0,0,0,225,226,1,0,0,0,226,
  	68,1,0,0,0,227,229,7,3,0,0,228,227,1,0,0,0,229,230,1,0,0,0,230,228,1,
  	0,0,0,230,231,1,0,0,0,231,232,1,0,0,0,232,233,6,34,0,0,233,70,1,0,0,0,
  	6,0,208,214,219,225,230,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  statcomplexerLexerStaticData = std::move(staticData);
}

}

StatCompLexer::StatCompLexer(CharStream *input) : Lexer(input) {
  StatCompLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *statcomplexerLexerStaticData->atn, statcomplexerLexerStaticData->decisionToDFA, statcomplexerLexerStaticData->sharedContextCache);
}

StatCompLexer::~StatCompLexer() {
  delete _interpreter;
}

std::string StatCompLexer::getGrammarFileName() const {
  return "StatComp.g4";
}

const std::vector<std::string>& StatCompLexer::getRuleNames() const {
  return statcomplexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& StatCompLexer::getChannelNames() const {
  return statcomplexerLexerStaticData->channelNames;
}

const std::vector<std::string>& StatCompLexer::getModeNames() const {
  return statcomplexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& StatCompLexer::getVocabulary() const {
  return statcomplexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView StatCompLexer::getSerializedATN() const {
  return statcomplexerLexerStaticData->serializedATN;
}

const atn::ATN& StatCompLexer::getATN() const {
  return *statcomplexerLexerStaticData->atn;
}




void StatCompLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  statcomplexerLexerInitialize();
#else
  ::antlr4::internal::call_once(statcomplexerLexerOnceFlag, statcomplexerLexerInitialize);
#endif
}
