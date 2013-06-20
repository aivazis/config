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

// $Log: config_f77.h,v $
// Revision 1.2  2005/05/28 01:45:24  cummings
// Updated all existing config_f77.h files to use a standardized naming scheme for the various known conventions for Fortran symbol translation.  The other names that had been used are still defined (so as to avoid breaking tons of existing code), but they are labeled with a comment as being obsolete.  Also added definitions for the pair of macros FORTRAN_NAME and FORTRAN_NAME_ that may be used to perform the appropriate symbol translation automatically.  Each macro takes two arguments: the lowercase version of the original symbol and the uppercase version.  The second macro FORTRAN_NAME_ is to be used when the original symbol contains an underscore within the name (i.e., get_data).  You may find these macros more convenient for providing Fortran name mangling than handling all the various F77EXTERNS_ cases.
//
// Revision 1.1  2000/04/27 19:06:10  aivazis
// Mixed language improvements
//
*/

#if !defined(__config_f77_h__)
#define __config_f77_h__

#define NEEDS_F77_TRANSLATION
#define F77EXTERNS_LOWERCASE_NOTRAILINGBAR

/* Macros to perform proper name mangling */
#define FORTRAN_NAME(x,y) x
#define FORTRAN_NAME_(x,y) x

/* Obsolete name for this mangling scheme */
#define F77EXTERNS_NOTRAILINGBAR

#endif

/* End of file */
