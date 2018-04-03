                       n,
                       s->s.ToURL(buf,MAX_IPSTRLEN));
 
+    // MODES and specific sub-options.
     if (s->intercepted)
         storeAppendPrintf(e, " intercept");
 
-    if (s->spoof_client_ip)
+    else if (s->spoof_client_ip)
         storeAppendPrintf(e, " tproxy");
 
-    if (s->accel)
+    else if (s->accel) {
         storeAppendPrintf(e, " accel");
 
-    if (s->vhost)
-        storeAppendPrintf(e, " vhost");
+        if (s->vhost)
+            storeAppendPrintf(e, " vhost");
 
-    if (s->vport)
-        storeAppendPrintf(e, " vport");
+        if (s->vport < 0)
+            storeAppendPrintf(e, " vport");
+        else if (s->vport > 0)
+            storeAppendPrintf(e, " vport=%d", s->vport);
 
-    if (s->defaultsite)
-        storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);
+        if (s->defaultsite)
+            storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);
+
+        if (s->protocol && strcmp(s->protocol,"http") != 0)
+            storeAppendPrintf(e, " protocol=%s", s->protocol);
+
+        if (s->allow_direct)
+            storeAppendPrintf(e, " allow-direct");
+
+        if (s->ignore_cc)
+            storeAppendPrintf(e, " ignore-cc");
+
+    }
+
+    // Generic independent options
+
+    if (s->name)
+        storeAppendPrintf(e, " name=%s", s->name);
+
+#if !USE_HTTP_VIOLATIONS
+    if (!s->accel && s->ignore_cc)
+        storeAppendPrintf(e, " ignore-cc");
+#endif
 
     if (s->connection_auth_disabled)
         storeAppendPrintf(e, " connection-auth=off");
