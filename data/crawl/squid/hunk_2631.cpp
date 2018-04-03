     if (i <= 0)
         fatal("UFSSwapDir::parseSizeL1L2: invalid size value");
 
-    size_t size = i << 10;		/* Mbytes to kbytes */
+    const uint64_t size = i << 20; // MBytes to Bytes
 
     /* just reconfigure it */
     if (reconfiguring) {
-        if (size == max_size)
-            debugs(3, 2, "Cache dir '" << path << "' size remains unchanged at " << size << " KB");
+        if (size == maxSize())
+            debugs(3, 2, "Cache dir '" << path << "' size remains unchanged at " << i << " MB");
         else
-            debugs(3, 1, "Cache dir '" << path << "' size changed to " << size << " KB");
+            debugs(3, 1, "Cache dir '" << path << "' size changed to " << i << " MB");
     }
 
     max_size = size;
