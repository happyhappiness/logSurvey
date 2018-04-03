 #include "snprintf.h"
 
 #define RFC1035_MAXLABELSZ 63
+#define rfc1035_unpack_error 15
+
+#if 0
+#define RFC1035_UNPACK_DEBUG  fprintf(stderr, "unpack error at %s:%d\n", __FILE__,__LINE__)
+#else
+#define RFC1035_UNPACK_DEBUG  (void)0
+#endif
+
 
 typedef struct _rfc1035_header rfc1035_header;
 
