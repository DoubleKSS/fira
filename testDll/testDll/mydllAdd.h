//
// MATLAB Compiler: 5.1 (R2014a)
// Date: Tue Jan 30 16:08:57 2018
// Arguments: "-B" "macro_default" "-W" "cpplib:mydllAdd" "-T" "link:lib"
// "Add.m" 
//

#ifndef __mydllAdd_h
#define __mydllAdd_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_mydllAdd
#define PUBLIC_mydllAdd_C_API __global
#else
#define PUBLIC_mydllAdd_C_API /* No import statement needed. */
#endif

#define LIB_mydllAdd_C_API PUBLIC_mydllAdd_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_mydllAdd
#define PUBLIC_mydllAdd_C_API __declspec(dllexport)
#else
#define PUBLIC_mydllAdd_C_API __declspec(dllimport)
#endif

#define LIB_mydllAdd_C_API PUBLIC_mydllAdd_C_API


#else

#define LIB_mydllAdd_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_mydllAdd_C_API 
#define LIB_mydllAdd_C_API /* No special import/export declaration */
#endif

extern LIB_mydllAdd_C_API 
bool MW_CALL_CONV mydllAddInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_mydllAdd_C_API 
bool MW_CALL_CONV mydllAddInitialize(void);

extern LIB_mydllAdd_C_API 
void MW_CALL_CONV mydllAddTerminate(void);



extern LIB_mydllAdd_C_API 
void MW_CALL_CONV mydllAddPrintStackTrace(void);

extern LIB_mydllAdd_C_API 
bool MW_CALL_CONV mlxAdd(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_mydllAdd
#define PUBLIC_mydllAdd_CPP_API __declspec(dllexport)
#else
#define PUBLIC_mydllAdd_CPP_API __declspec(dllimport)
#endif

#define LIB_mydllAdd_CPP_API PUBLIC_mydllAdd_CPP_API

#else

#if !defined(LIB_mydllAdd_CPP_API)
#if defined(LIB_mydllAdd_C_API)
#define LIB_mydllAdd_CPP_API LIB_mydllAdd_C_API
#else
#define LIB_mydllAdd_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_mydllAdd_CPP_API void MW_CALL_CONV Add(int nargout, mwArray& c, const mwArray& a, const mwArray& b);

#endif
#endif
