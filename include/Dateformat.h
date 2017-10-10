#pragma once


#ifdef _WIN32
/** exporting flag for DLL functions on Windows systems **/
#define DLLEXPORT _declspec(dllexport)
/** hiding flag of DLL functions on Unix systems **/
#define DLLLOCAL
#else
/** exporting flag for DLL functions on Windows systems **/
#define DLLEXPORT
/** hiding flag of DLL functions on Unix systems **/
#ifndef __DOXYGEN
#define DLLLOCAL __attribute__((visibility("hidden")))
#else
#define DLLLOCAL
#endif
#endif


#ifdef __cplusplus
extern "C" {
#endif



#include <stdbool.h>
#if defined(_WIN32) || defined(_WIN64)
#include <inttypes.h>
#else
#include <unitypes.h>
#endif


/**
 * struct of date definition
 */
typedef struct DateType
{
    /**
     * year definition
     */
    const uint16_t year;

    /**
     * month definition
     */
    const uint8_t month;

    /**
     * day definition
     */
    const uint8_t day;

    /**
     * hour
     */
    const uint8_t hour;

    /**
     * minute
     */
    const uint8_t minute;

} DateType;


typedef struct DateFormat
{
    /**
     * parsing successful
     */
    const bool parsesuccessfully;

    /**
     * start date
     */
    const DateType start;

    /**
     * end date
     */
    const DateType end;

} DateFormat;


/**
 * parsing dateformat
 *
 * @param p_char date format string
 * @param p_now now definition
 * @return date format (must be freed extern)
 */
DLLEXPORT DateFormat* parsedateformat( const char* p_char, const DateType* p_now );


#ifdef __cplusplus
}
#endif
