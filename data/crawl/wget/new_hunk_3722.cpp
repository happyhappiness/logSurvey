	      -e y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/
	exit 0 ;;
    CRAY*TS:*:*:*)
	echo t90-cray-unicos${UNAME_RELEASE} | sed -e 's/\.[^.]*$/.X/'
	exit 0 ;;
    CRAY*T3D:*:*:*)
	echo alpha-cray-unicosmk${UNAME_RELEASE} | sed -e 's/\.[^.]*$/.X/'
	exit 0 ;;
    CRAY*T3E:*:*:*)
	echo alphaev5-cray-unicosmk${UNAME_RELEASE} | sed -e 's/\.[^.]*$/.X/'
	exit 0 ;;
    CRAY*SV1:*:*:*)
	echo sv1-cray-unicos${UNAME_RELEASE} | sed -e 's/\.[^.]*$/.X/'
	exit 0 ;;
    CRAY-2:*:*:*)
	echo cray2-cray-unicos
        exit 0 ;;
    F30[01]:UNIX_System_V:*:* | F700:UNIX_System_V:*:*)
	FUJITSU_PROC=`uname -m | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' 'abcdefghijklmnopqrstuvwxyz'`
        FUJITSU_SYS=`uname -p | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' 'abcdefghijklmnopqrstuvwxyz' | sed -e 's/\///'`
        FUJITSU_REL=`echo ${UNAME_RELEASE} | sed -e 's/ /_/'`
        echo "${FUJITSU_PROC}-fujitsu-${FUJITSU_SYS}${FUJITSU_REL}"
        exit 0 ;;
    hp300:OpenBSD:*:*)
	echo m68k-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    i?86:BSD/386:*:* | i?86:BSD/OS:*:* | *:Ascend\ Embedded/OS:*:*)
	echo ${UNAME_MACHINE}-pc-bsdi${UNAME_RELEASE}
	exit 0 ;;
    sparc*:BSD/OS:*:*)
	echo sparc-unknown-bsdi${UNAME_RELEASE}
	exit 0 ;;
    *:BSD/OS:*:*)
	echo ${UNAME_MACHINE}-unknown-bsdi${UNAME_RELEASE}
	exit 0 ;;
    *:FreeBSD:*:*)
	echo ${UNAME_MACHINE}-unknown-freebsd`echo ${UNAME_RELEASE}|sed -e 's/[-(].*//'`
	exit 0 ;;
    *:OpenBSD:*:*)
	echo ${UNAME_MACHINE}-unknown-openbsd`echo ${UNAME_RELEASE}|sed -e 's/[-_].*/\./'`
	exit 0 ;;
    i*:CYGWIN*:*)
	echo ${UNAME_MACHINE}-pc-cygwin
	exit 0 ;;
    i*:MINGW*:*)
	echo ${UNAME_MACHINE}-pc-mingw32
	exit 0 ;;
    i*:PW*:*)
	echo ${UNAME_MACHINE}-pc-pw32
	exit 0 ;;
    i*:Windows_NT*:* | Pentium*:Windows_NT*:*)
	# How do we know it's Interix rather than the generic POSIX subsystem?
	# It also conflicts with pre-2.0 versions of AT&T UWIN. Should we
	# UNAME_MACHINE based on the output of uname instead of i386?
	echo i386-pc-interix
	exit 0 ;;
    i*:UWIN*:*)
	echo ${UNAME_MACHINE}-pc-uwin
	exit 0 ;;
    p*:CYGWIN*:*)
	echo powerpcle-unknown-cygwin
	exit 0 ;;
    prep*:SunOS:5.*:*)
	echo powerpcle-unknown-solaris2`echo ${UNAME_RELEASE}|sed -e 's/[^.]*//'`
	exit 0 ;;
    *:GNU:*:*)
	echo `echo ${UNAME_MACHINE}|sed -e 's,[-/].*$,,'`-unknown-gnu`echo ${UNAME_RELEASE}|sed -e 's,/.*$,,'`
	exit 0 ;;
    i*86:Minix:*:*)
	echo ${UNAME_MACHINE}-pc-minix
	exit 0 ;;
    arm*:Linux:*:*)
	echo ${UNAME_MACHINE}-unknown-linux-gnu
	exit 0 ;;
    ia64:Linux:*:*)
	echo ${UNAME_MACHINE}-unknown-linux
	exit 0 ;;
    m68*:Linux:*:*)
	echo ${UNAME_MACHINE}-unknown-linux-gnu
	exit 0 ;;
    mips:Linux:*:*)
	cat >$dummy.c <<EOF
#ifdef __cplusplus
#include <stdio.h>  /* for printf() prototype */
int main (int argc, char *argv[]) {
#else
int main (argc, argv) int argc; char *argv[]; {
#endif
#ifdef __MIPSEB__
  printf ("%s-unknown-linux-gnu\n", argv[1]);
#endif
#ifdef __MIPSEL__
  printf ("%sel-unknown-linux-gnu\n", argv[1]);
#endif
  return 0;
}
EOF
	$CC_FOR_BUILD $dummy.c -o $dummy 2>/dev/null && ./$dummy "${UNAME_MACHINE}" && rm -f $dummy.c $dummy && exit 0
	rm -f $dummy.c $dummy
	;;
    ppc:Linux:*:*)
	# Determine Lib Version
	cat >$dummy.c <<EOF
#include <features.h>
#if defined(__GLIBC__)
extern char __libc_version[];
extern char __libc_release[];
#endif
main(argc, argv)
     int argc;
     char *argv[];
{
#if defined(__GLIBC__)
  printf("%s %s\n", __libc_version, __libc_release);
#else
  printf("unknown\n");
#endif
  return 0;
}
EOF
	LIBC=""
	$CC_FOR_BUILD $dummy.c -o $dummy 2>/dev/null
	if test "$?" = 0 ; then
		./$dummy | grep 1\.99 > /dev/null
		if test "$?" = 0 ; then LIBC="libc1" ; fi
	fi
	rm -f $dummy.c $dummy
	echo powerpc-unknown-linux-gnu${LIBC}
	exit 0 ;;
    alpha:Linux:*:*)
	cat <<EOF >$dummy.s
	  .data
	  \$Lformat:
		.byte 37,100,45,37,120,10,0	# "%d-%x\n"
	   .text
		.globl main
		.align 4
		.ent main
	    main:
		.frame \$30,16,\$26,0
		ldgp \$29,0(\$27)
		.prologue 1
		.long 0x47e03d80 # implver \$0
		lda \$2,-1
		.long 0x47e20c21 # amask \$2,\$1
		lda \$16,\$Lformat
		mov \$0,\$17
		not \$1,\$18
		jsr \$26,printf
		ldgp \$29,0(\$26)
		mov 0,\$16
		jsr \$26,exit
		.end main
EOF
	LIBC=""
	$CC_FOR_BUILD $dummy.s -o $dummy 2>/dev/null
	if test "$?" = 0 ; then
		case `./$dummy` in
		0-0)	UNAME_MACHINE="alpha" ;;
		1-0)	UNAME_MACHINE="alphaev5" ;;
		1-1)    UNAME_MACHINE="alphaev56" ;;
		1-101)	UNAME_MACHINE="alphapca56" ;;
		2-303)	UNAME_MACHINE="alphaev6" ;;
		2-307)	UNAME_MACHINE="alphaev67" ;;
		esac
		objdump --private-headers $dummy | \
		  grep ld.so.1 > /dev/null
		if test "$?" = 0 ; then
			LIBC="libc1"
		fi
	fi
	rm -f $dummy.s $dummy
	echo ${UNAME_MACHINE}-unknown-linux-gnu${LIBC}
	exit 0 ;;
    parisc:Linux:*:* | hppa:Linux:*:*)
	# Look for CPU level
	case `grep '^cpu[^a-z]*:' /proc/cpuinfo 2>/dev/null | cut -d' ' -f2` in
	  PA7*) echo hppa1.1-unknown-linux-gnu ;;
	  PA8*) echo hppa2.0-unknown-linux-gnu ;;
	  *)    echo hppa-unknown-linux-gnu ;;
	esac
	exit 0 ;;
    parisc64:Linux:*:* | hppa64:Linux:*:*)
	echo hppa64-unknown-linux-gnu
	exit 0 ;;
    s390:Linux:*:* | s390x:Linux:*:*)
	echo ${UNAME_MACHINE}-ibm-linux
	exit 0 ;;
    sh*:Linux:*:*)
	echo ${UNAME_MACHINE}-unknown-linux-gnu
	exit 0 ;;
    sparc:Linux:*:* | sparc64:Linux:*:*)
	echo ${UNAME_MACHINE}-unknown-linux-gnu
	exit 0 ;;
    x86_64:Linux:*:*)
	echo x86_64-unknown-linux-gnu
	exit 0 ;;
    i?86:Linux:*:*)
	# The BFD linker knows what the default object file format is, so
	# first see if it will tell us. cd to the root directory to prevent
	# problems with other programs or directories called `ld' in the path.
	ld_supported_emulations=`cd /; ld --help 2>&1 \
			 | sed -ne '/supported emulations:/!d
				    s/[ 	][ 	]*/ /g
				    s/.*supported emulations: *//
				    s/ .*//
				    p'`
        case "$ld_supported_emulations" in
	  i?86linux)
		echo "${UNAME_MACHINE}-pc-linux-gnuaout"
		exit 0
		;;
	  elf_i?86)
		TENTATIVE="${UNAME_MACHINE}-pc-linux-gnu"
		;;
	  i?86coff)
		echo "${UNAME_MACHINE}-pc-linux-gnucoff"
		exit 0
		;;
	esac
	# Either a pre-BFD a.out linker (linux-gnuoldld)
	# or one that does not give us useful --help.
	# GCC wants to distinguish between linux-gnuoldld and linux-gnuaout.
	# If ld does not provide *any* "supported emulations:"
	# that means it is gnuoldld.
	test -z "$ld_supported_emulations" && echo "${UNAME_MACHINE}-pc-linux-gnuoldld" && exit 0
	case "${UNAME_MACHINE}" in
	i?86)
	  VENDOR=pc;
	  ;;
	*)
	  VENDOR=unknown;
	  ;;
	esac
	# Determine whether the default compiler is a.out or elf
	cat >$dummy.c <<EOF
#include <features.h>
#ifdef __cplusplus
#include <stdio.h>  /* for printf() prototype */
	int main (int argc, char *argv[]) {
#else
	int main (argc, argv) int argc; char *argv[]; {
#endif
#ifdef __ELF__
# ifdef __GLIBC__
#  if __GLIBC__ >= 2
    printf ("%s-${VENDOR}-linux-gnu\n", argv[1]);
#  else
    printf ("%s-${VENDOR}-linux-gnulibc1\n", argv[1]);
#  endif
# else
   printf ("%s-${VENDOR}-linux-gnulibc1\n", argv[1]);
# endif
#else
  printf ("%s-${VENDOR}-linux-gnuaout\n", argv[1]);
#endif
  return 0;
}
EOF
	$CC_FOR_BUILD $dummy.c -o $dummy 2>/dev/null && ./$dummy "${UNAME_MACHINE}" && rm -f $dummy.c $dummy && exit 0
	rm -f $dummy.c $dummy
	test x"${TENTATIVE}" != x && echo "${TENTATIVE}" && exit 0
	;;
# ptx 4.0 does uname -s correctly, with DYNIX/ptx in there.  earlier versions
# are messed up and put the nodename in both sysname and nodename.
    i?86:DYNIX/ptx:4*:*)
	echo i386-sequent-sysv4
	exit 0 ;;
    i?86:UNIX_SV:4.2MP:2.*)
        # Unixware is an offshoot of SVR4, but it has its own version
        # number series starting with 2...
        # I am not positive that other SVR4 systems won't match this,
	# I just have to hope.  -- rms.
        # Use sysv4.2uw... so that sysv4* matches it.
	echo ${UNAME_MACHINE}-pc-sysv4.2uw${UNAME_VERSION}
	exit 0 ;;
    i?86:*:4.*:* | i?86:SYSTEM_V:4.*:*)
	UNAME_REL=`echo ${UNAME_RELEASE} | sed 's/\/MP$//'`
	if grep Novell /usr/include/link.h >/dev/null 2>/dev/null; then
		echo ${UNAME_MACHINE}-univel-sysv${UNAME_REL}
	else
		echo ${UNAME_MACHINE}-pc-sysv${UNAME_REL}
	fi
	exit 0 ;;
    i?86:*:5:7*)
        # Fixed at (any) Pentium or better
        UNAME_MACHINE=i586
        if [ ${UNAME_SYSTEM} = "UnixWare" ] ; then
	    echo ${UNAME_MACHINE}-sco-sysv${UNAME_RELEASE}uw${UNAME_VERSION}
	else
	    echo ${UNAME_MACHINE}-pc-sysv${UNAME_RELEASE}
	fi
	exit 0 ;;
    i?86:*:3.2:*)
