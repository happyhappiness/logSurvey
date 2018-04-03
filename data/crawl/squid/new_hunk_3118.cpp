SQUID_DEFINE_BOOL(USE_GNUREGEX,$enable_gnuregex,[Define if we should use GNU regex])
AC_SUBST(REGEXLIB)


dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Default UDP send buffer size)