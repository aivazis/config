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
// Revision 1.4  2003/04/10 04:22:58  aivazis
// Added HAVE__FUNC__
//
// Revision 1.3  2001/07/11 02:17:30  cummings
// Removed *using namespace std* hack from configuration file for HP aCC
// compiler.  Also removed #define of HUGE, since we don't use this
// macro anymore.
//
// Revision 1.2  2001/01/16 19:57:30  cummings
// Changed brackets around config_f77.h to quotes,
// since this is not a standard header file.
//
// Revision 1.1  2000/08/14 23:04:39  aivazis
// Original source
//
*/

#if !defined(__config_compiler_h__)
#define __config_compiler_h__

#include "config_f77.h"

#if !defined(WITH_TAU)
/* The gcc preprocessor defines __FUNC__ */
#define HAVE__FUNC__
#endif

#endif

/* End of file */
