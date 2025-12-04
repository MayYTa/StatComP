
// Generated from /home/mayta/Desktop/CompilersTheory/StatComP/StatComp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  StatCompLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, POW = 13, ADD = 14, 
    SUB = 15, MUL = 16, DIV = 17, INTDIV = 18, MOD = 19, ASSIGN = 20, LPAR = 21, 
    RPAR = 22, COLON = 23, LBRACE = 24, RBRACE = 25, LBRACK = 26, RBRACK = 27, 
    COMMA = 28, TINT = 29, TFLOAT = 30, ARRAY = 31, ID = 32, INT = 33, FLOAT = 34, 
    WS = 35
  };

  explicit StatCompLexer(antlr4::CharStream *input);

  ~StatCompLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

