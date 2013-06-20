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
//
*/

#if !defined(__config_compiler_h__)
#define __config_compiler_h__

#include <config_f77.h>

#if !defined(WITH_TAU)
/* The preprocessor defines __FUNC__ */
#define HAVE__FUNC__
#endif

#ifndef __cplusplus
/* IBM C compiler recognizes __inline as a keyword. */
#define inline __inline
#endif

#endif

/* End of file */
