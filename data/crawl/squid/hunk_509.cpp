 #include "squid.h"
 #include "fatal.h"
 
-/* Stub File for the ssl/libsslutil.la convenience library */
+/* Unused (XXX) Stub File for the ssl/libsslutil.la convenience library */
 
-#define STUB_BASE "ssl/libsslutil.la"
-
-#define STUB { fatal(STUB_BASE " required."); }
-#define STUB_RETVAL(x) { fatal(STUB_BASE " required."); return (x); }
-#define STUB_RETREF(x) { fatal(STUB_BASE " required."); static x v; return v; }
-#define STUB_RETREF2(x,y) { fatal(STUB_BASE " required."); static x v((y)); return v; }
+#define STUB_API "ssl/libsslutil.la"
+#include "tests/STUB.h"
 
 #include "ssl/crtd_message.h"
 Ssl::CrtdMessage::CrtdMessage() STUB
