
AC_SUBST(LIBOBJS)

AC_HAVE_FUNCS(getdtablesize sys_siglist _sys_siglist psignal \
	      dup2 getcwd sigsetmask getgroups setlinebuf \
	      seteuid setegid setreuid setregid strerror)
AC_ALLOCA
AC_VFORK
AC_SETVBUF_REVERSED
