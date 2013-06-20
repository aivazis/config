/*
// -*- C -*-
//
//                       Michael A.G. Aivazis
//                California Institute of Technology
//                   (C) 1999 All Rights Reserved
//

// $Log: config_compiler.h,v $
// Revision 1.3  2000/04/27 19:06:11  aivazis
// Mixed language improvements
//
// Revision 1.2  1999/10/23 04:00:14  aivazis
// Added a using namespace std.
//
// Revision 1.1  1999/10/23 03:25:53  aivazis
// Original source
//
*/

#if !defined(__config_compiler_h__)
#define __config_compiler_h__

#include <config_f77.h>

/* C++ section */
#if defined(__cplusplus)

namespace std {};
using namespace std;

#endif
/* End of C++ section */

#endif

/* End of file */
