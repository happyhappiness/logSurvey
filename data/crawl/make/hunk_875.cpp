   fi
 fi
 
-AC_SUBST(LIBOBJS)
-
-AC_DEFUN(AC_CHECK_SYMBOL, [dnl
-AC_MSG_CHECKING(for $1)
-AC_CACHE_VAL(ac_cv_check_symbol_$1, [dnl
-AC_TRY_LINK(, [extern char *sys_siglist[]; puts(*sys_siglist);],
-	    ac_cv_check_symbol_$1=yes, ac_cv_check_symbol_$1=no)])
-if test "$ac_cv_check_symbol_$1" = yes; then
-changequote(,)dnl
-  ac_tr_symbol=`echo $1 | tr '[a-z]' '[A-Z]'`
-changequote([,])dnl
-  AC_DEFINE_UNQUOTED(HAVE_${ac_tr_symbol})
-fi
-AC_MSG_RESULT($ac_cv_check_symbol_$1)])dnl
 
 # See if we have a standard version of gettimeofday().  Since actual
 # implementations can differ, just make sure we have the most common
