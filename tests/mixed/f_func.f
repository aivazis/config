c
c -*- FORTRAN -*-
c--------------------------------------------------------------------------
c
c
c                       Michael A.G. Aivazis
c                California Institute of Technology
c                   (C) 1999 All Rights Reserved
c
c--------------------------------------------------------------------------

c $Log: f_func.f,v $
c Revision 1.1  2000/08/09 23:01:05  aivazis
c Original source
c
c Revision 1.2  2000/08/09 17:35:03  aivazis
c Added another test case
c
c Revision 1.1  2000/08/08 21:01:59  aivazis
c Original source
c

      subroutine func()

      print *, "Hello from a FORTRAN function"

      return
      end

c A routine with an underbar in its name
c Some compilers (Compaq F90) behave differently when the symbol already
c contains an underbar

      subroutine func_2()

      print *, "Hello from another FORTRAN function"

      return
      end

c End of file
