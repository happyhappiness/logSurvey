     }
 
 #else
-    fatal("Failed to allocate TLS client context: No TLS library\n");
+    debugs(83, 1, "WARNING: Failed to allocate TLS client context: No TLS library");
 
 #endif
 
