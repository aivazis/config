#--------------------------------------------------------------------------
#                         Ralf Deiterding
#                California Institute of Technology
#                   (C) 2004 All Rights Reserved
#
#--------------------------------------------------------------------------


PROJECT = f90dealloc
PROJ_BIN = $(BLD_BINDIR)/f90dealloc
EXT_CXX = C
# F90
include std-f90.def
EXT_F77 = f90
PROJ_SRCS = ftest.$(EXT_F77) main.$(EXT_CXX)

PROJ_CLEAN += $(PROJ_BIN) 

all: $(PROJ_BIN)

$(PROJ_BIN): $(BLD_BINDIR) $(PROJ_OBJS) 
	$(CXX) $(LCXXFLAGS) -o $@ $(PROJ_OBJS) $(LCXX_FORTRAN)

# version
# $Id: Make.mm,v 1.3 2004/02/06 00:01:28 cummings Exp $

#
# End of file
