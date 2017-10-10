#pragma once


#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include <stdio.h>


/** macro to expand other macros **/
#define DEBUGSTRINGEXPAND( x ) #x
/** macro to stringify a value **/
#define DEBUGSTRINGIFY( x ) DEBUGSTRINGEXPAND(x)


/**
 * individual assert command with comment option
 * @see http://www.cplusplus.com/reference/cassert/assert/
 **/
#ifdef NDEBUG
#define ASSERT( p_expression, p_format, ... )
#else

#define ASSERT( p_expression, p_format, ... ) \
            if (!(p_expression)) \
            { \
                fprintf( stderr, "ASSERT line %s file %s: " p_format "\n", DEBUGSTRINGIFY(__LINE__), DEBUGSTRINGIFY(__FILE__), ##__VA_ARGS__ ); \
                exit(EXIT_FAILURE); \
            }
#endif


/**
 * log definition to write a message to the
 * stdout, syntax is like printf
 **/
#ifdef NDEBUG
#define LOG( p_expression, ... )
#else
#define LOG( p_expression, ... ) printf( "LOG line %s file %s: " p_expression "\n", DEBUGSTRINGIFY(__LINE__), DEBUGSTRINGIFY(__FILE__), ##__VA_ARGS__ );
#endif


#ifdef __cplusplus
}
#endif
