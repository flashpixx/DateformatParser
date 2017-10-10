#include <stdio.h>
#include <stdlib.h>
#include "../include/Library.h"


/** terminate function, for suppress exspecially on Windows the abnormal termination
 * message, that is thrown on uncaught exceptions. The handler need not call the
 * "abort()" function, because this creates the message
 **/
 #if defined(_WIN32) || defined(_WIN64)
 void program_terminate() {
    exit(EXIT_FAILURE); 
}
#endif


/**
 * test program
 *
 * @param p_argc argument number
 * @param p_argv arguments
 * @return execution
 */
int main( int p_argc, char* p_argv[] )
{
    #if defined(_WIN32) || defined(_WIN64)
    set_terminate(program_terminate);
    #endif
    

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
    free( l_third );

    return EXIT_SUCCESS;
}
