     static MemBuf mb;
 
     mb.reset();
-
-    mb.Printf("http://%s", lc_host);
+    mb.appendf("http://%s", lc_host);
 
     /* append port if not default */
     if (port && port != urlDefaultPort(AnyP::PROTO_HTTP))
-        mb.Printf(":%d", port);
+        mb.appendf(":%u", port);
 
     if (dir)
-        mb.Printf("%s", dir);
+        mb.append(dir, strlen(dir));
 
-    mb.Printf("%s", name);
+    mb.append(name, strlen(name));
 
     /* return a pointer to a local static buffer */
     return mb.buf;
