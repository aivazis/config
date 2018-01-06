/* -*- C -*-
 *
 * michael a.g. aivazis
 * parasim
 * (c) 1998-2018  all rights reserved
 *
 */

#if !defined(__config_f77_h__)
#define __config_f77_h__

#define NEEDS_F77_TRANSLATION
#define F77EXTERNS_LOWERCASE_TRAILINGBAR

/* Macros to perform proper name mangling */
#define FORTRAN_NAME(x,y) x ## _
#define FORTRAN_NAME_(x,y) x ## _

#endif

/* end of file */
