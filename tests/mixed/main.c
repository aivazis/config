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

// $Log: main.c,v $
// Revision 1.5  2005/05/28 01:56:09  cummings
// Updated all config tests involving mixed-language code to use the proper macros for Fortran name mangling.  Also made sure that Python tests build shared archives correctly under Darwin.
//
// Revision 1.4  2000/08/14 23:51:16  cummings
// Added F77 to C symbol translation for the cases of all uppercase letters
// with or without a trailing underbar.
//
// Revision 1.3  2000/08/14 22:53:28  aivazis
// Populated the symbol translation section a bit more
//
// Revision 1.2  2000/08/09 17:35:13  aivazis
// Added another test case
//
// Revision 1.1  2000/08/08 21:01:32  aivazis
// Original source
//
*/

#include <portinfo.h>

/* Symbol translation */
#if defined(NEEDS_F77_TRANSLATION)

#if defined(F77EXTERNS_LOWERCASE_TRAILINGBAR)
/*
 * This is the default naming convention for us.
 * No translation necessary
 */
#elif defined(F77EXTERNS_LOWERCASE_NOTRAILINGBAR)
#define func_ func
#define func_2_ func_2

#elif defined(F77EXTERNS_UPPERCASE_TRAILINGBAR)
#define func_ FUNC_
#define func_2_ FUNC_2_

#elif defined(F77EXTERNS_UPPERCASE_NOTRAILINGBAR)
#define func_ FUNC
#define func_2_ FUNC_2

#elif defined(F77EXTERNS_LOWERCASE_EXTRATRAILINGBAR)
#define func_ func_
#define func_2_ func_2__

#else
#error Unknown translation for FORTRAN external symbols
#endif

#endif

void func_();
void func_2_();

int main()
{
    func_();
    func_2_();
    
    return 0;
}

/* End of file */
