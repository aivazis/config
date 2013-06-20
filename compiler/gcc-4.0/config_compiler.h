/* -*- C -*-
 *--------------------------------------------------------------------------
 *
 *
 *                       Julian C. Cummings
 *                California Institute of Technology
 *                   (C) 2005 All Rights Reserved
 *
 *--------------------------------------------------------------------------
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
/* $Id: config_compiler.h,v 1.2 2007/03/06 15:36:26 rapa Exp $ */

/* End of file */
