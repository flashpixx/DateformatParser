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

#include <unitypes.h>
#include <stdbool.h>

/**
 * struct of date definition
 */
typedef struct DateType
{
    /**
     * year definition
     */
    const uint32_t year;

    /**
     * month definition
     */
    const uint32_t month;

    /**
     * day definition
     */
    const uint32_t day;

    /**
     * hour
     */
    const uint32_t hour;

    /**
     * minute
     */
    const uint32_t minute;

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
    const struct DateType start;

    /**
     * end date
     */
    const struct DateType end;

} DateFormat;





/**
 * parsing dateformat
 *
 * @param p_char date format string
 * @param p_now now definition
 * @return date format (must be freed extern)
 */
DLLEXPORT DateFormat* parsedateformat( char* p_char, const DateType* p_now );


#ifdef __cplusplus
}
#endif
