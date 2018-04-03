AC_AIX
AC_ISC_POSIX
AC_MINIX
AC_STDC_HEADERS
AC_DIR_HEADER
AC_UID_T			dnl Also does gid_t.
AC_GETGROUPS_T
AC_PID_T
AC_RETSIGTYPE
AC_HAVE_HEADERS(unistd.h limits.h sys/param.h fcntl.h string.h memory.h \
	        sys/timeb.h)
AC_MINUS_C_MINUS_O
AC_CONST			dnl getopt needs this.
AC_STAT_MACROS_BROKEN

AC_SUBST(LIBOBJS)

AC_HAVE_FUNCS(getdtablesize psignal \
	      dup2 getcwd sigsetmask getgroups setlinebuf \
	      seteuid setegid setreuid setregid strerror)
AC_COMPILE_CHECK(sys_siglist, ,
   [extern char *sys_siglist[]; puts(*sys_siglist);],
   AC_DEFINE(HAVE_SYS_SIGLIST))
AC_COMPILE_CHECK(_sys_siglist, ,
   [extern char *_sys_siglist[]; puts(*_sys_siglist);],
   AC_DEFINE(HAVE__SYS_SIGLIST))
AC_ALLOCA
AC_VFORK
AC_SETVBUF_REVERSED
AC_GETLOADAVG
AC_STRCOLL

dnl Check out the wait reality.
AC_HAVE_HEADERS(sys/wait.h) AC_HAVE_FUNCS(waitpid wait3)
AC_COMPILE_CHECK(union wait, [#include <sys/types.h>
#include <sys/wait.h>],
	 	 [union wait status; int pid; pid = wait (&status);
#ifdef WEXITSTATUS
/* Some POSIXoid systems have both the new-style macros and the old
   union wait type, and they do not work together.  If union wait
