#pragma once

#include <string>
#include "../include/Library.h"
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
         * @param p_now now definition
         */
        ASTExecution( const std::string& p_input, const DateType* p_now );

        /**
         * returns resulted date format
         *
         * @return date format poinzter (must be freed extern)
         */
        DateFormat* get();

        void enterDateunit( DateformatParser::DateunitContext* context ) override;

        void enterSign( DateformatParser::SignContext* context ) override;

        void enterNow( DateformatParser::NowContext* context ) override;

        void enterDateelement( DateformatParser::DateelementContext* context ) override;

        void enterNumber( DateformatParser::NumberContext* context ) override;


    private :

        /**
         * pointer of now definition
         */
        const DateType* m_now;
        /**
         * parsing successfully flag
         */
        bool m_parsesuccessfully;

};