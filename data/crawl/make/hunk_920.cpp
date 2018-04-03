     mips:*:*:UMIPS | mips:*:*:RISCos)
 	sed 's/^	//' << EOF >$dummy.c
 #ifdef __cplusplus
+#include <stdio.h>  /* for printf() prototype */
 	int main (int argc, char *argv[]) {
 #else
 	int main (argc, argv) int argc; char *argv[]; {
