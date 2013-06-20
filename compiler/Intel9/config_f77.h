/*
// -*- C -*-
//--------------------------------------------------------------------------
//
//
//                       Julian C. Cummings
//                California Institute of Technology
//                   (C) 2006 All Rights Reserved
//
//--------------------------------------------------------------------------
*/

#if !defined(__config_f77_h__)
#define __config_f77_h__

#define NEEDS_F77_TRANSLATION
#define F77EXTERNS_LOWERCASE_TRAILINGBAR

/* Macros to perform proper name mangling */
#define FORTRAN_NAME(x,y) x ## _
#define FORTRAN_NAME_(x,y) x ## _

#endif

/* version */
/* $Id: config_f77.h,v 1.1 2006/08/30 02:21:27 cummings Exp $ */

/* End of file */
