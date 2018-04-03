 void
 CossSwapDir::reconfigure(int index, char *path)
 {
-    unsigned int i;
-    unsigned int size;
-
-    i = GetInteger();
-    size = i << 10;		/* Mbytes to Kbytes */
-
-    if (size <= 0)
+    const int i = GetInteger();
+    if (i <= 0)
         fatal("storeCossDirParse: invalid size value");
 
-    if (size == (size_t)max_size)
-        debugs(3, 1, "Cache COSS dir '" << path << "' size remains unchanged at " << size << " KB");
+    const uint64_t size = i << 20; // MBytes to Bytes
+
+    if (size == maxSize())
+        debugs(3, 1, "Cache COSS dir '" << path << "' size remains unchanged at " << i << " MB");
     else {
-        debugs(3, 1, "Cache COSS dir '" << path << "' size changed to " << size << " KB");
+        debugs(3, 1, "Cache COSS dir '" << path << "' size changed to " << i << " MB");
         max_size = size;
     }
 
