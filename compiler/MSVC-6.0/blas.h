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

// $Log: blas.h,v $
// Revision 1.3  1999/10/20 21:03:23  mga
// Added some missing translations (possibly do not belong here)
//
// Revision 1.2  1999/10/20 18:33:29  mga
// Fixed a typo
//
// Revision 1.1  1999/10/20 18:31:18  mga
// Original source
//

*/

/*
    This file contains symbol translations from libblas
    They are resolved against MKL_I.dll from intel
*/

#if !defined(__CONFIG_BLAS_H__)
#define __CONFIG_BLAS_H__

#define ddot_ DDOT
#define daxpy_ DAXPY
#define dcopy_ DCOPY
#define dgemv_ DGEMV
#define dgemm_ DGEMM
#define dswap_ DSWAP
#define dscal_ DSCAL
#define drot_ DROT
#define dger_ DGER
#define dtrmm_ DTRMM
#define dtrsm_ DTRSM
#define dnrm2_ DNRM2
#define dtrmv_ DTRMV
#define idamax_ IDAMAX
#define saxpy_ SAXPY
#define sscal_ SSCAL
#define isamax_ ISAMAX
#define dasum_ DASUM
#define sasum_ SASUM
#define sswap_ SSWAP
#define sdot_ SDOT
#define scopy_ SCOPY

#define dgelss_ DGELSS
#define dgetrs_ DGETRS
#define dgetrf_ DGETRF

#endif

/* End of file */
