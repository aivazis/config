# -*- Makefile -*-
#
#--------------------------------------------------------------------------
#
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

#
# Local makefile

include local.def

#
PROJECT = pyf90
PACKAGE =

BLD_BINDIR = .
PROJ_SAR = $(BLD_LIBDIR)/lib$(PROJECT).$(EXT_SAR)
PROJ_DLL = $(BLD_BINDIR)/$(PROJECT)module.$(EXT_SO)
PROJ_CLEAN += $(PROJ_DLL) $(PROJ_SAR)


PROJ_SRCS = \
    hello.$(EXT_F77)

MODINIT = $(PROJECT).cc

LIBRARIES = $(DEV_LCXX_LIBRARIES) $(EXTERNAL_LIBS) $(COMPILER_LCXX_FORTRAN)

all: $(PROJ_SAR) proj-dll export

proj-dll: $(MODINIT)
	$(CXX) $(MODINIT) -o $(PROJ_DLL) $(CXXFLAGS) $(LCXX_SOFLAGS) \
	$(LCXXFLAGS) -l$(PROJECT) $(LIBRARIES)

export:: export-libraries export-binaries

EXPORT_LIBS = $(PROJ_SAR)
EXPORT_BINS = $(PROJ_DLL)
EXPORT_BINDIR = $(EXPORT_MODULEDIR)

# Version
# $Id: 

#
# End of file
