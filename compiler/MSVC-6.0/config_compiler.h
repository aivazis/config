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
// Revision 1.7  2000/04/27 19:06:10  aivazis
// Mixed language improvements
//
// Revision 1.6  1999/10/20 18:34:27  mga
// Added blas.h with translated symbols
//
// Revision 1.5  1999/06/24 22:18:13  aivazis
// Added headers
//
*/

/*
 *
 */

#if !defined(__config_compiler_h__)
#define __config_compiler_h__

#include <config_f77.h>

#define M_PI 3.141592653589793238460


#define VC_EXTRALEAN
#include <windows.h>

/* C++ section */
#if defined(__cplusplus)

namespace std {};
using namespace std;

// Had to comment those out due to conflicts with the ACIS headers
//
// #include <string>
// #include <vector>
// #include <map>

// #include <iostream>
// #include <strstream>
// #include <fstream>

#endif
/* End of C++ section */

#if defined(WITH_MATH)
#include "blas.h"
#endif

#endif

/* End of file */
