/*
// -*- C -*-
//
//                       Michael A.G. Aivazis
//                California Institute of Technology
//                   (C) 1999 All Rights Reserved
//

// $Log: config_platform.h,v $
// Revision 1.9  1999/07/14 22:25:44  aivazis
// Added PATHS_DIRECTORY_SEPARATOR
//
// Revision 1.8  1999/07/06 05:52:24  aivazis
// Added NEEDS_STRICMP and NEEDS_STRNICMP
//
// Revision 1.7  1999/07/02 03:11:09  aivazis
// Fixed a typo: lost closing comment characters (?)
//
// Revision 1.6  1999/06/19 19:15:39  aivazis
// Added HAVE_STRTOD
//
// Revision 1.5  1999/06/18 23:11:59  aivazis
// Split the automatically generated stuff into their own file
//
// Revision 1.4  1999/06/18 18:20:02  aivazis
// Leverage magnum: Added an autoconf-generated section
//
*/

#if !defined(__config_platform_h__)
#define __config_platform_h__

/*
 * The following is here for historical reasons.
 * Removing it wouldn't hurt any existing code because of HAVE_UNAME below
 */

/* Define if you have sysinfo */
#define HAVE_SYSINFO
 
/* Include the automatically generated platform header */
#include "autoconfig.h"

/* Here are some defines that autoconfig does not guess */

/* Define if the system strtod exists and works correctly */
#define HAVE_STRTOD 1

/* Here are things that are missing */

#define NEEDS_STRICMP
#define NEEDS_STRNICMP

/* Pathnames */
#define PATHS_DIRECTORY_SEPARATOR "/"

#endif

/* End of file */
