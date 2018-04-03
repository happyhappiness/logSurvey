 #pragma implementation
 #endif
 
-#include "config.h"
-#include "signal.hh"
-
-//#include <sys/types.h>
+#include <sys/types.h>
 #include <errno.h>
 #include <string.h>
 #include <memory.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/wait.h>
-//#include <signal.h>
+#include <signal.h>
+
+#include "signal.hh"
+
+static const char* RCS_ID =
+    "$Id$";
+
+#ifndef HAS_PSIGNAL
+#ifdef AIX
+extern const char* const sys_siglist[];
+#define _sys_nsig 64
+#define _sys_siglist sys_siglist
+#endif // AIX
+
+void
+psignal( int sig, const char* msg )
+// purpose: print message, colon, space, signal name and LF.
+// paramtr: sig (IN): signal number
+//          msg (IN): message to prepend
+{
+    if ( msg && *msg ) fprintf( stderr, "%s: ", msg );
+    if ( sig > 0 && sig < _sys_nsig )
+        fprintf( stderr, "%s\n", _sys_siglist[sig] );
+    else
+        fputs( "(unknown)\n", stderr );
+}
+#endif // !HAS_PSIGNAL
 
 SigFunc*
 Signal( int signo, SigFunc* newhandler, bool doInterrupt )
