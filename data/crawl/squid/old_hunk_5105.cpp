    *:ITS:*:*)
	echo pdp10-unknown-its
	exit 0 ;;
    i*86:XTS-300:*:STOP)
	echo ${UNAME_MACHINE}-unknown-stop
	exit 0 ;;
    i*86:atheos:*:*)
	echo ${UNAME_MACHINE}-unknown-atheos
	exit 0 ;;
esac

#echo '(No uname command or uname output not recognized.)' 1>&2
