   return true;
 }
 
+#define _CHECK_CERT(flag,msg) \
+  if (status & (flag))\
+    {\
+      logprintf (LOG_NOTQUIET, (msg),\
+                 severity, quote (host));\
+      success = false;\
+    }
+
 bool
 ssl_check_certificate (int fd, const char *host)
 {
