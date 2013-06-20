// -*- C++ -*-
//
// ---------------------------------------------------------------------------
//
//                              Michael A.G. Aivazis
//                       California Institute of Technology
//                          (C) 2000-2005 All Rights Reserved
//
// <LicenseText>
//
// ---------------------------------------------------------------------------
//


#include <portinfo>

#include "Python.h"
#include "externs.h"


// The method table
extern struct PyMethodDef pyf90_methods[];

// The binding
extern char pyf90_hello__doc__[];
PyObject * pyf90_hello(PyObject *, PyObject *);

// Initialization function for the module (*must* be called initpyf90)
char pyf90_module__doc__[] = "";

extern "C" void initpyf90 ()
{
// Create the module and add the functions
    PyObject *m = 
        Py_InitModule4("pyf90", pyf90_methods, pyf90_module__doc__, 0, PYTHON_API_VERSION);

// Check for errors //
    if (PyErr_Occurred()) {
        Py_FatalError("can't initialize module pyf90");
    }

// Finished
    return;
}

// The method table 

struct PyMethodDef pyf90_methods[] = {
// The methods
    {"hello", pyf90_hello, METH_VARARGS, pyf90_hello__doc__},
   
// Sentinel
    {0, 0}
};


char pyf90_hello__doc__[] = "";

PyObject * pyf90_hello(PyObject * self, PyObject *args)
{
    printf("    Hello from the binding\n");

    hello_();

    Py_INCREF(Py_None);
    return Py_None;
}

// Version
// $Id: 

// End of file
