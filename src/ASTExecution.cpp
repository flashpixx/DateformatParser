#include <cassert>
#include "antlr4-runtime.h"
#include "grammar/DateformatLexer.h"
#include "grammar/DateformatParser.h"
#include "ASTExecution.h"
#include "ASTErrorListener.h"

ASTExecution::ASTExecution( const std::string& p_input, const DateType* p_now ) :
    m_now( p_now ),
    m_parsesuccessfully( false )
{
    assert( m_now );

    std::cout << "parsing: " << p_input << std::endl;

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


DateFormat* ASTExecution::get()
{
    // build result struct on stack
    DateFormat l_result = { m_parsesuccessfully, { 0,0,0, 0,0 }, { 0,0,0, 0,0 } };

    // copy C-like stack element to heap
    auto* l_copy = static_cast<DateFormat*>( std::malloc( sizeof( DateFormat ) ) );
    std::memcmp( l_copy, &l_result, sizeof( DateFormat ) );
    return l_copy;
}


void ASTExecution::enterDateunit( DateformatParser::DateunitContext* p_context )
{
    std::cout << "found dateunit " << p_context->getText() << std::endl;
}


void ASTExecution::enterSign( DateformatParser::SignContext* p_context )
{
    std::cout << "found sign " << p_context->getText() << std::endl;
}


void ASTExecution::enterNow( DateformatParser::NowContext* p_context )
{
    std::cout << "found now " << p_context->getText() << std::endl;
}


void ASTExecution::enterDateelement( DateformatParser::DateelementContext* p_context )
{
    std::cout << "found date element " << p_context->getText() << std::endl;
}

void ASTExecution::enterNumber( DateformatParser::NumberContext* p_context )
{
    std::cout << "found number " << std::stoi( p_context->getText() ) << std::endl;
}
