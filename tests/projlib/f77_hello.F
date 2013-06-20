C
C
C                      Michael A.G. Aivazis
C               California Institute of Technology
C                  (C) 1999 All Rights Reserved
C

C     $Log: f77_hello.F,v $
C     Revision 1.3  2001/10/25 21:22:14  cummings
C     Removed include file, since this C-style include file cannot be safely
C     included within F90 source code.  There is no point in having this here
C     anyway, since we do not generate dependency information for F90 sources.
C
C     Revision 1.2  2000/08/31 21:53:24  cummings
C     Cosmetic changes to make output look more similar to C code output.
C
C     Revision 1.1  2000/08/31 04:48:00  aivazis
C     Original source
C

      SUBROUTINE f77_hello()
      WRITE(*,5)
 5    FORMAT('Hello F77 world!')
      RETURN
      END

C     End of file
