/*
// -*- C -*-
//
//                       Michael A.G. Aivazis
//                California Institute of Technology
//                   (C) 1999 All Rights Reserved
//

// $Log: portinfo.h,v $
// Revision 1.3  1999/06/20 16:32:06  aivazis
// Added header
//
*/

#if !defined(__config_portinfo_h__)
#define __config_portinfo_h__

#include <config_platform.h>
#include <config_compiler.h>

#include "config_local.h"

/* The default Fortran compiler requires changes to the names of FORTRAN externals */
#define RENAME_FORTRAN_EXTERNALS

/* FORTRAN externals are upper case, no trailing nderscore */
#define FORTRAN_EXTERNALS_UC_NOU

#endif

/* End of file */
