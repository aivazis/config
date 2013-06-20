//
//
//                      Michael A.G. Aivazis
//               California Institute of Technology
//                  (C) 1999 All Rights Reserved
//

// $Log: cpp_hello.cc,v $
// Revision 1.3  2001/09/26 20:23:17  cummings
// Added missing std:: qualifier.
//
// Revision 1.2  2000/08/31 21:53:24  cummings
// Cosmetic changes to make output look more similar to C code output.
//
// Revision 1.1  1999/11/27 00:46:42  aivazis
// Original source
//

#include <portinfo>

#include <iostream>

#include "include.h"

void cpp_hello()
{
    std::cout << "Hello C++ world!" << std::endl;
    return;
}

/* End of file */
