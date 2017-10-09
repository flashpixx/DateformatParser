
// Generated from grammar/Dateformat.g4 by ANTLR 4.7


#include "DateformatListener.h"

#include "DateformatParser.h"


using namespace antlrcpp;
using namespace antlr4;

DateformatParser::DateformatParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

DateformatParser::~DateformatParser() {
  delete _interpreter;
}

std::string DateformatParser::getGrammarFileName() const {
  return "Dateformat.g4";
}

const std::vector<std::string>& DateformatParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& DateformatParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MainContext ------------------------------------------------------------------

DateformatParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DateformatParser::DateelementContext *> DateformatParser::MainContext::dateelement() {
  return getRuleContexts<DateformatParser::DateelementContext>();
}

DateformatParser::DateelementContext* DateformatParser::MainContext::dateelement(size_t i) {
  return getRuleContext<DateformatParser::DateelementContext>(i);
}


size_t DateformatParser::MainContext::getRuleIndex() const {
  return DateformatParser::RuleMain;
}

void DateformatParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void DateformatParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}

DateformatParser::MainContext* DateformatParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, DateformatParser::RuleMain);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(13); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(12);
      dateelement();
      setState(15); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DateformatParser::DAY)
      | (1ULL << DateformatParser::WEEK)
      | (1ULL << DateformatParser::MONTH)
      | (1ULL << DateformatParser::QUARTER)
      | (1ULL << DateformatParser::HALFYEAR)
      | (1ULL << DateformatParser::YEAR))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DateelementContext ------------------------------------------------------------------

DateformatParser::DateelementContext::DateelementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DateformatParser::DateunitContext* DateformatParser::DateelementContext::dateunit() {
  return getRuleContext<DateformatParser::DateunitContext>(0);
}

DateformatParser::NowContext* DateformatParser::DateelementContext::now() {
  return getRuleContext<DateformatParser::NowContext>(0);
}

DateformatParser::SignContext* DateformatParser::DateelementContext::sign() {
  return getRuleContext<DateformatParser::SignContext>(0);
}

DateformatParser::NumberContext* DateformatParser::DateelementContext::number() {
  return getRuleContext<DateformatParser::NumberContext>(0);
}


size_t DateformatParser::DateelementContext::getRuleIndex() const {
  return DateformatParser::RuleDateelement;
}

void DateformatParser::DateelementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDateelement(this);
}

void DateformatParser::DateelementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDateelement(this);
}

DateformatParser::DateelementContext* DateformatParser::dateelement() {
  DateelementContext *_localctx = _tracker.createInstance<DateelementContext>(_ctx, getState());
  enterRule(_localctx, 2, DateformatParser::RuleDateelement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    dateunit();
    setState(19);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DateformatParser::NOW) {
      setState(18);
      now();
    }
    setState(22);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DateformatParser::PLUS

    || _la == DateformatParser::MINUS) {
      setState(21);
      sign();
    }
    setState(25);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DateformatParser::DIGIT) {
      setState(24);
      number();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DateunitContext ------------------------------------------------------------------

DateformatParser::DateunitContext::DateunitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DateformatParser::DateunitContext::DAY() {
  return getToken(DateformatParser::DAY, 0);
}

tree::TerminalNode* DateformatParser::DateunitContext::WEEK() {
  return getToken(DateformatParser::WEEK, 0);
}

tree::TerminalNode* DateformatParser::DateunitContext::MONTH() {
  return getToken(DateformatParser::MONTH, 0);
}

tree::TerminalNode* DateformatParser::DateunitContext::QUARTER() {
  return getToken(DateformatParser::QUARTER, 0);
}

tree::TerminalNode* DateformatParser::DateunitContext::HALFYEAR() {
  return getToken(DateformatParser::HALFYEAR, 0);
}

tree::TerminalNode* DateformatParser::DateunitContext::YEAR() {
  return getToken(DateformatParser::YEAR, 0);
}


size_t DateformatParser::DateunitContext::getRuleIndex() const {
  return DateformatParser::RuleDateunit;
}

void DateformatParser::DateunitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDateunit(this);
}

void DateformatParser::DateunitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDateunit(this);
}

DateformatParser::DateunitContext* DateformatParser::dateunit() {
  DateunitContext *_localctx = _tracker.createInstance<DateunitContext>(_ctx, getState());
  enterRule(_localctx, 4, DateformatParser::RuleDateunit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DateformatParser::DAY)
      | (1ULL << DateformatParser::WEEK)
      | (1ULL << DateformatParser::MONTH)
      | (1ULL << DateformatParser::QUARTER)
      | (1ULL << DateformatParser::HALFYEAR)
      | (1ULL << DateformatParser::YEAR))) != 0))) {
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

//----------------- SignContext ------------------------------------------------------------------

DateformatParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DateformatParser::SignContext::PLUS() {
  return getToken(DateformatParser::PLUS, 0);
}

tree::TerminalNode* DateformatParser::SignContext::MINUS() {
  return getToken(DateformatParser::MINUS, 0);
}


size_t DateformatParser::SignContext::getRuleIndex() const {
  return DateformatParser::RuleSign;
}

void DateformatParser::SignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSign(this);
}

void DateformatParser::SignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSign(this);
}

DateformatParser::SignContext* DateformatParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 6, DateformatParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    _la = _input->LA(1);
    if (!(_la == DateformatParser::PLUS

    || _la == DateformatParser::MINUS)) {
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

//----------------- NumberContext ------------------------------------------------------------------

DateformatParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DateformatParser::NumberContext::DIGIT() {
  return getTokens(DateformatParser::DIGIT);
}

tree::TerminalNode* DateformatParser::NumberContext::DIGIT(size_t i) {
  return getToken(DateformatParser::DIGIT, i);
}


size_t DateformatParser::NumberContext::getRuleIndex() const {
  return DateformatParser::RuleNumber;
}

void DateformatParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void DateformatParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

DateformatParser::NumberContext* DateformatParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 8, DateformatParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(31);
      match(DateformatParser::DIGIT);
      setState(34); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DateformatParser::DIGIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NowContext ------------------------------------------------------------------

DateformatParser::NowContext::NowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DateformatParser::NowContext::NOW() {
  return getToken(DateformatParser::NOW, 0);
}


size_t DateformatParser::NowContext::getRuleIndex() const {
  return DateformatParser::RuleNow;
}

void DateformatParser::NowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNow(this);
}

void DateformatParser::NowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DateformatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNow(this);
}

DateformatParser::NowContext* DateformatParser::now() {
  NowContext *_localctx = _tracker.createInstance<NowContext>(_ctx, getState());
  enterRule(_localctx, 10, DateformatParser::RuleNow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(DateformatParser::NOW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> DateformatParser::_decisionToDFA;
atn::PredictionContextCache DateformatParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN DateformatParser::_atn;
std::vector<uint16_t> DateformatParser::_serializedATN;

std::vector<std::string> DateformatParser::_ruleNames = {
  "main", "dateelement", "dateunit", "sign", "number", "now"
};

std::vector<std::string> DateformatParser::_literalNames = {
  "", "'+'", "'-'", "", "'w'", "'m'", "'q'", "'h'"
};

std::vector<std::string> DateformatParser::_symbolicNames = {
  "", "PLUS", "MINUS", "DAY", "WEEK", "MONTH", "QUARTER", "HALFYEAR", "YEAR", 
  "NOW", "DIGIT", "WHITESPACE"
};

dfa::Vocabulary DateformatParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> DateformatParser::_tokenNames;

DateformatParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xd, 0x29, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x6, 0x2, 0x10, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x11, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x16, 0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x1c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x6, 0x6, 0x23, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x24, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x2, 0x2, 0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 
    0x4, 0x3, 0x2, 0x5, 0xa, 0x3, 0x2, 0x3, 0x4, 0x2, 0x27, 0x2, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x22, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x26, 0x3, 0x2, 0x2, 0x2, 0xe, 0x10, 0x5, 0x4, 0x3, 0x2, 0xf, 0xe, 0x3, 
    0x2, 0x2, 0x2, 0x10, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x11, 0x12, 0x3, 0x2, 0x2, 0x2, 0x12, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x13, 0x15, 0x5, 0x6, 0x4, 0x2, 0x14, 0x16, 0x5, 0xc, 0x7, 0x2, 
    0x15, 0x14, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x17, 0x19, 0x5, 0x8, 0x5, 0x2, 0x18, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x1c, 0x5, 0xa, 0x6, 0x2, 0x1b, 0x1a, 0x3, 0x2, 
    0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x1e, 0x9, 0x2, 0x2, 0x2, 0x1e, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x20, 0x9, 0x3, 0x2, 0x2, 0x20, 0x9, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x23, 0x7, 0xc, 0x2, 0x2, 0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0xb, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0xb, 
    0x2, 0x2, 0x27, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7, 0x11, 0x15, 0x18, 0x1b, 
    0x24, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

DateformatParser::Initializer DateformatParser::_init;
