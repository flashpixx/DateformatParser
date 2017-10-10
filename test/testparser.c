#include <stdio.h>
#include <stdlib.h>
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

    const DateType l_now = { 2014, 03, 01, 12, 00 };


    DateFormat* l_first = parsedateformat( "q5", &l_now );
    printf( l_first->parsesuccessfully ? "-> parsing successfully\n" : "-> parsing error\n" );
    free( l_first );

    printf( "\n\n" );


    DateFormat* l_second = parsedateformat( "t+3q#2", &l_now );
    printf( l_second->parsesuccessfully ? "-> parsing successfully\n" : "-> parsing error\n" );
    free( l_second );
    printf( "\n\n" );


    DateFormat* l_third = parsedateformat( "y2000xy", &l_now );
    printf( l_third->parsesuccessfully ? "-> parsing successfully\n" : "-> parsing error\n" );
    free( l_second );

}
