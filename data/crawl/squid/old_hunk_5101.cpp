        # Use sysv4.2uw... so that sysv4* matches it.
	echo ${UNAME_MACHINE}-pc-sysv4.2uw${UNAME_VERSION}
	exit 0 ;;
    i*86:*:4.*:* | i*86:SYSTEM_V:4.*:*)
	UNAME_REL=`echo ${UNAME_RELEASE} | sed 's/\/MP$//'`
	if grep Novell /usr/include/link.h >/dev/null 2>/dev/null; then
