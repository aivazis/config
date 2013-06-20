/*
 *
 *                California Institute of Technology
 *                   (C) 2001 All Rights Reserved
 *
 * $Log: stdio.h,v $
 * Revision 1.3  2001/06/12 18:54:35  cummings
 * Added include guard to this file.
 *
 * Revision 1.2  2001/04/28 01:17:32  cummings
 * The trick of using the #include_next directive to include
 * the standard stdio.h header file from here works with the
 * C cross-compiler for TFLOPS, but not with the C++ cross-
 * compiler.  Doh!  Instead, include stdio.h by specifying
 * the full pathname on the ASCI Red front-end server.
 *
 * Revision 1.1  2001/04/27 00:34:43  cummings
 * Replacement for <stdio.h> header on TFLOPS platform that adds missing
 * declarations of getopt and optargs, which we use in our C drivers to
 * process the command-line arguments.
 *
 *
 */

#if !defined(__config_platform_stdio_h__)
#define __config_platform_stdio_h__

/* Replacement for stdio.h header file on TFLOPS to add getopt and optargs */

#include "/usr/local/intel/tflop/current/tflops/include/stdio.h"

/*
 * Add missing declarations for getopt and optargs.
 */

extern int getopt(int, char *const *, const char *);
extern char *optarg;

#endif

/* End of file */
