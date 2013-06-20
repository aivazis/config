#!/usr/bin/env python
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
#                             Michael A.G. Aivazis
#                      California Institute of Technology
#                      (C) 1998-2008  All Rights Reserved
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#

import os, string, sys

PYTHON_LIBDIR = '$(PYTHON_EXECDIR)/lib/python$(PYTHON_VERSION)'
PYTHON_LCXX_FLAGS = ''
PYTHON_LIB = '$(PYTHON_LIBDIR)/config/libpython$(PYTHON_VERSION).$(EXT_AR)'

PYTHON_SYSCONFIG_APIREQS = None

try:
    from distutils.sysconfig import get_config_var, get_python_inc
    PYTHON_INCDIR = get_python_inc()
    PYTHON_LIBDIR = get_config_var('LIBP') or PYTHON_LIBDIR
    PYTHON_SYSCONFIG_APIREQS = get_config_var('LIBS') or PYTHON_SYSCONFIG_APIREQS # Add SHLIBS, SYSLIBS?
    staticLibPython = "%s/%s" % (get_config_var('LIBPL'), get_config_var('LIBRARY'))
    if (os.path.isfile(staticLibPython)):
        PYTHON_LIB = staticLibPython
    else:
        PYTHON_LCXX_FLAGS = get_config_var('LINKFORSHARED') or PYTHON_LCXX_FLAGS
        PYTHON_LIB = get_config_var('BLDLIBRARY') or '' # default intentionally blank (for Mac OS X)
except:
    PYTHON_INCDIR = '$(PYTHON_DIR)/include/python$(PYTHON_VERSION)'
    # PYTHON_SYSCONFIG_APIREQS will assume hard-coded default under config/external/Python

pythonMacros = [
    ('PYTHON',            sys.executable),
    ('PYTHON_DIR',        sys.prefix),
    ('PYTHON_EXECDIR',    sys.exec_prefix),
    ('PYTHON_VERSION',    sys.version.split()[0][0:3]),
    ('PYTHON_INCDIR',     PYTHON_INCDIR),
    ('PYTHON_LIBDIR',     PYTHON_LIBDIR),
    ('PYTHON_SCRIPTDIR',  '$(PYTHON_LIBDIR)'),
    ('PYTHON_BINDIR',     '$(PYTHON_EXECDIR)/bin'),
    ('PYTHON_LCXX_FLAGS', PYTHON_LCXX_FLAGS),
    ('PYTHON_LIB',        PYTHON_LIB),
]

if (PYTHON_SYSCONFIG_APIREQS):
    pythonMacros.append(('PYTHON_SYSCONFIG_APIREQS', PYTHON_SYSCONFIG_APIREQS))

for variable, value in pythonMacros:
    print ("%s = %s" % (variable, value))

# end of file
