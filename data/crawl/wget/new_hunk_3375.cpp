	esac
	# Determine whether the default compiler is a.out or elf
	eval $set_cc_for_build
	sed 's/^	//' << EOF >$dummy.c
	#include <features.h>
	#ifdef __ELF__
	# ifdef __GLIBC__
	#  if __GLIBC__ >= 2
	LIBC=gnu
	#  else
	LIBC=gnulibc1
	#  endif
	# else
	LIBC=gnulibc1
	# endif
	#else
	#ifdef __INTEL_COMPILER
	LIBC=gnu
	#else
	LIBC=gnuaout
	#endif
	#endif
EOF
	eval `$CC_FOR_BUILD -E $dummy.c 2>/dev/null | grep ^LIBC=`
	rm -f $dummy.c && rmdir $tmpdir
	test x"${LIBC}" != x && echo "${UNAME_MACHINE}-pc-linux-${LIBC}" && exit 0
	test x"${TENTATIVE}" != x && echo "${TENTATIVE}" && exit 0
	;;
    i*86:DYNIX/ptx:4*:*)
