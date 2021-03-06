#include "ASTListener.h"
#include "../include/Dateformat.h"
#include "Common.h"


DateFormat* parsedateformat( const char* p_char, const DateType* p_now )
{
    ASSERT( p_now, "date pointer is null" )
    LOG( "start parsing %s", p_char )

    ASTListener l_execute( std::string( p_char ), p_now );
    return l_execute.get();
}