 #include "config.h"
 #include "Debug.h"
 #include "SquidTime.h"
+#include "util.h"
 
-/* for Config */
-#include "structs.h"
+/* for shutting_down flag in xassert() */
+#include "globals.h"
 
+/* cope with no squid.h */
+#ifndef MAXPATHLEN
+#define MAXPATHLEN 256
+#endif
+
+char *Debug::debugOptions = NULL;
+int Debug::override_X = 0;
+int Debug::log_stderr = -1;
+bool Debug::log_syslog = false;
 int Debug::Levels[MAX_DEBUG_SECTIONS];
 int Debug::level;
+char *Debug::cache_log = NULL;
+int Debug::rotateNumber = 1;
 FILE *debug_log = NULL;
 static char *debug_log_file = NULL;
 static int Ctx_Lock = 0;
