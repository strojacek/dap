
// Generated from Scene.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  SceneLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, DRAW = 3, WRITE = 4, IN = 5, AT = 6, CIRCLE = 7, 
    SQUARE = 8, SMALL = 9, MEDIUM = 10, BIG = 11, LEFT = 12, RIGHT = 13, 
    CENTER = 14, TOP = 15, BOTTOM = 16, STRING = 17, BLACK = 18, BLUE = 19, 
    BROWN = 20, GREEN = 21, RED = 22, ORANGE = 23, PURPLE = 24, YELLOW = 25, 
    WHITE = 26, NAME = 27, NEWLINE = 28, TAB = 29, WHITESPACE = 30
  };

  explicit SceneLexer(antlr4::CharStream *input);

  ~SceneLexer() override;


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

