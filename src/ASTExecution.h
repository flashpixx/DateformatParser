#pragma once

#include <string>
#include "grammar/DateformatBaseListener.h"

/**
 * abstract syntax tree class
 */
class ASTExecution : public DateformatBaseListener
{
    public :

        /**
         * parsing call
         *
         * @param p_input input string
         */
        void parse( const std::string& p_input );

        void enterDateunit( DateformatParser::DateunitContext* context ) override;

        void enterSign( DateformatParser::SignContext* context ) override;

        void enterNow( DateformatParser::NowContext* context ) override;

        void enterDateelement( DateformatParser::DateelementContext* context ) override;

        void enterNumber( DateformatParser::NumberContext* context ) override;

};