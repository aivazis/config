/*
// -*- C -*-
//
//                       Michael A.G. Aivazis
//                California Institute of Technology
//                   (C) 1999 All Rights Reserved
//

// $Log: config_platform.h,v $
// Revision 1.1  2011/11/04 00:58:05  aivazis
// added support for linux 3.x
//
// Revision 1.8  2010/02/14 03:46:12  aivazis
// Added platform identifier
//
// Revision 1.7  2000/09/29 01:44:26  cummings
// Protected the #define of NEEDS_TRAP_FPE with a check for __GNUC__
// being defined, which indicates that we are running gcc.  The PGI
// pgcc compiler barfs on the floating-point exception trapping code.
//
// Revision 1.6  1999/12/24 19:06:04  rapa
// added NEEDS_TRAP_FPE to platform
//
// Revision 1.5  1999/08/30 16:01:12  aivazis
// Added include "autoconfig.h" and performed associated housekeeping
//
// Revision 1.4  1999/07/01 05:24:59  aivazis
// Added headers
//
*/

#if !defined(__config_platform_h__)
#define __config_platform_h__

#define __config_platform_linux 1
#define __config_platform_linux_2_x 1

/* Include the automatically generated platform header */
#include "autoconfig.h"

/* Here are some settings that autoconfig does not guess */

/* Things that are missing */
#define NEEDS_STRICMP
#define NEEDS_STRNICMP

/* Pathnames */
#define PATHS_DIRECTORY_SEPARATOR "/"

/* Trap FPE */
#ifdef __GNUC__
#define NEEDS_TRAP_FPE
#endif

#endif

/* End of file */
