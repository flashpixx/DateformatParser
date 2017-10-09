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

/**
 * parsing dateformat
 *
 * @param date string
 */
DLLEXPORT void parsedateformat( char* );
