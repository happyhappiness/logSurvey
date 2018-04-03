 
 #include "makeint.h"
 
+#ifdef TEST
+/* Hack, the real error() routine eventually pulls in die from main.c */
+#define error(a, b, c, d)
+#endif
+
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #else
