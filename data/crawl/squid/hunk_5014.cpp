 
 #include "DiskIO/DiskDaemon/diomsg.h"
 
-#undef assert
-#include <assert.h>
+void
+xassert(const char *msg, const char *file, int line)
+{
+    fprintf(stderr,"assertion failed: %s:%d: \"%s\"\n", file, line, msg);
 
+    abort();
+}
 
 const int diomsg::msg_snd_rcv_sz = sizeof(diomsg) - sizeof(mtyp_t);
 #define DEBUG(LEVEL) if ((LEVEL) <= DebugLevel)
