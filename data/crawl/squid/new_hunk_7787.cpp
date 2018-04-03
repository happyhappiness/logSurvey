done


echo $ac_n "checking Maximum number of filedescriptors we can open""... $ac_c" 1>&6
if test "$cross_compiling" = yes; then
  SQUID_FD_SETSIZE=256
else
cat > conftest.$ac_ext <<EOF
#line 2066 "configure"
#include "confdefs.h"

#include <unistd.h>
#include <sys/param.h>
#include <sys/resource.h>
main() {
	int i,j;
#if HAVE_SETRLIMIT
    struct rlimit rl;
#if defined(RLIMIT_NOFILE)
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
        perror("getrlimit: RLIMIT_NOFILE");
    } else {
        rl.rlim_cur = rl.rlim_max;      /* set it to the max */
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
#if HAVE_SYSCONF && defined(_SC_OPEN_MAX)
        i = sysconf(_SC_OPEN_MAX);
#elif HAVE_GETDTABLESIZE
        i = getdtablesize();
#elif defined(OPEN_MAX)
        i = OPEN_MAX;
#elif defined(NOFILE)
        i = NOFILE;
#elif defined(_NFILE)
        i = _NFILE;
#else
	while((j=open("/dev/null", 0)) > 0) i=j;
#endif
	fprintf (fopen("conftestval", "w"), "%d\n", i);
	exit(0);
}

EOF
eval $ac_link
if test -s conftest && (./conftest; exit) 2>/dev/null; then
  SQUID_FD_SETSIZE=`cat conftestval`
else
  SQUID_FD_SETSIZE=256
fi
fi
rm -fr conftest*
echo "$ac_t""$SQUID_FD_SETSIZE" 1>&6
cat >> confdefs.h <<EOF
#define SQUID_FD_SETSIZE $SQUID_FD_SETSIZE
EOF


XTRA_OBJS=''
if test "$HAVE_LIBMALLOC" = "yes" ; then
	if test -r /usr/lib/debug/malloc.o ; then
