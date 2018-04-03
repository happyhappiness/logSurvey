 	elif test "${UNAME_MACHINE}" = "mips" ; then
 	  cat >$dummy.c <<EOF
 #ifdef __cplusplus
+#include <stdio.h>  /* for printf() prototype */
 	int main (int argc, char *argv[]) {
 #else
 	int main (argc, argv) int argc; char *argv[]; {
