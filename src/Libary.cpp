#include "ASTExecution.h"

extern "C" {
    #include "../include/Library.h"
}

/**
 * parse string
 *
 * @param p_char date format string
 */
void parsedateformat( char* p_char )
{
    ASTExecution l_execute;
    l_execute.parse( std::string( p_char ) );
}