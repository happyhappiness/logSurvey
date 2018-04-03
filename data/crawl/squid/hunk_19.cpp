 #define STUB_API "fatal.cc"
 #include "tests/STUB.h"
 
-void fatal(const char *message) STUB
-void fatal_common(const char *message) STUB
-void fatalf(const char *fmt,...) STUB
-void fatalvf(const char *fmt, va_list args) STUB
-void fatal_dump(const char *message) STUB
+void fatal(const char *) STUB
+void fatal_common(const char *) STUB
+void fatalf(const char *, ...) STUB
+void fatalvf(const char *, va_list) STUB
+void fatal_dump(const char *) STUB
 
