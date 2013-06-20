#--------------------------------------------------------------------------
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: Make.mm,v $
# Revision 1.2  1999/11/17 16:32:23  aivazis
# Added headers and a new test file
#

#
# Test makefile
#

# Print the current configuration

include local.def

all: show-configuration c-configuration cpp-configuration fortran-configuration

c: c-configuration

cpp: cpp-configuration

fortran: fortran-configuration

test-d:
	$(MM) -f depends.def

#
# End of file
