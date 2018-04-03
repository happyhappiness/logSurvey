 int
 getMyPort(void)
 {
-    if (Config.Sockaddr.http)
-        return Config.Sockaddr.http->s.GetPort();
+    if (Config.Sockaddr.http) {
+        // skip any special mode ports
+        http_port_list *p = Config.Sockaddr.http;
+        while(p->intercepted || p->accel || p->spoof_client_ip)
+            p = p->next;
+        if (p)
+            return p->s.GetPort();
+    }
 
 #if USE_SSL
-
     if (Config.Sockaddr.https)
         return Config.Sockaddr.https->http.s.GetPort();
-
 #endif
 
-    fatal("No port defined");
-
-    return 0;			/* NOT REACHED */
+    debugs(21, DBG_CRITICAL, "ERROR: No forward-proxy ports configured.");
+    return 0; // Invalid port. This will result in invalid URLs on bad configurations.
 }
 
 /*