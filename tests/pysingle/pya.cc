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

char pya_set__doc__[] = "";
char pya_set__name__[] = "set";
extern "C" PyObject * pya_set(PyObject *, PyObject * args)
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

char pya_get__doc__[] = "";
char pya_get__name__[] = "get";
extern "C" PyObject * pya_get(PyObject *, PyObject * args)
{
    // return 
    return Py_BuildValue("i", Singleton::get());
}

// binding table

struct PyMethodDef pya_methods[] = {

    // bindings
    {pya_set__name__, pya_set, METH_VARARGS, pya_set__doc__},
    {pya_get__name__, pya_get, METH_VARARGS, pya_get__doc__},
    // sentinel
    {0, 0}
};


// initialization function for the module (*must* be called initpya)
char pya_module__doc__[] = "";

extern "C" void initpya()
{
// create the module and add the functions
    Py_InitModule4("pya", pya_methods, pya_module__doc__, 0, PYTHON_API_VERSION);

// check for errors
    if (PyErr_Occurred()) {
        Py_FatalError("can't initialize module pya");
    }

    return;
}

// $Id: pya.cc,v 1.2 2003/04/08 21:42:27 steve Exp $

// End of file
