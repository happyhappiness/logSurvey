 void
 Rock::SwapDir::parseSize()
 {
-    max_size = GetInteger() << 10; // MBytes to KBytes
-    if (max_size < 0)
+    const int i = GetInteger();
+    if (i < 0)
         fatal("negative Rock cache_dir size value");
+    max_size = i << 20; // MBytes to Bytes
 }
 
 /// check the results of the configuration; only level-0 debugging works here
