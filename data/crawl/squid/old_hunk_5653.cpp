		exit 0 ;;
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
    printf ("%s-pc-linux-gnu\n", argv[1]);
#  else
    printf ("%s-pc-linux-gnulibc1\n", argv[1]);
#  endif
# else
   printf ("%s-pc-linux-gnulibc1\n", argv[1]);
# endif
#else
  printf ("%s-pc-linux-gnuaout\n", argv[1]);
#endif
  return 0;
}
EOF
	eval $set_cc_for_build
	$CC_FOR_BUILD $dummy.c -o $dummy 2>/dev/null && ./$dummy "${UNAME_MACHINE}" && rm -f $dummy.c $dummy && exit 0
	rm -f $dummy.c $dummy
	test x"${TENTATIVE}" != x && echo "${TENTATIVE}" && exit 0
	;;
    i*86:DYNIX/ptx:4*:*)
