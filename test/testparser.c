#include <stdio.h>
#include "../include/Library.h"

/**
 * test program
 *
 * @param p_argc argument number
 * @param p_argv arguments
 * @return execution
 */
int main( int p_argc, char* p_argv[] )
{
    parsedateformat( "q5" );
    printf( "\n\n" );

    parsedateformat( "t+3q#2" );
    printf( "\n\n" );

    parsedateformat( "y2000xy" );
}
