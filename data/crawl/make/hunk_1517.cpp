 
 AC_SUBST(LIBOBJS)
 
-AC_HAVE_FUNCS(getdtablesize sys_siglist _sys_siglist psignal \
+AC_HAVE_FUNCS(getdtablesize psignal \
 	      dup2 getcwd sigsetmask getgroups setlinebuf \
 	      seteuid setegid setreuid setregid strerror)
+AC_COMPILE_CHECK(sys_siglist, ,
+   [extern char *sys_siglist[]; puts(*sys_siglist);],
+   AC_DEFINE(HAVE_SYS_SIGLIST))
+AC_COMPILE_CHECK(_sys_siglist, ,
+   [extern char *_sys_siglist[]; puts(*_sys_siglist);],
+   AC_DEFINE(HAVE__SYS_SIGLIST))
 AC_ALLOCA
 AC_VFORK
 AC_SETVBUF_REVERSED
