
// Generated from grammar/Dateformat.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "DateformatListener.h"


/**
 * This class provides an empty implementation of DateformatListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DateformatBaseListener : public DateformatListener {
public:

  virtual void enterMain(DateformatParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(DateformatParser::MainContext * /*ctx*/) override { }

  virtual void enterDateelement(DateformatParser::DateelementContext * /*ctx*/) override { }
  virtual void exitDateelement(DateformatParser::DateelementContext * /*ctx*/) override { }

  virtual void enterDateunit(DateformatParser::DateunitContext * /*ctx*/) override { }
  virtual void exitDateunit(DateformatParser::DateunitContext * /*ctx*/) override { }

  virtual void enterSign(DateformatParser::SignContext * /*ctx*/) override { }
  virtual void exitSign(DateformatParser::SignContext * /*ctx*/) override { }

  virtual void enterNumber(DateformatParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(DateformatParser::NumberContext * /*ctx*/) override { }

  virtual void enterNow(DateformatParser::NowContext * /*ctx*/) override { }
  virtual void exitNow(DateformatParser::NowContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

