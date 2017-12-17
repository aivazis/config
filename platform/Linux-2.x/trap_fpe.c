//
// Function to enable core dumps on floating point exceptions
//

// $Log: trap_fpe.c,v $
// Revision 1.1  2000/01/15 23:19:03  aivazis
// Original source
//

#include <fpu_control.h>

void trap_fpe()
{
    fpu_control_t fpucw = __fpu_control;
    _FPU_SETCW(fpucw & ~(_FPU_MASK_OM | _FPU_MASK_IM | _FPU_MASK_DM));
    
    return;
}

#if defined(__MAIN__)
#include <math.h>

int main()
{
    double d;
/* trap_fpe(); Uncomment to get the core dump */
    
    d = sqrt(-1.0);
    return 0;
}
#endif

// End of file
