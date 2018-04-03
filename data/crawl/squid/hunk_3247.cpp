  *
  *
  */
-
+#include "config.h"
+#include "helpers/defines.h"
+#include "libntlmauth/support_bits.cci"
+#include "sspwin32.h"
 #include "util.h"
+
+#include <windows.h>
+#include <sspi.h>
+#include <security.h>
 #if HAVE_GETOPT_H
 #include <getopt.h>
 #endif
-#include "negotiate.h"
 #if HAVE_CTYPE_H
 #include <ctype.h>
 #endif
 
-#define BUFFER_SIZE 10240
-
-int debug_enabled = 0;
 int Negotiate_packet_debug_enabled = 0;
-
 static int have_serverblob;
 
-/* makes a null-terminated string upper-case. Changes CONTENTS! */
-void
-uc(char *string)
-{
-    char *p = string, c;
-    while ((c = *p)) {
-        *p = xtoupper(c);
-        p++;
-    }
-}
-
-/* makes a null-terminated string lower-case. Changes CONTENTS! */
-static void
-lc(char *string)
-{
-    char *p = string, c;
-    while ((c = *p)) {
-        *p = xtolower(c);
-        p++;
-    }
-}
-
-void
-helperfail(const char *reason)
-{
-#if FAIL_DEBUG
-    fail_debug_enabled = 1;
+/* A couple of harmless helper macros */
+#define SEND(X) debug("sending '%s' to squid\n",X); printf(X "\n");
+#ifdef __GNUC__
+#define SEND2(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
+#define SEND3(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
+#else
+/* no gcc, no debugging. varargs macros are a gcc extension */
+#define SEND2(X,Y) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
+#define SEND3(X,Y,Z) debug("sending '" X "' to squid\n",Y,Z); printf(X "\n",Y,Z);
 #endif
-    SEND2("BH %s", reason);
-}
+
+char *negotiate_check_auth(SSP_blobP auth, int auth_length);
 
 /*
  * options:
