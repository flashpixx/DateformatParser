#include "ASTExecution.h"
#include "../include/Library.h"


DateFormat* parsedateformat( char* p_char, const DateType* p_now )
{
    ASTExecution l_execute( std::string( p_char ), p_now );
    return l_execute.get();
}