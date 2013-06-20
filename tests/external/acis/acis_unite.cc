// -*- C++ -*-
//
//--------------------------------------------------------------------------------
//
//                              Michael A.G. Aivazis
//                       California Institute of Technology
//                          (C) 2000 All Rights Reserved
//
// <LicenseText>
//
//--------------------------------------------------------------------------------
//
// $Log: acis_unite.cc,v $
// Revision 1.1  2000/09/17 05:33:23  aivazis
// Original source
//

#include <portinfo>
#include <iostream>

#include "acis_unite.h"

int main()
{
    outcome check_start = api_start_modeller(0);
    if (!check_start.ok()) {
        cerr << "Could not start ACIS" << endl;
        return 1;
    }
    outcome check_kernel = api_initialize_kernel();
    if (!check_kernel.ok()) {
        cerr << "Could not start the ACIS kernel" << endl;
        return 0;
    }

    outcome check_spline = api_initialize_spline();
    if (!check_spline.ok()) {
        cerr << "Could not start the ACIS spline" << endl;
        return 0;
    }

    outcome check_constructors = api_initialize_constructors();
    if (!check_constructors.ok()) {
        cerr << "Could not start the ACIS constructors" << endl;
        return 0;
    }

    outcome check_booleans = api_initialize_booleans();
    if (!check_booleans.ok()) {
        cerr << "Could not start the ACIS booleans" << endl;
        return 0;
    }

    position top(0,0,20);
    position bottom(0,0,0);

    cerr << "Creating a cone" << endl;
    BODY * cone = 0;
    outcome check_cone = api_solid_cylinder_cone(bottom, top, 50, 50, 20, 0, cone);
    if (!check_cone.ok()) {
        cerr << "cone: error " << check_cone.error_number() 
             << ": " << find_err_mess(check_cone.error_number())
             << endl;
        return 0;
    }

    cerr << "Creating a cylinder" << endl;
    BODY * cylinder = 0;
    outcome check_cylinder = api_solid_cylinder_cone(bottom, top, 50, 50, 50, 0, cylinder);
    if (!check_cylinder.ok()) {
        cerr << "cylinder: error " << check_cylinder.error_number() 
             << ": " << find_err_mess(check_cylinder.error_number())
             << endl;
        return 0;
    }

    cerr << "Uniting the cone with the cylinder" << endl;
    outcome check_union = api_unite(cone, cylinder);
    if (!check_union.ok()) {
        cerr << "union: error " << check_union.error_number() 
             << ": " << find_err_mess(check_union.error_number())
             << endl;
        return 0;
    }

    return 0;
}

// End of file
