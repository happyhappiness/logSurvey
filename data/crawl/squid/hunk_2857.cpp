  *
  */
 
-#include "squid.h"
+#include "config.h"
+#include "AccessLogEntry.h"
+#include "HttpRequest.h"
 #include "log/File.h"
+#include "log/Formats.h"
 #include "SquidTime.h"
 
-#if USE_REFERER_LOG
-static Logfile *refererlog = NULL;
-#endif
-
 void
-refererOpenLog(void)
+Log::Format::SquidReferer(AccessLogEntry *al, Logfile *logfile)
 {
-#if USE_REFERER_LOG
-    assert(NULL == refererlog);
+    const char *referer = al->request->header.getStr(HDR_REFERER);
 
-    if (!Config.Log.referer || (0 == strcmp(Config.Log.referer, "none"))) {
-        debugs(40, 1, "Referer logging is disabled.");
+    // do not log unless there is something to be displayed
+    if (!referer || *referer == '\0')
         return;
-    }
-
-    refererlog = logfileOpen(Config.Log.referer, 0, 1);
-#endif
-}
 
-void
-refererRotateLog(void)
-{
-#if USE_REFERER_LOG
-
-    if (NULL == refererlog)
-        return;
-
-    logfileRotate(refererlog);
-
-#endif
-}
-
-void
-logReferer(const char *client, const char *referer, const char *uri)
-{
-#if USE_REFERER_LOG
+    char clientip[MAX_IPSTRLEN];
 
-    if (NULL == refererlog)
-        return;
-
-    logfilePrintf(refererlog, "%9d.%03d %s %s %s\n",
-                  (int) current_time.tv_sec,
+    logfilePrintf(logfile, "%9ld.%03d %s %s %s\n",
+                  (long int) current_time.tv_sec,
                   (int) current_time.tv_usec / 1000,
-                  client,
+                  al->cache.caddr.NtoA(clientip, MAX_IPSTRLEN),
                   referer,
-                  uri ? uri : "-");
-
-#endif
-}
-
-void
-refererCloseLog(void)
-{
-#if USE_REFERER_LOG
-
-    if (NULL == refererlog)
-        return;
-
-    logfileClose(refererlog);
-
-    refererlog = NULL;
-
-#endif
+                  al->url ? al->url : "-");
 }
