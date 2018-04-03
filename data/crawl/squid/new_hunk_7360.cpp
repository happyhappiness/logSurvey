	strerror \
)

AC_MSG_CHECKING(Default FD_SETSIZE value)
AC_TRY_RUN([
#if HAVE_STDIO_H
#include <stdio.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
main() {
	fprintf (fopen("conftestval", "w"), "%d\n", FD_SETSIZE);
	exit(0);
}
],
DEFAULT_FD_SETSIZE=`cat conftestval`,
DEFAULT_FD_SETSIZE=256,
DEFAULT_FD_SETSIZE=256)
AC_MSG_RESULT($DEFAULT_FD_SETSIZE)
AC_DEFINE_UNQUOTED(DEFAULT_FD_SETSIZE, $DEFAULT_FD_SETSIZE)

AC_MSG_CHECKING(Maximum number of filedescriptors we can open)
AC_TRY_RUN([
#include <stdio.h>
