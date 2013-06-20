/*

 *                       Michael A.G. Aivazis
 *                California Institute of Technology
 *                   (C) 1999 All Rights Reserved
 *

 * Automatically generated platform-specific macros
 *
 * $Log: autoconfig.h,v $
 * Revision 1.3  2000/09/29 01:48:30  cummings
 * The config file was causing iostreams in the PGI pgCC compiler to
 * crash.  I reproduced this file using the current configure script
 * from Python 1.5.1, and removed the SIZEOF macros as aivazis had
 * done before.  This new version seems to make pgCC happy.
 *
 * Revision 1.2  2000/09/02 03:23:46  aivazis
 * Removed the SIZEOF_xxx macros since they were wrong for 64bit machines
 *
 * Revision 1.1  1999/08/30 16:01:31  aivazis
 * Original source
 *
 */

/* autoconfig.h.  Generated automatically by configure.  */

/* Define if on AIX 3.
   System headers sometimes define this.
   We just want to avoid a redefinition error message.  */
#ifndef _ALL_SOURCE
/* #undef _ALL_SOURCE */
#endif

/* Define if type char is unsigned and you are not using gcc.  */
#ifndef __CHAR_UNSIGNED__
/* #undef __CHAR_UNSIGNED__ */
#endif

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef gid_t */

/* Define if your struct tm has tm_zone.  */
#define HAVE_TM_ZONE 1

/* Define if you don't have tm_zone but do have the external array
   tzname.  */
/* #undef HAVE_TZNAME */

/* Define if on MINIX.  */
/* #undef _MINIX */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef mode_t */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef off_t */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define if the system does not provide POSIX.1 features except
   with this defined.  */
/* #undef _POSIX_1_SOURCE */

/* Define if you need to in order for stat and other things to work.  */
/* #undef _POSIX_SOURCE */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define if your <sys/time.h> declares struct tm.  */
/* #undef TM_IN_SYS_TIME */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef uid_t */

/* Define if your <unistd.h> contains bad prototypes for exec*()
   (as it does on SGI IRIX 4.x) */
/* #undef BAD_EXEC_PROTOTYPES */

/* Define if your compiler botches static forward declarations
   (as it does on SCI ODT 3.0) */
/* #undef BAD_STATIC_FORWARD */

/* Define if you have the Mach cthreads package */
/* #undef C_THREADS */

/* Define to `long' if <time.h> doesn't define.  */
/* #undef clock_t */

/* Define if getpgrp() must be called as getpgrp(0). */
/* #undef GETPGRP_HAVE_ARG */

/* Define if gettimeofday() does not have second (timezone) argument
   This is the case on Motorola V4 (R40V4.2) */
/* #undef GETTIMEOFDAY_NO_TZ */

/* Define this if your time.h defines altzone */
/* #undef HAVE_ALTZONE */

/* Define this if you have a K&R style C preprocessor */
/* #undef HAVE_OLD_CPP */

/* Define if your compiler supports function prototypes */
#define HAVE_PROTOTYPES 1

/* Define if your compiler supports variable length function prototypes
   (e.g. void fprintf(FILE *, char *, ...);) *and* <stdarg.h> */
#define HAVE_STDARG_PROTOTYPES 1

/* Define if malloc(0) returns a NULL pointer */
#define MALLOC_ZERO_RETURNS_NULL 1

/* Define if you have POSIX threads */
/* #undef _POSIX_THREADS */

/* Define to force use of thread-safe errno, h_errno, and other functions */
/* #undef _REENTRANT */

/* Define if setpgrp() must be called as setpgrp(0, 0). */
/* #undef SETPGRP_HAVE_ARG */

/* Define to empty if the keyword does not work.  */
/* #undef signed */

/* Define if  you can safely include both <sys/select.h> and <sys/time.h>
   (which you can't on SCO ODT 3.0). */
#define SYS_SELECT_WITH_SYS_TIME 1

/* Define if a va_list is an array of some kind */
/* #undef VA_LIST_IS_ARRAY */

/* Define to empty if the keyword does not work.  */
/* #undef volatile */

/* Define if you want SIGFPE handled (see Include/pyfpe.h). */
/* #undef WANT_SIGFPE_HANDLER */

/* Define if you want to use SGI (IRIX 4) dynamic linking.
   This requires the "dl" library by Jack Jansen,
   ftp://ftp.cwi.nl/pub/dynload/dl-1.6.tar.Z.
   Don't bother on IRIX 5, it already has dynamic linking using SunOS
   style shared libraries */ 
/* #undef WITH_SGI_DL */

/* Define if you want to emulate SGI (IRIX 4) dynamic linking.
   This is rumoured to work on VAX (Ultrix), Sun3 (SunOS 3.4),
   Sequent Symmetry (Dynix), and Atari ST.
   This requires the "dl-dld" library,
   ftp://ftp.cwi.nl/pub/dynload/dl-dld-1.1.tar.Z,
   as well as the "GNU dld" library,
   ftp://ftp.cwi.nl/pub/dynload/dld-3.2.3.tar.Z.
   Don't bother on SunOS 4 or 5, they already have dynamic linking using
   shared libraries */ 
/* #undef WITH_DL_DLD */

/* Define if you want to compile in rudimentary thread support */
/* #undef WITH_THREAD */

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

/* Define if you have the flock function.  */
#define HAVE_FLOCK 1

/* Define if you have the fork function.  */
#define HAVE_FORK 1

/* Define if you have the ftime function.  */
#define HAVE_FTIME 1

/* Define if you have the ftruncate function.  */
#define HAVE_FTRUNCATE 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define if you have the gethostname_r function.  */
/* #undef HAVE_GETHOSTNAME_R */

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
/* #undef HAVE_PLOCK */

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

/* Define if you have the <ncurses.h> header file.  */
/* #undef HAVE_NCURSES_H */

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

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

/* Define if you have the <sys/audioio.h> header file.  */
/* #undef HAVE_SYS_AUDIOIO_H */

/* Define if you have the <sys/dir.h> header file.  */
/* #undef HAVE_SYS_DIR_H */

/* Define if you have the <sys/file.h> header file.  */
#define HAVE_SYS_FILE_H 1

/* Define if you have the <sys/lock.h> header file.  */
/* #undef HAVE_SYS_LOCK_H */

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

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

/* Define if you have the <thread.h> header file.  */
/* #undef HAVE_THREAD_H */

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <utime.h> header file.  */
#define HAVE_UTIME_H 1

/* Define if you have the dl library (-ldl).  */
#define HAVE_LIBDL 1

/* Define if you have the dld library (-ldld).  */
/* #undef HAVE_LIBDLD */

/* Define if you have the ieee library (-lieee).  */
#define HAVE_LIBIEEE 1

/* End of file */
