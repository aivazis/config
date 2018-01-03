/* -*- C -*-
// 
// michael a.g. aïvázis
// california institute of technology
// (c) 1998-2018 all rights reserved
// 
*/

#if !defined(__config_platform_h__)
#define __config_platform_h__

#define __config_platform_darwin 1
#define __config_platform_darwin_8_x 1
#define __config_platform_darwin_9_x 1
#define __config_platform_darwin_10_x 1
#define __config_platform_darwin_11_x 1
#define __config_platform_darwin_12_x 1


/* Pathnames */
#define PATHS_DIRECTORY_SEPARATOR "/"

/* Trap FPE */
#ifdef __GNUC__
#define NEEDS_TRAP_FPE
#endif

/* system calls */
#define HAVE_SYSCTL 1
/* cpu count and geometry through "hw.xxxx" */
#define HAVE_SYSCTL_HW_DOT 1

#endif

/* $Id: config_platform.h,v 1.3 2012/12/12 15:20:32 mga Exp $ */

/* end of file */
