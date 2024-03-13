
// Generated from Scene.g4 by ANTLR 4.13.0


#include "SceneVisitor.h"

#include "SceneParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SceneParserStaticData final {
  SceneParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SceneParserStaticData(const SceneParserStaticData&) = delete;
  SceneParserStaticData(SceneParserStaticData&&) = delete;
  SceneParserStaticData& operator=(const SceneParserStaticData&) = delete;
  SceneParserStaticData& operator=(SceneParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sceneParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
SceneParserStaticData *sceneParserStaticData = nullptr;

void sceneParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (sceneParserStaticData != nullptr) {
    return;
  }
#else
  assert(sceneParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SceneParserStaticData>(
    std::vector<std::string>{
      "file", "name", "action", "size", "shape", "color", "position"
    },
    std::vector<std::string>{
      "", "':'", "','", "'draw'", "'write'", "'in'", "'at'", "'circle'", 
      "'square'", "'small'", "'medium'", "'big'", "'left'", "'right'", "'center'", 
      "'top'", "'bottom'", "", "'black'", "'blue'", "'brown'", "'green'", 
      "'red'", "'orange'", "'purple'", "'yellow'", "'white'", "", "", "", 
      "' '"
    },
    std::vector<std::string>{
      "", "", "", "DRAW", "WRITE", "IN", "AT", "CIRCLE", "SQUARE", "SMALL", 
      "MEDIUM", "BIG", "LEFT", "RIGHT", "CENTER", "TOP", "BOTTOM", "STRING", 
      "BLACK", "BLUE", "BROWN", "GREEN", "RED", "ORANGE", "PURPLE", "YELLOW", 
      "WHITE", "NAME", "NEWLINE", "TAB", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,30,60,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,1,0,1,0,3,0,20,8,0,5,0,22,8,0,10,0,12,0,25,9,0,1,0,1,0,1,1,1,
  	1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	3,2,48,8,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,6,1,6,0,0,7,0,2,4,6,
  	8,10,12,0,5,1,0,9,11,1,0,7,8,1,0,18,26,1,0,12,14,1,0,14,16,55,0,14,1,
  	0,0,0,2,28,1,0,0,0,4,47,1,0,0,0,6,49,1,0,0,0,8,51,1,0,0,0,10,53,1,0,0,
  	0,12,55,1,0,0,0,14,15,3,2,1,0,15,23,5,28,0,0,16,17,5,29,0,0,17,19,3,4,
  	2,0,18,20,5,28,0,0,19,18,1,0,0,0,19,20,1,0,0,0,20,22,1,0,0,0,21,16,1,
  	0,0,0,22,25,1,0,0,0,23,21,1,0,0,0,23,24,1,0,0,0,24,26,1,0,0,0,25,23,1,
  	0,0,0,26,27,5,0,0,1,27,1,1,0,0,0,28,29,5,27,0,0,29,30,5,1,0,0,30,3,1,
  	0,0,0,31,32,5,3,0,0,32,33,3,6,3,0,33,34,3,8,4,0,34,35,5,5,0,0,35,36,3,
  	10,5,0,36,37,5,6,0,0,37,38,3,12,6,0,38,48,1,0,0,0,39,40,5,4,0,0,40,41,
  	3,6,3,0,41,42,5,17,0,0,42,43,5,5,0,0,43,44,3,10,5,0,44,45,5,6,0,0,45,
  	46,3,12,6,0,46,48,1,0,0,0,47,31,1,0,0,0,47,39,1,0,0,0,48,5,1,0,0,0,49,
  	50,7,0,0,0,50,7,1,0,0,0,51,52,7,1,0,0,52,9,1,0,0,0,53,54,7,2,0,0,54,11,
  	1,0,0,0,55,56,7,3,0,0,56,57,5,2,0,0,57,58,7,4,0,0,58,13,1,0,0,0,3,19,
  	23,47
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sceneParserStaticData = staticData.release();
}

}

SceneParser::SceneParser(TokenStream *input) : SceneParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SceneParser::SceneParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SceneParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sceneParserStaticData->atn, sceneParserStaticData->decisionToDFA, sceneParserStaticData->sharedContextCache, options);
}

SceneParser::~SceneParser() {
  delete _interpreter;
}

const atn::ATN& SceneParser::getATN() const {
  return *sceneParserStaticData->atn;
}

std::string SceneParser::getGrammarFileName() const {
  return "Scene.g4";
}

const std::vector<std::string>& SceneParser::getRuleNames() const {
  return sceneParserStaticData->ruleNames;
}

const dfa::Vocabulary& SceneParser::getVocabulary() const {
  return sceneParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SceneParser::getSerializedATN() const {
  return sceneParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

SceneParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::FileContext::EOF() {
  return getToken(SceneParser::EOF, 0);
}

SceneParser::NameContext* SceneParser::FileContext::name() {
  return getRuleContext<SceneParser::NameContext>(0);
}

std::vector<tree::TerminalNode *> SceneParser::FileContext::NEWLINE() {
  return getTokens(SceneParser::NEWLINE);
}

tree::TerminalNode* SceneParser::FileContext::NEWLINE(size_t i) {
  return getToken(SceneParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> SceneParser::FileContext::TAB() {
  return getTokens(SceneParser::TAB);
}

tree::TerminalNode* SceneParser::FileContext::TAB(size_t i) {
  return getToken(SceneParser::TAB, i);
}

std::vector<SceneParser::ActionContext *> SceneParser::FileContext::action() {
  return getRuleContexts<SceneParser::ActionContext>();
}

SceneParser::ActionContext* SceneParser::FileContext::action(size_t i) {
  return getRuleContext<SceneParser::ActionContext>(i);
}


size_t SceneParser::FileContext::getRuleIndex() const {
  return SceneParser::RuleFile;
}


std::any SceneParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SceneVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

SceneParser::FileContext* SceneParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, SceneParser::RuleFile);
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
    setState(14);
    name();
    setState(15);
    match(SceneParser::NEWLINE);
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SceneParser::TAB) {
      setState(16);
      match(SceneParser::TAB);
      setState(17);
      antlrcpp::downCast<FileContext *>(_localctx)->actionContext = action();
      antlrcpp::downCast<FileContext *>(_localctx)->elements.push_back(antlrcpp::downCast<FileContext *>(_localctx)->actionContext);
      setState(19);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SceneParser::NEWLINE) {
        setState(18);
        match(SceneParser::NEWLINE);
      }
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(26);
    match(SceneParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

SceneParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::NameContext::NAME() {
  return getToken(SceneParser::NAME, 0);
}


size_t SceneParser::NameContext::getRuleIndex() const {
  return SceneParser::RuleName;
}


std::any SceneParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SceneVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

SceneParser::NameContext* SceneParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 2, SceneParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(SceneParser::NAME);
    setState(29);
    match(SceneParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActionContext ------------------------------------------------------------------

SceneParser::ActionContext::ActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::ActionContext::DRAW() {
  return getToken(SceneParser::DRAW, 0);
}

SceneParser::SizeContext* SceneParser::ActionContext::size() {
  return getRuleContext<SceneParser::SizeContext>(0);
}

SceneParser::ShapeContext* SceneParser::ActionContext::shape() {
  return getRuleContext<SceneParser::ShapeContext>(0);
}

tree::TerminalNode* SceneParser::ActionContext::IN() {
  return getToken(SceneParser::IN, 0);
}

SceneParser::ColorContext* SceneParser::ActionContext::color() {
  return getRuleContext<SceneParser::ColorContext>(0);
}

tree::TerminalNode* SceneParser::ActionContext::AT() {
  return getToken(SceneParser::AT, 0);
}

SceneParser::PositionContext* SceneParser::ActionContext::position() {
  return getRuleContext<SceneParser::PositionContext>(0);
}

tree::TerminalNode* SceneParser::ActionContext::WRITE() {
  return getToken(SceneParser::WRITE, 0);
}

tree::TerminalNode* SceneParser::ActionContext::STRING() {
  return getToken(SceneParser::STRING, 0);
}


size_t SceneParser::ActionContext::getRuleIndex() const {
  return SceneParser::RuleAction;
}


std::any SceneParser::ActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SceneVisitor*>(visitor))
    return parserVisitor->visitAction(this);
  else
    return visitor->visitChildren(this);
}

SceneParser::ActionContext* SceneParser::action() {
  ActionContext *_localctx = _tracker.createInstance<ActionContext>(_ctx, getState());
  enterRule(_localctx, 4, SceneParser::RuleAction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SceneParser::DRAW: {
        enterOuterAlt(_localctx, 1);
        setState(31);
        match(SceneParser::DRAW);
        setState(32);
        size();
        setState(33);
        shape();
        setState(34);
        match(SceneParser::IN);
        setState(35);
        color();
        setState(36);
        match(SceneParser::AT);
        setState(37);
        position();
        break;
      }

      case SceneParser::WRITE: {
        enterOuterAlt(_localctx, 2);
        setState(39);
        match(SceneParser::WRITE);
        setState(40);
        size();
        setState(41);
        match(SceneParser::STRING);
        setState(42);
        match(SceneParser::IN);
        setState(43);
        color();
        setState(44);
        match(SceneParser::AT);
        setState(45);
        position();
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

//----------------- SizeContext ------------------------------------------------------------------

SceneParser::SizeContext::SizeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::SizeContext::SMALL() {
  return getToken(SceneParser::SMALL, 0);
}

tree::TerminalNode* SceneParser::SizeContext::MEDIUM() {
  return getToken(SceneParser::MEDIUM, 0);
}

tree::TerminalNode* SceneParser::SizeContext::BIG() {
  return getToken(SceneParser::BIG, 0);
}


size_t SceneParser::SizeContext::getRuleIndex() const {
  return SceneParser::RuleSize;
}


std::any SceneParser::SizeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SceneVisitor*>(visitor))
    return parserVisitor->visitSize(this);
  else
    return visitor->visitChildren(this);
}

SceneParser::SizeContext* SceneParser::size() {
  SizeContext *_localctx = _tracker.createInstance<SizeContext>(_ctx, getState());
  enterRule(_localctx, 6, SceneParser::RuleSize);
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
    setState(49);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3584) != 0))) {
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

//----------------- ShapeContext ------------------------------------------------------------------

SceneParser::ShapeContext::ShapeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::ShapeContext::CIRCLE() {
  return getToken(SceneParser::CIRCLE, 0);
}

tree::TerminalNode* SceneParser::ShapeContext::SQUARE() {
  return getToken(SceneParser::SQUARE, 0);
}


size_t SceneParser::ShapeContext::getRuleIndex() const {
  return SceneParser::RuleShape;
}


std::any SceneParser::ShapeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SceneVisitor*>(visitor))
    return parserVisitor->visitShape(this);
  else
    return visitor->visitChildren(this);
}

SceneParser::ShapeContext* SceneParser::shape() {
  ShapeContext *_localctx = _tracker.createInstance<ShapeContext>(_ctx, getState());
  enterRule(_localctx, 8, SceneParser::RuleShape);
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
    setState(51);
    _la = _input->LA(1);
    if (!(_la == SceneParser::CIRCLE

    || _la == SceneParser::SQUARE)) {
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

//----------------- ColorContext ------------------------------------------------------------------

SceneParser::ColorContext::ColorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::ColorContext::BLACK() {
  return getToken(SceneParser::BLACK, 0);
}

tree::TerminalNode* SceneParser::ColorContext::BLUE() {
  return getToken(SceneParser::BLUE, 0);
}

tree::TerminalNode* SceneParser::ColorContext::BROWN() {
  return getToken(SceneParser::BROWN, 0);
}

tree::TerminalNode* SceneParser::ColorContext::GREEN() {
  return getToken(SceneParser::GREEN, 0);
}

tree::TerminalNode* SceneParser::ColorContext::RED() {
  return getToken(SceneParser::RED, 0);
}

tree::TerminalNode* SceneParser::ColorContext::ORANGE() {
  return getToken(SceneParser::ORANGE, 0);
}

tree::TerminalNode* SceneParser::ColorContext::PURPLE() {
  return getToken(SceneParser::PURPLE, 0);
}

tree::TerminalNode* SceneParser::ColorContext::YELLOW() {
  return getToken(SceneParser::YELLOW, 0);
}

tree::TerminalNode* SceneParser::ColorContext::WHITE() {
  return getToken(SceneParser::WHITE, 0);
}


size_t SceneParser::ColorContext::getRuleIndex() const {
  return SceneParser::RuleColor;
}


std::any SceneParser::ColorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SceneVisitor*>(visitor))
    return parserVisitor->visitColor(this);
  else
    return visitor->visitChildren(this);
}

SceneParser::ColorContext* SceneParser::color() {
  ColorContext *_localctx = _tracker.createInstance<ColorContext>(_ctx, getState());
  enterRule(_localctx, 10, SceneParser::RuleColor);
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
    setState(53);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 133955584) != 0))) {
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

//----------------- PositionContext ------------------------------------------------------------------

SceneParser::PositionContext::PositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::PositionContext::LEFT() {
  return getToken(SceneParser::LEFT, 0);
}

std::vector<tree::TerminalNode *> SceneParser::PositionContext::CENTER() {
  return getTokens(SceneParser::CENTER);
}

tree::TerminalNode* SceneParser::PositionContext::CENTER(size_t i) {
  return getToken(SceneParser::CENTER, i);
}

tree::TerminalNode* SceneParser::PositionContext::RIGHT() {
  return getToken(SceneParser::RIGHT, 0);
}

tree::TerminalNode* SceneParser::PositionContext::TOP() {
  return getToken(SceneParser::TOP, 0);
}

tree::TerminalNode* SceneParser::PositionContext::BOTTOM() {
  return getToken(SceneParser::BOTTOM, 0);
}


size_t SceneParser::PositionContext::getRuleIndex() const {
  return SceneParser::RulePosition;
}


std::any SceneParser::PositionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SceneVisitor*>(visitor))
    return parserVisitor->visitPosition(this);
  else
    return visitor->visitChildren(this);
}

SceneParser::PositionContext* SceneParser::position() {
  PositionContext *_localctx = _tracker.createInstance<PositionContext>(_ctx, getState());
  enterRule(_localctx, 12, SceneParser::RulePosition);
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
    setState(55);
    antlrcpp::downCast<PositionContext *>(_localctx)->x = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 28672) != 0))) {
      antlrcpp::downCast<PositionContext *>(_localctx)->x = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(56);
    match(SceneParser::T__1);
    setState(57);
    antlrcpp::downCast<PositionContext *>(_localctx)->y = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0))) {
      antlrcpp::downCast<PositionContext *>(_localctx)->y = _errHandler->recoverInline(this);
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

void SceneParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  sceneParserInitialize();
#else
  ::antlr4::internal::call_once(sceneParserOnceFlag, sceneParserInitialize);
#endif
}
