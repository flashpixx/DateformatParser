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


    parsedateformat( "q5", &l_now );

    printf( "\n\n" );


    parsedateformat( "t+3q#2", &l_now );

    printf( "\n\n" );


    parsedateformat( "y2000xy", &l_now );

}
