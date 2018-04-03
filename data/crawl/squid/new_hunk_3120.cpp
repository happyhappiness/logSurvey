SQUID_DEFINE_BOOL(USE_GNUREGEX,$enable_gnuregex,[Define if we should use GNU regex])
AC_SUBST(REGEXLIB)

SQUID_CHECK_DEFAULT_FD_SETSIZE

dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Maximum number of filedescriptors we can open)