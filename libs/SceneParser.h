
// Generated from Scene.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  SceneParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, DRAW = 3, WRITE = 4, IN = 5, AT = 6, CIRCLE = 7, 
    SQUARE = 8, SMALL = 9, MEDIUM = 10, BIG = 11, LEFT = 12, RIGHT = 13, 
    CENTER = 14, TOP = 15, BOTTOM = 16, STRING = 17, BLACK = 18, BLUE = 19, 
    BROWN = 20, GREEN = 21, RED = 22, ORANGE = 23, PURPLE = 24, YELLOW = 25, 
    WHITE = 26, NAME = 27, NEWLINE = 28, TAB = 29, WHITESPACE = 30
  };

  enum {
    RuleFile = 0, RuleName = 1, RuleAction = 2, RuleSize = 3, RuleShape = 4, 
    RuleColor = 5, RulePosition = 6
  };

  explicit SceneParser(antlr4::TokenStream *input);

  SceneParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~SceneParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FileContext;
  class NameContext;
  class ActionContext;
  class SizeContext;
  class ShapeContext;
  class ColorContext;
  class PositionContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    SceneParser::ActionContext *actionContext = nullptr;
    std::vector<ActionContext *> elements;
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    NameContext *name();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TAB();
    antlr4::tree::TerminalNode* TAB(size_t i);
    std::vector<ActionContext *> action();
    ActionContext* action(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

  class  ActionContext : public antlr4::ParserRuleContext {
  public:
    ActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DRAW();
    SizeContext *size();
    ShapeContext *shape();
    antlr4::tree::TerminalNode *IN();
    ColorContext *color();
    antlr4::tree::TerminalNode *AT();
    PositionContext *position();
    antlr4::tree::TerminalNode *WRITE();
    antlr4::tree::TerminalNode *STRING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();

  class  SizeContext : public antlr4::ParserRuleContext {
  public:
    SizeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SMALL();
    antlr4::tree::TerminalNode *MEDIUM();
    antlr4::tree::TerminalNode *BIG();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SizeContext* size();

  class  ShapeContext : public antlr4::ParserRuleContext {
  public:
    ShapeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CIRCLE();
    antlr4::tree::TerminalNode *SQUARE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShapeContext* shape();

  class  ColorContext : public antlr4::ParserRuleContext {
  public:
    ColorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BLACK();
    antlr4::tree::TerminalNode *BLUE();
    antlr4::tree::TerminalNode *BROWN();
    antlr4::tree::TerminalNode *GREEN();
    antlr4::tree::TerminalNode *RED();
    antlr4::tree::TerminalNode *ORANGE();
    antlr4::tree::TerminalNode *PURPLE();
    antlr4::tree::TerminalNode *YELLOW();
    antlr4::tree::TerminalNode *WHITE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ColorContext* color();

  class  PositionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *x = nullptr;
    antlr4::Token *y = nullptr;
    PositionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT();
    std::vector<antlr4::tree::TerminalNode *> CENTER();
    antlr4::tree::TerminalNode* CENTER(size_t i);
    antlr4::tree::TerminalNode *RIGHT();
    antlr4::tree::TerminalNode *TOP();
    antlr4::tree::TerminalNode *BOTTOM();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PositionContext* position();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

