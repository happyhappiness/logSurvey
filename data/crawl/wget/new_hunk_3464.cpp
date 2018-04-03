	echo ${UNAME_MACHINE}-unknown-linux-gnu
	exit 0 ;;
    mips:Linux:*:*)
	case `sed -n '/^byte/s/^.*: \(.*\) endian/\1/p' < /proc/cpuinfo` in
	  big)    echo mips-unknown-linux-gnu && exit 0 ;;
	  little) echo mipsel-unknown-linux-gnu && exit 0 ;;
	esac
	;;
    ppc:Linux:*:*)
	echo powerpc-unknown-linux-gnu
	exit 0 ;;
    ppc64:Linux:*:*)
	echo powerpc64-unknown-linux-gnu
	exit 0 ;;
    alpha:Linux:*:*)
	case `sed -n '/^cpu model/s/^.*: \(.*\)/\1/p' < /proc/cpuinfo` in
	  EV5)   UNAME_MACHINE=alphaev5 ;;
	  EV56)  UNAME_MACHINE=alphaev56 ;;
	  PCA56) UNAME_MACHINE=alphapca56 ;;
	  PCA57) UNAME_MACHINE=alphapca56 ;;
	  EV6)   UNAME_MACHINE=alphaev6 ;;
	  EV67)  UNAME_MACHINE=alphaev67 ;;
	  EV68*) UNAME_MACHINE=alphaev68 ;;
        esac
	objdump --private-headers /bin/sh | grep ld.so.1 >/dev/null
	if test "$?" = 0 ; then LIBC="libc1" ; else LIBC="" ; fi
	echo ${UNAME_MACHINE}-unknown-linux-gnu${LIBC}
	exit 0 ;;
    parisc:Linux:*:* | hppa:Linux:*:*)
