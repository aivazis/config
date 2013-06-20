/*
// -*- C -*-
//--------------------------------------------------------------------------
//
//
//                       Michael A.G. Aivazis
//                California Institute of Technology
//                   (C) 1999 All Rights Reserved
//
//--------------------------------------------------------------------------

// $Log: config_compiler.h,v $
// Revision 1.1  2000/08/17 22:01:34  cummings
// Added new build system compiler definition and configuration files
// for gcc-2.95.2 compiler.
//
//
*/

#if !defined(__config_compiler_h__)
#define __config_compiler_h__

#include <config_f77.h>

/* The gcc preprocessor defines __FUNC__ */
#define HAVE__FUNC__


#if defined(__cplusplus)

namespace std {};
using namespace std;

#endif

#endif

/* End of file */
