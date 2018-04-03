SQUID_DEFINE_BOOL(USE_GNUREGEX,$enable_gnuregex,[Define if we should use GNU regex])
AC_SUBST(REGEXLIB)

SQUID_CHECK_DEFAULT_FD_SETSIZE

dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Maximum number of filedescriptors we can open)
dnl damn! FreeBSD pthreads break dup2().
TLDFLAGS="$LDFLAGS"
if test -n "$squid_filedescriptors_num" ; then
  SQUID_MAXFD=$squid_filedescriptors_num
  AC_MSG_RESULT($SQUID_MAXFD (user-forced))
else
  case $host in
  i386-unknown-freebsd*)
      if echo "$LDFLAGS" | grep -q pthread; then
  	LDFLAGS=`echo $LDFLAGS | sed -e "s/-pthread//"`
      fi
  esac
  AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>	/* needed on FreeBSD */
#include <sys/param.h>
#include <sys/resource.h>
int main(int argc, char **argv) {
	FILE *fp;
	int i,j;
#if defined(__CYGWIN32__) || defined (__CYGWIN__)
    /* getrlimit and sysconf returns bogous values on cygwin32.
     * Number of fds is virtually unlimited in cygwin (sys/param.h)
     * __CYGWIN32__ is deprecated.
     */
    i = NOFILE;
#else
#if HAVE_SETRLIMIT
    struct rlimit rl;
#if defined(RLIMIT_NOFILE)
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
        perror("getrlimit: RLIMIT_NOFILE");
    } else {
#if defined(__APPLE__)
        /* asking for more than OPEN_MAX fails on Leopard */
        rl.rlim_cur = (OPEN_MAX < rl.rlim_max ? OPEN_MAX : rl.rlim_max);
#else
        rl.rlim_cur = rl.rlim_max;      /* set it to the max */
#endif
        if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
            perror("setrlimit: RLIMIT_NOFILE");
        }
    }
#elif defined(RLIMIT_OFILE)
    if (getrlimit(RLIMIT_OFILE, &rl) < 0) {
        perror("getrlimit: RLIMIT_OFILE");
    } else {
        rl.rlim_cur = rl.rlim_max;      /* set it to the max */
        if (setrlimit(RLIMIT_OFILE, &rl) < 0) {
            perror("setrlimit: RLIMIT_OFILE");
        }
    }
#endif /* RLIMIT_NOFILE */
#endif /* HAVE_SETRLIMIT */
	/* by starting at 2^14, we will never get higher
	than 2^15 for SQUID_MAXFD */
        i = j = 1<<14;
        while (j) {
                j >>= 1;
                if (dup2(0, i) < 0) { 
                        i -= j;
                } else {
                        close(i);
                        i += j;
                }
        }
        i++;
#endif /* IF !DEF CYGWIN */
	fp = fopen("conftestval", "w");
	fprintf (fp, "%d\n", i & ~0x3F);
	return 0;
}
  ]])],[SQUID_MAXFD=`cat conftestval`],[SQUID_MAXFD=256],[SQUID_MAXFD=256])
  dnl Microsoft MSVCRT.DLL supports 2048 maximum FDs
  case "$host_os" in
  mingw|mingw32)
    SQUID_MAXFD="2048"
    ;;
  esac
  AC_MSG_RESULT($SQUID_MAXFD)
fi
AC_DEFINE_UNQUOTED(SQUID_MAXFD, $SQUID_MAXFD,[Maximum number of open filedescriptors])
if test "$SQUID_MAXFD" -lt 512 ; then
    AC_MSG_WARN([$SQUID_MAXFD may not be enough filedescriptors if your])
    AC_MSG_WARN([cache will be very busy.  Please see the FAQ page])
    AC_MSG_WARN([http://wiki.squid-cache.org/SquidFaq/TroubleShooting])
    AC_MSG_WARN([on how to increase your filedescriptor limit])
fi
LDFLAGS="$TLDFLAGS"

if test `expr $SQUID_MAXFD % 64` != 0; then
    AC_MSG_WARN([$SQUID_MAXFD is not an multiple of 64. This may cause issues on certain platforms.])
fi

dnl Not cached since people are likely to tune this
AC_MSG_CHECKING(Default UDP send buffer size)