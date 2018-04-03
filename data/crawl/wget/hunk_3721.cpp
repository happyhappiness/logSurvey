     VAX*:ULTRIX*:*:*)
 	echo vax-dec-ultrix${UNAME_RELEASE}
 	exit 0 ;;
+    2020:CLIX:*:* | 2430:CLIX:*:*)
+	echo clipper-intergraph-clix${UNAME_RELEASE}
+	exit 0 ;;
     mips:*:*:UMIPS | mips:*:*:RISCos)
-	sed 's/^	//' << EOF >dummy.c
-	int main (argc, argv) int argc; char **argv; {
+	sed 's/^	//' << EOF >$dummy.c
+#ifdef __cplusplus
+#include <stdio.h>  /* for printf() prototype */
+	int main (int argc, char *argv[]) {
+#else
+	int main (argc, argv) int argc; char *argv[]; {
+#endif
 	#if defined (host_mips) && defined (MIPSEB)
 	#if defined (SYSTYPE_SYSV)
 	  printf ("mips-mips-riscos%ssysv\n", argv[1]); exit (0);
