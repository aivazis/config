#--------------------------------------------------------------------------
#                       Michael A.G. Aivazis
#                California Institute of Technology
#                   (C) 1999 All Rights Reserved
#
#--------------------------------------------------------------------------

# $Log: Make.mm,v $
# Revision 1.4  2000/08/14 23:52:49  cummings
# Removed main.o and cstring.o from the $(RM) command lines, since these
# .o files are never actually produced.
#
# Revision 1.3  2000/08/14 22:59:28  aivazis
# Renamed the targets to match the executables. Added clean
#
# Revision 1.2  2000/08/09 22:57:33  aivazis
# Added a string example
#
# Revision 1.1  2000/08/08 21:02:07  aivazis
# Original source
#

PROJECT = test
PROJ_CLEAN = $(PROJ_BIN) *~ *.o

PROJ_BIN = c_f77 cstring

all: $(PROJ_BIN)

c_f77:
	$(F77) -c $(F77FLAGS) f_func.f
	$(CC) $(CFLAGS) main.c f_func.o -o c_f77 $(COMPILER_LCC_FORTRAN)
	-$(RM) f_func.o
	c_f77

cstring:
	$(F77) -c $(F77FLAGS) fstring.f
	$(CC) $(CFLAGS) cstring.c fstring.o -o cstring $(COMPILER_LCC_FORTRAN)
	-$(RM) fstring.o
	cstring


#
# End of file
