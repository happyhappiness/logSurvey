 	esac
 	# Determine whether the default compiler is a.out or elf
 	eval $set_cc_for_build
-	cat >$dummy.c <<EOF
-#include <features.h>
-#ifdef __cplusplus
-#include <stdio.h>  /* for printf() prototype */
-	int main (int argc, char *argv[]) {
-#else
-	int main (argc, argv) int argc; char *argv[]; {
-#endif
-#ifdef __ELF__
-# ifdef __GLIBC__
-#  if __GLIBC__ >= 2
-    printf ("%s-pc-linux-gnu\n", argv[1]);
-#  else
-    printf ("%s-pc-linux-gnulibc1\n", argv[1]);
-#  endif
-# else
-   printf ("%s-pc-linux-gnulibc1\n", argv[1]);
-# endif
-#else
-  printf ("%s-pc-linux-gnuaout\n", argv[1]);
-#endif
-  return 0;
-}
+	sed 's/^	//' << EOF >$dummy.c
+	#include <features.h>
+	#ifdef __ELF__
+	# ifdef __GLIBC__
+	#  if __GLIBC__ >= 2
+	LIBC=gnu
+	#  else
+	LIBC=gnulibc1
+	#  endif
+	# else
+	LIBC=gnulibc1
+	# endif
+	#else
+	#ifdef __INTEL_COMPILER
+	LIBC=gnu
+	#else
+	LIBC=gnuaout
+	#endif
+	#endif
 EOF
-	$CC_FOR_BUILD $dummy.c -o $dummy 2>/dev/null && ./$dummy "${UNAME_MACHINE}" && rm -f $dummy.c $dummy && exit 0
-	rm -f $dummy.c $dummy
+	eval `$CC_FOR_BUILD -E $dummy.c 2>/dev/null | grep ^LIBC=`
+	rm -f $dummy.c && rmdir $tmpdir
+	test x"${LIBC}" != x && echo "${UNAME_MACHINE}-pc-linux-${LIBC}" && exit 0
 	test x"${TENTATIVE}" != x && echo "${TENTATIVE}" && exit 0
 	;;
     i*86:DYNIX/ptx:4*:*)
