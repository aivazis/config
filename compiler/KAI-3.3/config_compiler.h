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
// Revision 1.2  2000/04/27 19:06:10  aivazis
// Mixed language improvements
//
// Revision 1.1  1999/11/17 22:38:00  aivazis
// Original source
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
