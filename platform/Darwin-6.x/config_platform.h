/* -*- C -*-
// 
//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//                               Michael A.G. Aivazis
//                        California Institute of Technology
//                        (C) 1998-2003 All Rights Reserved
// 
//  <LicenseText>
// 
//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


#if !defined(__config_platform_h__)
#define __config_platform_h__

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

// version
// $Id: config_platform.h,v 1.1 2003/02/27 19:38:42 aivazis Exp $

/* End of file */
