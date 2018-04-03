     /* build uri in mb */
     static MemBuf mb;
 
-    memBufReset(&mb);
+    mb.reset();
 
-    memBufPrintf(&mb, "http://%s", lc_host);
+    mb.Printf("http://%s", lc_host);
 
     /* append port if not default */
     if (port && port != urlDefaultPort(PROTO_HTTP))
-        memBufPrintf(&mb, ":%d", port);
+        mb.Printf(":%d", port);
 
     if (dir)
-        memBufPrintf(&mb, "%s", dir);
+        mb.Printf("%s", dir);
 
-    memBufPrintf(&mb, "%s", name);
+    mb.Printf("%s", name);
 
     /* return a pointer to a local static buffer */
     return mb.buf;
