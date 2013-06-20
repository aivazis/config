#--------------------------------------------------------------------------
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# local makefile
include local.def

PROJECT = test
PROJ_CXX_LIB = $(BLD_LIBDIR)/$(PROJECT).$(EXT_LIB)
PROJ_TMPDIR = $(BLD_TMPDIR)/projlib

PROJ_SRCS = \
    f77_hello.F \
    c_hello.c \
    cpp_hello.cc

all: proj-cxx-lib hello

ifeq (tau, ${findstring tau, $(BLD_USER_TARGET)})
hello:	$(PROJ_CXX_LIB)
	$(PDTCXXPARSE) main.cc $(CXX_BUILD_DEFINES) $(CXX_BUILD_INCLUDES) \
	$(TAU_INCLUDE) $(TAU_DEFS)
	$(TAUINSTR) main.pdb main.cc -o main.inst.cc
	$(TAU_CXX) $(CXXFLAGS) -c main.inst.cc
	$(TAU_CXX) -o $(BLD_BINDIR)/hello main.inst.o \
	$(PROJ_CXX_LIB) $(LCXXFLAGS) $(LCXX_FORTRAN)
	$(RM) $(RMFLAGS) main.inst.o main.pdb main.inst.cc
	$(BLD_BINDIR)/hello
else
hello:	$(PROJ_CXX_LIB)
	$(CXX) -o $(BLD_BINDIR)/hello main.cc $(CXXFLAGS) \
	$(PROJ_CXX_LIB) $(LCXXFLAGS) $(LCXX_FORTRAN)
	$(BLD_BINDIR)/hello
endif

project: show-project


#
# End of file
