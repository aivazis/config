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

// $Log: config_compiler.h,v $
// Revision 1.4  2001/12/07 03:08:24  cummings
// I removed the hack which opened and closed namespace std if we are
// using the tau option.  The kai header files within the pdtoolkit
// have been fixed, so this hack is no longer needed.
//
// Revision 1.3  2001/11/28 23:07:10  cummings
// Added line to create the std namespace if it does not already exist when
// building with the tau option.  This avoids a bug in some of the kai header
// files that are used with the pdtoolkit C++ parser.  For some reason, a
// few of KAI's C standard header files do not place things in namespace std
// as they should.  Therefore you can run into a situation where the std
// namespace has not yet been established.  I ran into this problem with our
// source code file firewall.cc, which includes <cstdarg> and expects to find
// the type va_list defined in namespace std.
//
// Revision 1.2  2001/11/10 02:14:26  cummings
// Added check that we are not using Tau before defining the HAVE__FUNC__
// macro, since this causes some problems for the Tau parser.
//
// Revision 1.1  2001/07/11 02:07:26  cummings
// Build procedure files for new gcc 3.0 compiler, borrowed from gcc-2.95.2.  I have removed the *using namespace std* hack from the config_compiler.h file here.
//
//
*/

#if !defined(__config_compiler_h__)
#define __config_compiler_h__

#include <config_f77.h>

#if !defined(WITH_TAU)
/* The gcc preprocessor defines __FUNC__ */
#define HAVE__FUNC__
#endif

#endif

/* End of file */
