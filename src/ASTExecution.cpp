#include <cassert>
#include "antlr4-runtime.h"
#include "grammar/DateformatLexer.h"
#include "grammar/DateformatParser.h"
#include "ASTExecution.h"

ASTExecution::ASTExecution( const std::string& p_input, const DateType* p_now ) :
    m_now( p_now )
{
    assert( m_now );

    std::cout << "parsing: " << p_input << std::endl;

    antlr4::ANTLRInputStream l_input( p_input );
    DateformatLexer l_lexer( &l_input );
    antlr4::CommonTokenStream l_token( &l_lexer );
    DateformatParser l_parser( &l_token );
    antlr4::tree::ParseTree* l_tree = l_parser.main();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk( this, l_tree );
}


DateFormat* ASTExecution::get()
{
    // build result struct on stack
    DateFormat l_result = { false, { 0,0,0, 0,0 }, { 0,0,0, 0,0 } };


    // copy stack to heap C-like
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
