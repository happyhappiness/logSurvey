    *:ITS:*:*)
	echo pdp10-unknown-its
	exit 0 ;;
    SEI:*:*:SEIUX)
        echo mips-sei-seiux${UNAME_RELEASE}
	exit 0 ;;
    *:DragonFly:*:*)
	echo ${UNAME_MACHINE}-unknown-dragonfly`echo ${UNAME_RELEASE}|sed -e 's/[-(].*//'`
	exit 0 ;;
    *:*VMS:*:*)
    	UNAME_MACHINE=`(uname -p) 2>/dev/null`
	case "${UNAME_MACHINE}" in
	    A*) echo alpha-dec-vms && exit 0 ;;
	    I*) echo ia64-dec-vms && exit 0 ;;
	    V*) echo vax-dec-vms && exit 0 ;;
	esac
esac

#echo '(No uname command or uname output not recognized.)' 1>&2
