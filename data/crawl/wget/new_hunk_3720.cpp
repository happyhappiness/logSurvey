
UNAME_MACHINE=`(uname -m) 2>/dev/null` || UNAME_MACHINE=unknown
UNAME_RELEASE=`(uname -r) 2>/dev/null` || UNAME_RELEASE=unknown
UNAME_SYSTEM=`(uname -s) 2>/dev/null`  || UNAME_SYSTEM=unknown
UNAME_VERSION=`(uname -v) 2>/dev/null` || UNAME_VERSION=unknown

# Note: order is significant - the case branches are not exclusive.

case "${UNAME_MACHINE}:${UNAME_SYSTEM}:${UNAME_RELEASE}:${UNAME_VERSION}" in
    *:NetBSD:*:*)
	# Netbsd (nbsd) targets should (where applicable) match one or
	# more of the tupples: *-*-netbsdelf*, *-*-netbsdaout*,
	# *-*-netbsdecoff* and *-*-netbsd*.  For targets that recently
	# switched to ELF, *-*-netbsd* would select the old
	# object file format.  This provides both forward
	# compatibility and a consistent mechanism for selecting the
	# object file format.
	# Determine the machine/vendor (is the vendor relevant).
	case "${UNAME_MACHINE}" in
	    amiga) machine=m68k-unknown ;;
	    arm32) machine=arm-unknown ;;
	    atari*) machine=m68k-atari ;;
	    sun3*) machine=m68k-sun ;;
	    mac68k) machine=m68k-apple ;;
	    macppc) machine=powerpc-apple ;;
	    hp3[0-9][05]) machine=m68k-hp ;;
	    ibmrt|romp-ibm) machine=romp-ibm ;;
	    *) machine=${UNAME_MACHINE}-unknown ;;
	esac
	# The Operating System including object format, if it has switched
	# to ELF recently, or will in the future.
	case "${UNAME_MACHINE}" in
	    i386|sparc|amiga|arm*|hp300|mvme68k|vax|atari|luna68k|mac68k|news68k|next68k|pc532|sun3*|x68k)
		if echo __ELF__ | $CC_FOR_BUILD -E - 2>/dev/null \
			| grep __ELF__ >/dev/null
		then
		    # Once all utilities can be ECOFF (netbsdecoff) or a.out (netbsdaout).
		    # Return netbsd for either.  FIX?
		    os=netbsd
		else
		    os=netbsdelf
		fi
		;;
	    *)
	        os=netbsd
		;;
	esac
	# The OS release
	release=`echo ${UNAME_RELEASE}|sed -e 's/[-_].*/\./'`
	# Since CPU_TYPE-MANUFACTURER-KERNEL-OPERATING_SYSTEM:
	# contains redundant information, the shorter form:
	# CPU_TYPE-MANUFACTURER-OPERATING_SYSTEM is used.
	echo "${machine}-${os}${release}"
	exit 0 ;;
    alpha:OSF1:*:*)
	if test $UNAME_RELEASE = "V4.0"; then
		UNAME_RELEASE=`/usr/sbin/sizer -v | awk '{print $3}'`
	fi
	# A Vn.n version is a released version.
	# A Tn.n version is a released field test version.
	# A Xn.n version is an unreleased experimental baselevel.
	# 1.2 uses "1.2" for uname -r.
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
	$CC_FOR_BUILD $dummy.s -o $dummy 2>/dev/null
	if test "$?" = 0 ; then
		case `./$dummy` in
			0-0)
				UNAME_MACHINE="alpha"
				;;
			1-0)
				UNAME_MACHINE="alphaev5"
				;;
			1-1)
				UNAME_MACHINE="alphaev56"
				;;
			1-101)
				UNAME_MACHINE="alphapca56"
				;;
			2-303)
				UNAME_MACHINE="alphaev6"
				;;
			2-307)
				UNAME_MACHINE="alphaev67"
				;;
		esac
	fi
	rm -f $dummy.s $dummy
	echo ${UNAME_MACHINE}-dec-osf`echo ${UNAME_RELEASE} | sed -e 's/^[VTX]//' | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' 'abcdefghijklmnopqrstuvwxyz'`
	exit 0 ;;
    Alpha\ *:Windows_NT*:*)
	# How do we know it's Interix rather than the generic POSIX subsystem?
	# Should we change UNAME_MACHINE based on the output of uname instead
	# of the specific Alpha model?
	echo alpha-pc-interix
	exit 0 ;;
    21064:Windows_NT:50:3)
	echo alpha-dec-winnt3.5
	exit 0 ;;
    Amiga*:UNIX_System_V:4.0:*)
	echo m68k-unknown-sysv4
	exit 0;;
    amiga:OpenBSD:*:*)
	echo m68k-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    *:[Aa]miga[Oo][Ss]:*:*)
	echo ${UNAME_MACHINE}-unknown-amigaos
	exit 0 ;;
    arc64:OpenBSD:*:*)
	echo mips64el-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    arc:OpenBSD:*:*)
	echo mipsel-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    hkmips:OpenBSD:*:*)
	echo mips-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    pmax:OpenBSD:*:*)
	echo mipsel-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    sgi:OpenBSD:*:*)
	echo mips-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    wgrisc:OpenBSD:*:*)
	echo mipsel-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    *:OS/390:*:*)
	echo i370-ibm-openedition
	exit 0 ;;
    arm:RISC*:1.[012]*:*|arm:riscix:1.[012]*:*)
	echo arm-acorn-riscix${UNAME_RELEASE}
	exit 0;;
    SR2?01:HI-UX/MPP:*:* | SR8000:HI-UX/MPP:*:*)
	echo hppa1.1-hitachi-hiuxmpp
	exit 0;;
    Pyramid*:OSx*:*:* | MIS*:OSx*:*:* | MIS*:SMP_DC-OSx*:*:*)
	# akee@wpdis03.wpafb.af.mil (Earle F. Ake) contributed MIS and NILE.
	if test "`(/bin/universe) 2>/dev/null`" = att ; then
		echo pyramid-pyramid-sysv3
