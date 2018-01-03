/* -*- C -*-
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                             michael a.g. aïvázis
 *                      california institute of technology
 *                      (c) 1998-2018  all rights reserved
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 */

#if !defined(__config_compiler_h__)
#define __config_compiler_h__

#include <config_f77.h>

#if !defined(WITH_TAU)
/* The gcc preprocessor defines __FUNC__ */
#define HAVE__FUNC__
#endif

#define NEEDS_GLIBC2_FPE_TRAP

#endif

/* version */
/* $Id: config_compiler.h,v 1.1 2013/03/08 00:15:24 mga Exp $ */

/* End of file */
