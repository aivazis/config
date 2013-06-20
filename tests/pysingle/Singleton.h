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

class Singleton {

public:

    static int get();
    static void set(int);

private:

    static int _count;
};

// $Id: Singleton.h,v 1.1 2001/09/08 18:23:41 aivazis Exp $

// End of file
