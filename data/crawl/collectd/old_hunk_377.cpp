
AC_FUNC_STRERROR_R

AC_CHECK_FUNCS(getpwnam_r getgrnam_r setgroups regcomp regerror regexec regfree)

socket_needs_socket="no"