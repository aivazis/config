/*

 *                       Michael A.G. Aivazis
 *                California Institute of Technology
 *                   (C) 1999 All Rights Reserved
 *

 * Automatically generated platform-specific macros
 *
 * $Log: autoconfig.h,v $
 * Revision 1.4  2001/05/09 16:36:03  aivazis
 * Removed sizeof macros to accomodate 64/32 bit builds
 *
 * Revision 1.3  1999/07/04 01:03:35  aivazis
 * Added the end-of-file marker
 *
 * Revision 1.2  1999/06/23 18:25:08  aivazis
 * Removed WITH_MPI and WITH_PARALLEL_IO that were inadvertently checked in
 *
 * Revision 1.1  1999/06/18 23:11:59  aivazis
 * Split the automatically generated stuff into their own file
 *
 */


/* autoconfig.h.  Generated automatically by configure.  */

/* Define if type char is unsigned and you are not using gcc.  */
#ifndef __CHAR_UNSIGNED__
/* #undef __CHAR_UNSIGNED__ */
#endif

/* Define if you don't have tm_zone but do have the external array
   tzname.  */
#define HAVE_TZNAME 1

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define this if your time.h defines altzone */
#define HAVE_ALTZONE 1

/* Define this if you have some version of gethostbyname_r() */
#define HAVE_GETHOSTBYNAME_R 1

/* Define this if you have the 5-arg version of gethostbyname_r() */
#define HAVE_GETHOSTBYNAME_R_5_ARG 1

/* Define this if you have the type long long */
#define HAVE_LONG_LONG 1

/* Define if your compiler supports function prototypes */
#define HAVE_PROTOTYPES 1

/* Define if your compiler supports variable length function prototypes
   (e.g. void fprintf(FILE *, char *, ...);) *and* <stdarg.h> */
#define HAVE_STDARG_PROTOTYPES 1

/* Define if you have POSIX threads */
#define _POSIX_THREADS 1

/* Define to force use of thread-safe errno, h_errno, and other functions */
#define _REENTRANT 1

/* Define if  you can safely include both <sys/select.h> and <sys/time.h>
   (which you can't on SCO ODT 3.0). */
#define SYS_SELECT_WITH_SYS_TIME 1

/* Define if you want to compile in rudimentary thread support */
#define WITH_THREAD 1

/* The number of bytes in an off_t. */
#define SIZEOF_OFF_T 8

/* Defined to enable large file support when an off_t is bigger than a long
   and long long is available and at least as big as an off_t. You may need
   to add some flags for configuration and compilation to enable this mode.
   E.g, for Solaris 2.7:
   CFLAGS="-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64" OPT="-O2 $CFLAGS" \
 configure
*/
#define HAVE_LARGEFILE_SUPPORT 1

/* Define if you have the alarm function.  */
#define HAVE_ALARM 1

/* Define if you have the chown function.  */
#define HAVE_CHOWN 1

/* Define if you have the clock function.  */
#define HAVE_CLOCK 1

/* Define if you have the dlopen function.  */
#define HAVE_DLOPEN 1

/* Define if you have the dup2 function.  */
#define HAVE_DUP2 1

/* Define if you have the execv function.  */
#define HAVE_EXECV 1

/* Define if you have the fdatasync function.  */
#define HAVE_FDATASYNC 1

/* Define if you have the flock function.  */
#define HAVE_FLOCK 1

/* Define if you have the fork function.  */
#define HAVE_FORK 1

/* Define if you have the fseek64 function.  */
#define HAVE_FSEEK64 1

/* Define if you have the fseeko function.  */
#define HAVE_FSEEKO 1

/* Define if you have the fstatvfs function.  */
#define HAVE_FSTATVFS 1

/* Define if you have the fsync function.  */
#define HAVE_FSYNC 1

/* Define if you have the ftell64 function.  */
#define HAVE_FTELL64 1

/* Define if you have the ftello function.  */
#define HAVE_FTELLO 1

/* Define if you have the ftime function.  */
#define HAVE_FTIME 1

/* Define if you have the ftruncate function.  */
#define HAVE_FTRUNCATE 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define if you have the getpeername function.  */
#define HAVE_GETPEERNAME 1

/* Define if you have the getpgrp function.  */
#define HAVE_GETPGRP 1

/* Define if you have the getpid function.  */
#define HAVE_GETPID 1

/* Define if you have the getpwent function.  */
#define HAVE_GETPWENT 1

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the getwd function.  */
#define HAVE_GETWD 1

/* Define if you have the hypot function.  */
#define HAVE_HYPOT 1

/* Define if you have the kill function.  */
#define HAVE_KILL 1

/* Define if you have the link function.  */
#define HAVE_LINK 1

/* Define if you have the lstat function.  */
#define HAVE_LSTAT 1

/* Define if you have the memmove function.  */
#define HAVE_MEMMOVE 1

/* Define if you have the mkfifo function.  */
#define HAVE_MKFIFO 1

/* Define if you have the mktime function.  */
#define HAVE_MKTIME 1

/* Define if you have the nice function.  */
#define HAVE_NICE 1

/* Define if you have the pause function.  */
#define HAVE_PAUSE 1

/* Define if you have the plock function.  */
#define HAVE_PLOCK 1

/* Define if you have the pthread_init function.  */
/* #undef HAVE_PTHREAD_INIT */

/* Define if you have the putenv function.  */
#define HAVE_PUTENV 1

/* Define if you have the readlink function.  */
#define HAVE_READLINK 1

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the setgid function.  */
#define HAVE_SETGID 1

/* Define if you have the setlocale function.  */
#define HAVE_SETLOCALE 1

/* Define if you have the setpgid function.  */
#define HAVE_SETPGID 1

/* Define if you have the setpgrp function.  */
#define HAVE_SETPGRP 1

/* Define if you have the setsid function.  */
#define HAVE_SETSID 1

/* Define if you have the setuid function.  */
#define HAVE_SETUID 1

/* Define if you have the setvbuf function.  */
#define HAVE_SETVBUF 1

/* Define if you have the sigaction function.  */
#define HAVE_SIGACTION 1

/* Define if you have the siginterrupt function.  */
#define HAVE_SIGINTERRUPT 1

/* Define if you have the sigrelse function.  */
#define HAVE_SIGRELSE 1

/* Define if you have the statvfs function.  */
#define HAVE_STATVFS 1

/* Define if you have the strdup function.  */
#define HAVE_STRDUP 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the strftime function.  */
#define HAVE_STRFTIME 1

/* Define if you have the strptime function.  */
#define HAVE_STRPTIME 1

/* Define if you have the symlink function.  */
#define HAVE_SYMLINK 1

/* Define if you have the tcgetpgrp function.  */
#define HAVE_TCGETPGRP 1

/* Define if you have the tcsetpgrp function.  */
#define HAVE_TCSETPGRP 1

/* Define if you have the times function.  */
#define HAVE_TIMES 1

/* Define if you have the truncate function.  */
#define HAVE_TRUNCATE 1

/* Define if you have the uname function.  */
#define HAVE_UNAME 1

/* Define if you have the waitpid function.  */
#define HAVE_WAITPID 1

/* Define if you have the <dirent.h> header file.  */
#define HAVE_DIRENT_H 1

/* Define if you have the <dlfcn.h> header file.  */
#define HAVE_DLFCN_H 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <locale.h> header file.  */
#define HAVE_LOCALE_H 1

/* Define if you have the <pthread.h> header file.  */
#define HAVE_PTHREAD_H 1

/* Define if you have the <signal.h> header file.  */
#define HAVE_SIGNAL_H 1

/* Define if you have the <stdarg.h> header file.  */
#define HAVE_STDARG_H 1

/* Define if you have the <stddef.h> header file.  */
#define HAVE_STDDEF_H 1

/* Define if you have the <stdlib.h> header file.  */
#define HAVE_STDLIB_H 1

/* Define if you have the <sys/file.h> header file.  */
#define HAVE_SYS_FILE_H 1

/* Define if you have the <sys/lock.h> header file.  */
#define HAVE_SYS_LOCK_H 1

/* Define if you have the <sys/param.h> header file.  */
#define HAVE_SYS_PARAM_H 1

/* Define if you have the <sys/select.h> header file.  */
#define HAVE_SYS_SELECT_H 1

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <sys/times.h> header file.  */
#define HAVE_SYS_TIMES_H 1

/* Define if you have the <sys/un.h> header file.  */
#define HAVE_SYS_UN_H 1

/* Define if you have the <sys/utsname.h> header file.  */
#define HAVE_SYS_UTSNAME_H 1

/* Define if you have the <sys/wait.h> header file.  */
#define HAVE_SYS_WAIT_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <utime.h> header file.  */
#define HAVE_UTIME_H 1

/* Define if you have the dl library (-ldl).  */
#define HAVE_LIBDL 1

/* End of file */
