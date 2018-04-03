 #define SQUID_DEBUG
 
 #include <iostream>
+#undef assert
 #include <sstream>
+#if defined assert
+#undef assert
+#endif
+#if PURIFY
+#define assert(EX) ((void)0)
+#elif defined(NODEBUG)
+#define assert(EX) ((void)0)
+#elif STDC_HEADERS
+#define assert(EX)  ((EX)?((void)0):xassert( # EX , __FILE__, __LINE__))
+#else
+#define assert(EX)  ((EX)?((void)0):xassert("EX", __FILE__, __LINE__))
+#endif
 
 class Debug
 {
