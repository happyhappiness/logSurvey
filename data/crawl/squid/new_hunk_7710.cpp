EOF


echo $ac_n "checking Default UDP send buffer size""... $ac_c" 1>&6
if test "$cross_compiling" = yes; then
  SQUID_UDP_SO_SNDBUF=8192
else
cat > conftest.$ac_ext <<EOF
#line 2170 "configure"
#include "confdefs.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
main ()
{
        int fd,val=0,len=sizeof(int);
	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) exit(1);
        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) < 0) exit(1);
	if (val<=0) exit(1);
        fprintf (fopen("conftestval", "w"), "%d\n", val);
	exit(0);
}

EOF
eval $ac_link
if test -s conftest && (./conftest; exit) 2>/dev/null; then
  SQUID_UDP_SO_SNDBUF=`cat conftestval`
else
  SQUID_UDP_SO_SNDBUF=8192
fi
fi
rm -fr conftest*
echo "$ac_t""$SQUID_UDP_SO_SNDBUF" 1>&6
cat >> confdefs.h <<EOF
#define SQUID_UDP_SO_SNDBUF $SQUID_UDP_SO_SNDBUF
EOF


echo $ac_n "checking Default UDP receive buffer size""... $ac_c" 1>&6
if test "$cross_compiling" = yes; then
  SQUID_UDP_SO_RCVBUF=8192
else
cat > conftest.$ac_ext <<EOF
#line 2206 "configure"
#include "confdefs.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
main ()
{
        int fd,val=0,len=sizeof(int);
	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) exit(1);
        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0) exit(1);
	if (val <= 0) exit(1);
        fprintf (fopen("conftestval", "w"), "%d\n", val);
	exit(0);
}

EOF
eval $ac_link
if test -s conftest && (./conftest; exit) 2>/dev/null; then
  SQUID_UDP_SO_RCVBUF=`cat conftestval`
else
  SQUID_UDP_SO_RCVBUF=8192
fi
fi
rm -fr conftest*
echo "$ac_t""$SQUID_UDP_SO_RCVBUF" 1>&6
cat >> confdefs.h <<EOF
#define SQUID_UDP_SO_RCVBUF $SQUID_UDP_SO_RCVBUF
EOF


echo $ac_n "checking Default TCP send buffer size""... $ac_c" 1>&6
if test "$cross_compiling" = yes; then
  SQUID_TCP_SO_SNDBUF=8192
else
cat > conftest.$ac_ext <<EOF
#line 2242 "configure"
#include "confdefs.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
main ()
{
        int fd,val=0,len=sizeof(int);
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) exit(1);
        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) < 0) exit(1);
	if (val <= 0) exit(1);
        fprintf (fopen("conftestval", "w"), "%d\n", val);
	exit(0);
}

EOF
eval $ac_link
if test -s conftest && (./conftest; exit) 2>/dev/null; then
  SQUID_TCP_SO_SNDBUF=`cat conftestval`
else
  SQUID_TCP_SO_SNDBUF=8192
fi
fi
rm -fr conftest*
echo "$ac_t""$SQUID_TCP_SO_SNDBUF" 1>&6
cat >> confdefs.h <<EOF
#define SQUID_TCP_SO_SNDBUF $SQUID_TCP_SO_SNDBUF
EOF


echo $ac_n "checking Default TCP receive buffer size""... $ac_c" 1>&6
if test "$cross_compiling" = yes; then
  SQUID_TCP_SO_RCVBUF=8192
else
cat > conftest.$ac_ext <<EOF
#line 2278 "configure"
#include "confdefs.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
main ()
{
        int fd,val=0,len=sizeof(int);
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) exit(1);
        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0) exit(1);
	if (val <= 0) exit(1);
        fprintf (fopen("conftestval", "w"), "%d\n", val);
	exit(0);
}

EOF
eval $ac_link
if test -s conftest && (./conftest; exit) 2>/dev/null; then
  SQUID_TCP_SO_RCVBUF=`cat conftestval`
else
  SQUID_TCP_SO_RCVBUF=8192
fi
fi
rm -fr conftest*
echo "$ac_t""$SQUID_TCP_SO_RCVBUF" 1>&6
cat >> confdefs.h <<EOF
#define SQUID_TCP_SO_RCVBUF $SQUID_TCP_SO_RCVBUF
EOF


echo $ac_n "checking if sys_errlist is already defined""... $ac_c" 1>&6
cat > conftest.$ac_ext <<EOF
#line 2311 "configure"
#include "confdefs.h"
#include <stdio.h>
int main() { return 0; }
int t() {
char *s = sys_errlist[0];
; return 0; }
EOF
if eval $ac_compile; then
  rm -rf conftest*
  echo "$ac_t""yes" 1>&6
else
  rm -rf conftest*
  echo "$ac_t""no" 1>&6
cat >> confdefs.h <<\EOF
#define NEED_SYS_ERRLIST 1
EOF

fi
rm -f conftest*


XTRA_OBJS=''
if test "$HAVE_LIBMALLOC" = "yes" ; then
	if test -r /usr/lib/debug/malloc.o ; then
