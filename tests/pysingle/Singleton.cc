// -*- C++ -*-
//
//-----------------------------------------------------------------------------
//
//                              Michael A.G. Aivazis
//                       (C) 1998-2001  All Rights Reserved
//
// <LicenseText>
//
//-----------------------------------------------------------------------------
//

#include <portinfo>

#include "Singleton.h"

int Singleton::_count = 0;


void Singleton::set(int value) {
    _count = value;
    return;
}


int Singleton::get() {
    return _count;
}


// $Id: Singleton.cc,v 1.1 2001/09/08 18:23:41 aivazis Exp $

// End of file
