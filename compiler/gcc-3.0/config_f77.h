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
*/

#if !defined(__config_f77_h__)
#define __config_f77_h__

#define NEEDS_F77_TRANSLATION
/* By default, g77 adds extra trailing underscore if symbol contains an underscore, just like Compaq Fortran compiler */
#define F77EXTERNS_LOWERCASE_EXTRATRAILINGBAR

/* Macros to perform proper name mangling */
#define FORTRAN_NAME(x,y) x ## _
#define FORTRAN_NAME_(x,y) x ## __

/* Obsolete name for this mangling scheme */
#define F77EXTERNS_COMPAQ_F90

#endif

/* End of file */
