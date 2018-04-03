    mvmeppc:OpenBSD:*:*)
	echo powerpc-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    sgi:OpenBSD:*:*)
	echo mips64-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    sun3:OpenBSD:*:*)
	echo m68k-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    *:OpenBSD:*:*)
	echo ${UNAME_MACHINE}-unknown-openbsd${UNAME_RELEASE}
	exit 0 ;;
    *:ekkoBSD:*:*)
	echo ${UNAME_MACHINE}-unknown-ekkobsd${UNAME_RELEASE}
	exit 0 ;;
    macppc:MirBSD:*:*)
	echo powerppc-unknown-mirbsd${UNAME_RELEASE}
	exit 0 ;;
    *:MirBSD:*:*)
	echo ${UNAME_MACHINE}-unknown-mirbsd${UNAME_RELEASE}
	exit 0 ;;
    alpha:OSF1:*:*)
	case $UNAME_RELEASE in
	*4.0)
		UNAME_RELEASE=`/usr/sbin/sizer -v | awk '{print $3}'`
		;;
	*5.*)
	        UNAME_RELEASE=`/usr/sbin/sizer -v | awk '{print $4}'`
		;;
	esac
	# According to Compaq, /usr/sbin/psrinfo has been available on
	# OSF/1 and Tru64 systems produced since 1995.  I hope that
	# covers most systems running today.  This code pipes the CPU
	# types through head -n 1, so we only detect the type of CPU 0.
	ALPHA_CPU_TYPE=`/usr/sbin/psrinfo -v | sed -n -e 's/^  The alpha \(.*\) processor.*$/\1/p' | head -n 1`
	case "$ALPHA_CPU_TYPE" in
	    "EV4 (21064)")
		UNAME_MACHINE="alpha" ;;
	    "EV4.5 (21064)")
		UNAME_MACHINE="alpha" ;;
	    "LCA4 (21066/21068)")
		UNAME_MACHINE="alpha" ;;
	    "EV5 (21164)")
		UNAME_MACHINE="alphaev5" ;;
	    "EV5.6 (21164A)")
		UNAME_MACHINE="alphaev56" ;;
	    "EV5.6 (21164PC)")
		UNAME_MACHINE="alphapca56" ;;
	    "EV5.7 (21164PC)")
		UNAME_MACHINE="alphapca57" ;;
	    "EV6 (21264)")
		UNAME_MACHINE="alphaev6" ;;
	    "EV6.7 (21264A)")
		UNAME_MACHINE="alphaev67" ;;
	    "EV6.8CB (21264C)")
		UNAME_MACHINE="alphaev68" ;;
	    "EV6.8AL (21264B)")
		UNAME_MACHINE="alphaev68" ;;
	    "EV6.8CX (21264D)")
		UNAME_MACHINE="alphaev68" ;;
	    "EV6.9A (21264/EV69A)")
		UNAME_MACHINE="alphaev69" ;;
	    "EV7 (21364)")
		UNAME_MACHINE="alphaev7" ;;
	    "EV7.9 (21364A)")
		UNAME_MACHINE="alphaev79" ;;
	esac
	# A Pn.n version is a patched version.
	# A Vn.n version is a released version.
	# A Tn.n version is a released field test version.
	# A Xn.n version is an unreleased experimental baselevel.
	# 1.2 uses "1.2" for uname -r.
	echo ${UNAME_MACHINE}-dec-osf`echo ${UNAME_RELEASE} | sed -e 's/^[PVTX]//' | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' 'abcdefghijklmnopqrstuvwxyz'`
	exit 0 ;;
    Alpha\ *:Windows_NT*:*)
	# How do we know it's Interix rather than the generic POSIX subsystem?
