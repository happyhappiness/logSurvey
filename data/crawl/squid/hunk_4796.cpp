                           (int) http->start.tv_usec,
                           tvSubDsec(http->start, current_time));
 
-        if (http->request->auth_user_request) {
-            const char *p;
-
+        if (http->request->auth_user_request)
             p = http->request->auth_user_request->username();
+        else if (http->request->extacl_user.buf() != NULL) {
+            p = http->request->extacl_user.buf();
+        }
 
-            if (!p)
-                p = "-";
+        if (!p && (conn.getRaw() != NULL && conn->rfc931[0]))
+            p = conn->rfc931;
 
-            storeAppendPrintf(s, "username %s\n", p);
-        }
+#if USE_SSL
+
+        if (!p && conn.getRaw() != NULL)
+            p = sslGetUserEmail(fd_table[conn->fd].ssl);
+
+#endif
+
+        if (!p)
+            p = dash_str;
+
+        storeAppendPrintf(s, "username %s\n", p);
 
 #if DELAY_POOLS
+
         storeAppendPrintf(s, "delay_pool %d\n", DelayId::DelayClient(http) >> 16);
 
 #endif