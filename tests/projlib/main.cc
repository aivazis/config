// -*- C++ -*-
//--------------------------------------------------------------------------
//
//
//                       Michael A.G. Aivazis
//                California Institute of Technology
//                   (C) 1999 All Rights Reserved
//
//--------------------------------------------------------------------------
//

#include <portinfo>

/* Symbol translation */
#if defined(NEEDS_F77_TRANSLATION)

#if defined(F77EXTERNS_LOWERCASE_TRAILINGBAR)
#define f77_hello f77_hello_

#elif defined(F77EXTERNS_LOWERCASE_NOTRAILINGBAR)
/*
 * This is the default naming convention for us.
 * No translation necessary
 */
#elif defined(F77EXTERNS_UPPERCASE_TRAILINGBAR)
#define f77_hello F77_HELLO_

#elif defined(F77EXTERNS_UPPERCASE_NOTRAILINGBAR)
#define f77_hello F77_HELLO

#elif defined(F77EXTERNS_LOWERCASE_EXTRATRAILINGBAR)
#define f77_hello f77_hello__

#else
#error Unknown translation for FORTRAN external symbols
#endif

#endif

extern "C" {
void f77_hello();
void c_hello();
}
void cpp_hello();

int main()
{
    f77_hello();
    c_hello();
    cpp_hello();
    return 0;
}

/* End of file */
