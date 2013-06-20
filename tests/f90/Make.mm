#--------------------------------------------------------------------------
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# Fortran 90
include std-f90.def

PROJECT = test
PROJ_CLEAN = $(PROJ_BIN)
PROJ_DISTCLEAN = 

PROJ_BIN = hello

all: hello

hello:	hello.f
	$(F77) $(F77FLAGS) $(LF77FLAGS) hello.f -o $(PROJ_BIN)
	$(PROJ_BIN)


#
# End of file
