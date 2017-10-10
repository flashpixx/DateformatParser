#include <cassert>
#include "antlr4-runtime.h"
#include "grammar/DateformatLexer.h"
#include "grammar/DateformatParser.h"
#include "ASTListener.h"
#include "ASTErrorListener.h"
#include "Common.h"


ASTListener::ASTListener( const std::string& p_input, const DateType* p_now ) :
    m_now( p_now ),
    m_parsesuccessfully( false )
{
    ASSERT( m_now, "date pointer is null" );
    LOG( "parsing: %s", p_input.c_str() );

    // build AntLR specific input stream of the input and set error listener
    ASTErrorListener l_error;
    antlr4::ANTLRInputStream l_input( p_input );

    // create lexer and tocken stream for parser
    DateformatLexer l_lexer( &l_input );
    l_lexer.removeErrorListeners();
    l_lexer.addErrorListener( &l_error );
    antlr4::CommonTokenStream l_token( &l_lexer );

    // create parser and error listener
    DateformatParser l_parser( &l_token );
    l_parser.removeErrorListeners();
    l_parser.addErrorListener( &l_error );


    try
    {
        // get top-level grammer rule as node in the parsing tree
        antlr4::tree::ParseTree* l_tree = l_parser.main();
        // start parsing process and catch any error
        antlr4::tree::ParseTreeWalker::DEFAULT.walk( this, l_tree );

        m_parsesuccessfully = true;
    }
    catch ( const std::invalid_argument& p_exception )
    {
    }
}


DateFormat* ASTListener::get()
{
    // build result struct on help with data
    return new DateFormat{ m_parsesuccessfully, { 0,0,0, 0,0 }, { 0,0,0, 0,0 } };
}


void ASTListener::enterDateunit( DateformatParser::DateunitContext* p_context )
{
    LOG( "found dateunit %s", p_context->getText().c_str() )
}


void ASTListener::enterSign( DateformatParser::SignContext* p_context )
{
    LOG( "found sign %s", p_context->getText().c_str() )
}


void ASTListener::enterNow( DateformatParser::NowContext* p_context )
{
    LOG( "found now %s", p_context->getText().c_str() )
}


void ASTListener::enterDateelement( DateformatParser::DateelementContext* p_context )
{
    LOG( "found date element %s", p_context->getText().c_str() )
}

void ASTListener::enterNumber( DateformatParser::NumberContext* p_context )
{
    LOG( "found number %u", std::stoi( p_context->getText() ) )
}
