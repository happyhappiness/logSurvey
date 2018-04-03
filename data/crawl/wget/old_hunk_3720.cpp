
UNAME_MACHINE=`(uname -m) 2>/dev/null` || UNAME_MACHINE=unknown
UNAME_RELEASE=`(uname -r) 2>/dev/null` || UNAME_RELEASE=unknown
UNAME_SYSTEM=`(uname -s) 2>/dev/null` || UNAME_SYSTEM=unknown
UNAME_VERSION=`(uname -v) 2>/dev/null` || UNAME_VERSION=unknown

trap 'rm -f dummy.c dummy.o dummy; exit 1' 1 2 15

# Note: order is significant - the case branches are not exclusive.

case "${UNAME_MACHINE}:${UNAME_SYSTEM}:${UNAME_RELEASE}:${UNAME_VERSION}" in
    alpha:OSF1:*:*)
	# A Vn.n version is a released version.
	# A Tn.n version is a released field test version.
	# A Xn.n version is an unreleased experimental baselevel.
	# 1.2 uses "1.2" for uname -r.
	echo alpha-dec-osf`echo ${UNAME_RELEASE} | sed -e 's/^[VTX]//'`
	exit 0 ;;
    21064:Windows_NT:50:3)
	echo alpha-dec-winnt3.5
	exit 0 ;;
    Amiga*:UNIX_System_V:4.0:*)
	echo m68k-cbm-sysv4
	exit 0;;
    amiga:NetBSD:*:*)
      echo m68k-cbm-netbsd${UNAME_RELEASE}
      exit 0 ;;
    amiga:OpenBSD:*:*)
      echo m68k-cbm-openbsd${UNAME_RELEASE}
      exit 0 ;;
    arm:RISC*:1.[012]*:*|arm:riscix:1.[012]*:*)
	echo arm-acorn-riscix${UNAME_RELEASE}
	exit 0;;
    Pyramid*:OSx*:*:*|MIS*:OSx*:*:*)
	# akee@wpdis03.wpafb.af.mil (Earle F. Ake) contributed MIS and NILE.
	if test "`(/bin/universe) 2>/dev/null`" = att ; then
		echo pyramid-pyramid-sysv3
