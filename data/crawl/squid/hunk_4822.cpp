 
 #include "config.h"
 
-#if PURIFY
-#define assert(EX) ((void)0)
-#elif defined(NODEBUG)
-#define assert(EX) ((void)0)
-#elif STDC_HEADERS
-#define assert(EX)  ((EX)?((void)0):xassert( # EX , __FILE__, __LINE__))
-#else
-#define assert(EX)  ((EX)?((void)0):xassert("EX", __FILE__, __LINE__))
-#endif
-extern void xassert(const char *, const char *, int);
+#include "assert.h"
 
 #if HAVE_UNISTD_H
 #include <unistd.h>