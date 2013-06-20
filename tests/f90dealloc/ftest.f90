SUBROUTINE ftest(i)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: i
  DOUBLE PRECISION, ALLOCATABLE :: dummy(:)
  INTEGER k

  ALLOCATE ( dummy(1:i) )
  DO k=1,i
     dummy(k) = DSIN(DBLE(k))
  END DO
  DEALLOCATE (dummy)

END SUBROUTINE ftest

SUBROUTINE ftest_2(i)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: i
  DOUBLE PRECISION, ALLOCATABLE :: dummy(:)
  INTEGER k

  ALLOCATE ( dummy(1:i) )
  DO k=1,i
     dummy(k) = DCOS(DBLE(k))
  END DO
  DEALLOCATE (dummy)

END SUBROUTINE ftest_2

