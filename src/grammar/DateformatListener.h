
// Generated from grammar/Dateformat.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "DateformatParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by DateformatParser.
 */
class  DateformatListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(DateformatParser::MainContext *ctx) = 0;
  virtual void exitMain(DateformatParser::MainContext *ctx) = 0;

  virtual void enterDateelement(DateformatParser::DateelementContext *ctx) = 0;
  virtual void exitDateelement(DateformatParser::DateelementContext *ctx) = 0;

  virtual void enterDateunit(DateformatParser::DateunitContext *ctx) = 0;
  virtual void exitDateunit(DateformatParser::DateunitContext *ctx) = 0;

  virtual void enterSign(DateformatParser::SignContext *ctx) = 0;
  virtual void exitSign(DateformatParser::SignContext *ctx) = 0;

  virtual void enterNumber(DateformatParser::NumberContext *ctx) = 0;
  virtual void exitNumber(DateformatParser::NumberContext *ctx) = 0;

  virtual void enterNow(DateformatParser::NowContext *ctx) = 0;
  virtual void exitNow(DateformatParser::NowContext *ctx) = 0;


};

