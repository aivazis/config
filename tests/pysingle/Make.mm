# -*- Makefile -*-
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
#                               Michael A.G. Aivazis
#                        (C) 1998-2018  All Rights Reserved
#
# <LicenseText>
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#

include local.def

PROJECT = pysingle
PACKAGE = 

LIBS = $(EXTERNAL_LIBS)
BLIBS = -L. -lsingle $(EXTERNAL_LIBS)

PROJ_SAR = libsingle.$(EXT_SAR)
PROJ_DLL = pysinglemodule.$(EXT_SO)
PROJ_CLEAN += $(PROJ_SAR) $(PROJ_DLL) pya.$(EXT_SO) pyb.$(EXT_SO) *~ core


all: pya.$(EXT_SO) pyb.$(EXT_SO)


PROJ_SRCS = Singleton.$(EXT_CXX)


pya.$(EXT_SO): $(PROJ_SAR)
	$(CXX) pya.cc -o pya.$(EXT_SO) $(CXXFLAGS) $(LCXX_SOFLAGS) $(LCXXFLAGS) $(BLIBS)


pyb.$(EXT_SO): $(PROJ_SAR)
	$(CXX) pyb.cc -o pyb.$(EXT_SO) $(CXXFLAGS) $(LCXX_SOFLAGS) $(LCXXFLAGS) $(BLIBS)


test: pya.$(EXT_SO) pyb.$(EXT_SO)
	@LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:`pwd` python stest.py



# id
# $Id: Make.mm,v 1.5 2005/05/28 01:56:09 cummings Exp $

# End of file
