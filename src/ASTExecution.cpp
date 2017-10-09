#include "antlr4-runtime.h"
#include "grammar/DateformatLexer.h"
#include "grammar/DateformatParser.h"
#include "ASTExecution.h"


void ASTExecution::parse( const std::string& p_input )
{
    std::cout << "parsing: " << p_input << std::endl;

    antlr4::ANTLRInputStream l_input( p_input );
    DateformatLexer l_lexer( &l_input );
    antlr4::CommonTokenStream l_token( &l_lexer );
    DateformatParser l_parser( &l_token );
    antlr4::tree::ParseTree* l_tree = l_parser.main();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk( this, l_tree );
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

