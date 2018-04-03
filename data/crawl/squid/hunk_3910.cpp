 #include "config.h"
 
 SQUIDCEXTERN void fatal(const char *message);
-#if STDC_HEADERS
-SQUIDCEXTERN void
-fatalf(const char *fmt,...) PRINTF_FORMAT_ARG1;
-#else
-SQUIDCEXTERN void fatalf();
-#endif
+SQUIDCEXTERN void fatalf(const char *fmt,...) PRINTF_FORMAT_ARG1;
 SQUIDCEXTERN void fatal_dump(const char *message);
 
 #endif
