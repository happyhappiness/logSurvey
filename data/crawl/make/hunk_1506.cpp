 AC_AIX
 AC_ISC_POSIX
 AC_MINIX
-AC_STDC_HEADERS
-AC_DIR_HEADER
-AC_UID_T			dnl Also does gid_t.
-AC_GETGROUPS_T
-AC_PID_T
-AC_RETSIGTYPE
-AC_HAVE_HEADERS(unistd.h limits.h sys/param.h fcntl.h string.h memory.h \
-	        sys/timeb.h)
-AC_MINUS_C_MINUS_O
-AC_CONST			dnl getopt needs this.
-AC_STAT_MACROS_BROKEN
+AC_HEADER_STDC
+AC_HEADER_DIRENT
+AC_TYPE_UID_T			dnl Also does gid_t.
+AC_TYPE_GETGROUPS
+AC_TYPE_PID_T
+AC_TYPE_SIGNAL
+AC_CHECK_HEADERS(unistd.h limits.h sys/param.h fcntl.h string.h memory.h \
+	         sys/timeb.h)
+AC_PROG_CC_C_O
+AC_C_CONST			dnl getopt needs this.
+AC_HEADER_STAT
 
 AC_SUBST(LIBOBJS)
 
-AC_HAVE_FUNCS(getdtablesize psignal \
-	      dup2 getcwd sigsetmask getgroups setlinebuf \
-	      seteuid setegid setreuid setregid strerror)
-AC_COMPILE_CHECK(sys_siglist, ,
-   [extern char *sys_siglist[]; puts(*sys_siglist);],
-   AC_DEFINE(HAVE_SYS_SIGLIST))
-AC_COMPILE_CHECK(_sys_siglist, ,
-   [extern char *_sys_siglist[]; puts(*_sys_siglist);],
-   AC_DEFINE(HAVE__SYS_SIGLIST))
-AC_ALLOCA
-AC_VFORK
-AC_SETVBUF_REVERSED
-AC_GETLOADAVG
-AC_STRCOLL
+AC_DEFUN(AC_CHECK_SYMBOL, [dnl
+AC_MSG_CHECKING(for $1)
+AC_CACHE_VAL(ac_cv_check_symbol_$1, [dnl
+AC_TRY_LINK(, [extern char *sys_siglist[]; puts(*sys_siglist);],
+	    ac_cv_check_symbol_$1=yes, ac_cv_check_symbol_$1=no)])
+if test "$ac_cv_check_symbol_$1" = yes; then
+changequote(,)dnl
+  ac_tr_symbol=`echo $1 | tr '[a-z]' '[A-Z]'`
+changequote([,])dnl
+  AC_DEFINE(HAVE_${ac_tr_symbol})
+fi
+AC_MSG_RESULT($ac_cv_check_symbol_$1)])dnl
+
+AC_CHECK_FUNCS(getdtablesize psignal \
+	       dup2 getcwd sigsetmask getgroups setlinebuf \
+	       seteuid setegid setreuid setregid strerror)
+AC_CHECK_SYMBOL(sys_siglist)
+AC_CHECK_SYMBOL(_sys_siglist)
+AC_FUNC_ALLOCA
+AC_FUNC_VFORK
+AC_FUNC_SETVBUF_REVERSED
+AC_FUNC_GETLOADAVG
+AC_FUNC_STRCOLL
 
-dnl Check out the wait reality.
-AC_HAVE_HEADERS(sys/wait.h) AC_HAVE_FUNCS(waitpid wait3)
-AC_COMPILE_CHECK(union wait, [#include <sys/types.h>
+# Check out the wait reality.
+AC_CHECK_HEADERS(sys/wait.h) AC_CHECK_FUNCS(waitpid wait3)
+AC_MSG_CHECKING(for union wait)
+AC_CACHE_VAL(make_cv_union_wait, [dnl
+AC_TRY_LINK([#include <sys/types.h>
 #include <sys/wait.h>],
-	 	 [union wait status; int pid; pid = wait (&status);
+	    [union wait status; int pid; pid = wait (&status);
 #ifdef WEXITSTATUS
 /* Some POSIXoid systems have both the new-style macros and the old
    union wait type, and they do not work together.  If union wait
