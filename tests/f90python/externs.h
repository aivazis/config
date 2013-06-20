/* -*- C -*-
 *
 * ---------------------------------------------------------------------------
 *
 *                              Julian C. Cummings
 *                       California Institute of Technology
 *                          (C) 2000-2005 All Rights Reserved
 *
 * <LicenseText>
 *
 * ---------------------------------------------------------------------------
 *
 */

#if !defined(externs_h)
#define externs_h

#if defined(F77EXTERNS_LOWERCASE_TRAILINGBAR)

/* This is the default. No translation */

#elif defined(F77EXTERNS_LOWERCASE_NOTRAILINGBAR)

#define hello_ hello

#elif defined(F77EXTERNS_UPPERCASE_TRAILINGBAR)

#define hello_ HELLO_

#elif defined(F77EXTERNS_UPPERCASE_NOTRAILINGBAR)

#define hello_ HELLO

#elif defined(F77EXTERNS_LOWERCASE_EXTRATRAILINGBAR)

/*
    This symbol does not contain "_" in its name and therefore requires no extra trailingbar and no translation
     hello_
*/

#else
#error Unknown translation for FORTRAN external symbols
#endif

/* The declarations */
#if defined(__cplusplus)
extern "C" {
#endif

void hello_();

#if defined(__cplusplus)
}
#endif

#endif /* EXTERNS_H */

/* Version */
/* $Id: */

/* End of file */

