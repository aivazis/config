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

#include <Python.h>
#include "Singleton.h"

// bindings

char pyb_set__doc__[] = "";
char pyb_set__name__[] = "set";
extern "C" PyObject * pyb_set(PyObject *, PyObject * args)
{
    int value;

    int ok = PyArg_ParseTuple(args, "i:set", &value);

    if (!ok) {
	return 0;
    }

    Singleton::set(value);

    // return 
    Py_INCREF(Py_None);
    return Py_None;
}

char pyb_get__doc__[] = "";
char pyb_get__name__[] = "get";
extern "C" PyObject * pyb_get(PyObject *, PyObject * args)
{
    // return 
    return Py_BuildValue("i", Singleton::get());
}

// binding table

struct PyMethodDef pyb_methods[] = {

    // bindings
    {pyb_set__name__, pyb_set, METH_VARARGS, pyb_set__doc__},
    {pyb_get__name__, pyb_get, METH_VARARGS, pyb_get__doc__},
    // sentinel
    {0, 0}
};


// initialization function for the module (*must* be called initpyb)
char pyb_module__doc__[] = "";

extern "C" void initpyb()
{
// create the module and add the functions
    Py_InitModule4("pyb", pyb_methods, pyb_module__doc__, 0, PYTHON_API_VERSION);

// check for errors
    if (PyErr_Occurred()) {
        Py_FatalError("can't initialize module pyb");
    }

    return;
}

// $Id: pyb.cc,v 1.2 2003/04/08 21:42:27 steve Exp $

// End of file
