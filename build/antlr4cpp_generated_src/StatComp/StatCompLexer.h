
// Generated from /home/mayta/Desktop/CompilersTheory/StatComP/StatComp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  StatCompLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, POW = 2, ADD = 3, SUB = 4, MUL = 5, DIV = 6, INTDIV = 7, MOD = 8, 
    ASSIGN = 9, LPAR = 10, RPAR = 11, COLON = 12, LBRACE = 13, RBRACE = 14, 
    LBRACK = 15, RBRACK = 16, COMMA = 17, TINT = 18, TFLOAT = 19, ARRAY = 20, 
    ID = 21, INT = 22, FLOAT = 23, WS = 24
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

