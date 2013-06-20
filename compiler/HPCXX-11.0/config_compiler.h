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
// Revision 1.4  2000/08/03 23:16:45  sharon
// HP doesn't understand HUGE, so we give it the local standard DLB_MAX
//
// Revision 1.3  2000/04/27 19:06:10  aivazis
// Mixed language improvements
//
// Revision 1.2  1999/06/24 22:18:12  aivazis
// Added headers
//
*/

#if !defined(__config_compiler_h__)
#define __config_compiler_h__

#include <config_f77.h>

#define HUGE DBL_MAX

#endif

/* End of file */
