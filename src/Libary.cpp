#include "ASTExecution.h"
#include "../include/Library.h"


void parsedateformat( char* p_char, const DateType* p_now )
{
    ASTExecution l_execute( std::string( p_char ), p_now );
}