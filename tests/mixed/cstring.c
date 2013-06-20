/*
//
// -*- C -*-
//--------------------------------------------------------------------------
//
//
//                       Michael A.G. Aivazis
//                California Institute of Technology
//                   (C) 2000 All Rights Reserved
//
//--------------------------------------------------------------------------

// $Log: cstring.c,v $
// Revision 1.6  2005/05/28 01:56:09  cummings
// Updated all config tests involving mixed-language code to use the proper macros for Fortran name mangling.  Also made sure that Python tests build shared archives correctly under Darwin.
//
// Revision 1.5  2004/05/06 15:07:56  aivazis
// Simplified the test
//
// Revision 1.4  2000/08/14 23:51:16  cummings
// Added F77 to C symbol translation for the cases of all uppercase letters
// with or without a trailing underbar.
//
// Revision 1.3  2000/08/14 22:53:12  aivazis
// Populated the symbol translation section a bit more
//
// Revision 1.2  2000/08/10 00:55:49  aivazis
// Added the translation section
// Improved the trailing info dump
//
// Revision 1.1  2000/08/09 22:57:15  aivazis
// Original source
//
 
*/
#include <portinfo.h>
#include <stdio.h>
#include <string.h>

/* Symbol translation */
#if defined(NEEDS_F77_TRANSLATION)

#if defined(F77EXTERNS_LOWERCASE_TRAILINGBAR)
/*
 * This is the default naming convention for us.
 * No translation necessary
 */
#elif defined(F77EXTERNS_LOWERCASE_NOTRAILINGBAR)
#define cget_string_ cget_string
#define fsend_string_ fsend_string

#elif defined(F77EXTERNS_UPPERCASE_TRAILINGBAR)
#define cget_string_ CGET_STRING_
#define fsend_string_ FSEND_STRING_

#elif defined(F77EXTERNS_UPPERCASE_NOTRAILINGBAR)
#define cget_string_ CGET_STRING
#define fsend_string_ FSEND_STRING

#elif defined(F77EXTERNS_LOWERCASE_EXTRATRAILINGBAR)
#define cget_string_ cget_string__
#define fsend_string_ fsend_string__

#else
#error Unknown translation for FORTRAN external symbols
#endif

#endif

/* Prototype for the FORTRAN string */
void fsend_string_();

void cget_string_(void * s, int len)
{
    int i;
    char buffer[8];
    char * alias = (char *)s;
    
    printf(" >> in cget_string\n");
    printf("      len: %d\n", len);
    printf("      bytes: ");
    for (i=0; i<10; ++i) {
        printf("{%02x}", alias[i]);
    }
    printf("\n");
    
/* The string is supposed to be "FORTRAN" */
/* Try to see whether it starts at the passed address */
    
    memcpy(buffer, s, 8);
    buffer[7] = 0;
    printf("      string: {%s}\n", buffer);
    
    return;
}

int main()
{
    fsend_string_();
    
    return 0;
}

/* End of file */
