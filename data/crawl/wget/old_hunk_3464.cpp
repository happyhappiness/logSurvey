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
