	      -e y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/
	exit 0 ;;
    CRAY*TS:*:*:*)
	echo t90-cray-unicos${UNAME_RELEASE}
	exit 0 ;;
    CRAY-2:*:*:*)
	echo cray2-cray-unicos
        exit 0 ;;
    F300:UNIX_System_V:*:*)
        FUJITSU_SYS=`uname -p | tr [A-Z] [a-z] | sed -e 's/\///'`
        FUJITSU_REL=`echo ${UNAME_RELEASE} | sed -e 's/ /_/'`
        echo "f300-fujitsu-${FUJITSU_SYS}${FUJITSU_REL}"
        exit 0 ;;
    F301:UNIX_System_V:*:*)
       echo f301-fujitsu-uxpv`echo $UNAME_RELEASE | sed 's/ .*//'`
       exit 0 ;;
    hp3[0-9][05]:NetBSD:*:*)
	echo m68k-hp-netbsd${UNAME_RELEASE}
	exit 0 ;;
    hp3[0-9][05]:OpenBSD:*:*)
	echo m68k-hp-openbsd${UNAME_RELEASE}
	exit 0 ;;
    i?86:BSD/386:*:* | *:BSD/OS:*:*)
	echo ${UNAME_MACHINE}-pc-bsdi${UNAME_RELEASE}
	exit 0 ;;
    *:FreeBSD:*:*)
	echo ${UNAME_MACHINE}-unknown-freebsd`echo ${UNAME_RELEASE}|sed -e 's/[-(].*//'`
	exit 0 ;;
    *:NetBSD:*:*)
	echo ${UNAME_MACHINE}-unknown-netbsd`echo ${UNAME_RELEASE}|sed -e 's/[-_].*/\./'`
	exit 0 ;;
    *:OpenBSD:*:*)
	echo ${UNAME_MACHINE}-unknown-openbsd`echo ${UNAME_RELEASE}|sed -e 's/[-_].*/\./'`
	exit 0 ;;
    i*:CYGWIN*:*)
	echo i386-pc-cygwin32
	exit 0 ;;
    p*:CYGWIN*:*)
	echo powerpcle-unknown-cygwin32
	exit 0 ;;
    prep*:SunOS:5.*:*)
	echo powerpcle-unknown-solaris2`echo ${UNAME_RELEASE}|sed -e 's/[^.]*//'`
	exit 0 ;;
    *:GNU:*:*)
	echo `echo ${UNAME_MACHINE}|sed -e 's,/.*$,,'`-unknown-gnu`echo ${UNAME_RELEASE}|sed -e 's,/.*$,,'`
	exit 0 ;;
    *:Linux:*:*)
	# The BFD linker knows what the default object file format is, so
	# first see if it will tell us.
	ld_help_string=`ld --help 2>&1`
	if echo "$ld_help_string" | grep >/dev/null 2>&1 "supported emulations: elf_i.86"; then
	  echo "${UNAME_MACHINE}-pc-linux-gnu" ; exit 0
	elif echo "$ld_help_string" | grep >/dev/null 2>&1 "supported emulations: i.86linux"; then
	  echo "${UNAME_MACHINE}-pc-linux-gnuaout" ; exit 0
	elif echo "$ld_help_string" | grep >/dev/null 2>&1 "supported emulations: i.86coff"; then
	  echo "${UNAME_MACHINE}-pc-linux-gnucoff" ; exit 0
	elif echo "$ld_help_string" | grep >/dev/null 2>&1 "supported emulations: m68kelf"; then
	  echo "${UNAME_MACHINE}-unknown-linux-gnu" ; exit 0
	elif echo "$ld_help_string" | grep >/dev/null 2>&1 "supported emulations: m68klinux"; then
	  echo "${UNAME_MACHINE}-unknown-linux-gnuaout" ; exit 0
	elif echo "$ld_help_string" | grep >/dev/null 2>&1 "supported emulations: elf32ppc"; then
	  echo "powerpc-unknown-linux-gnu" ; exit 0
	elif test "${UNAME_MACHINE}" = "alpha" ; then
	  echo alpha-unknown-linux-gnu ; exit 0
	elif test "${UNAME_MACHINE}" = "sparc" ; then
	  echo sparc-unknown-linux-gnu ; exit 0
	else
	  # Either a pre-BFD a.out linker (linux-gnuoldld) or one that does not give us
	  # useful --help.  Gcc wants to distinguish between linux-gnuoldld and linux-gnuaout.
	  test ! -d /usr/lib/ldscripts/. \
	    && echo "${UNAME_MACHINE}-pc-linux-gnuoldld" && exit 0
	  # Determine whether the default compiler is a.out or elf
	  cat >dummy.c <<EOF
main(argc, argv)
int argc;
char *argv[];
{
#ifdef __ELF__
  printf ("%s-pc-linux-gnu\n", argv[1]);
#else
  printf ("%s-pc-linux-gnuaout\n", argv[1]);
#endif
  return 0;
}
EOF
	  ${CC-cc} dummy.c -o dummy 2>/dev/null && ./dummy "${UNAME_MACHINE}" && rm dummy.c dummy && exit 0
	  rm -f dummy.c dummy
	fi ;;
# ptx 4.0 does uname -s correctly, with DYNIX/ptx in there.  earlier versions
# are messed up and put the nodename in both sysname and nodename.
    i?86:DYNIX/ptx:4*:*)
	echo i386-sequent-sysv4
	exit 0 ;;
    i?86:*:4.*:* | i?86:SYSTEM_V:4.*:*)
	if grep Novell /usr/include/link.h >/dev/null 2>/dev/null; then
		echo ${UNAME_MACHINE}-univel-sysv${UNAME_RELEASE}
	else
		echo ${UNAME_MACHINE}-pc-sysv${UNAME_RELEASE}
	fi
	exit 0 ;;
    i?86:*:3.2:*)
