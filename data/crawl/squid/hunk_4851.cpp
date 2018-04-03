     MemAllocator *pool;
 
     /* caption */
-    storeAppendPrintf(e, "Current memory usage:\n");
+    stream << "Current memory usage:\n";
     /* heading */
-    storeAppendPrintf(e,
-                      "Pool\t Obj Size\t"
-                      "Chunks\t\t\t\t\t\t\t"
-                      "Allocated\t\t\t\t\t"
-                      "In Use\t\t\t\t\t"
-                      "Idle\t\t\t"
-                      "Allocations Saved\t\t\t"
-                      "Hit Rate\t"
-                      "\n"
-                      " \t (bytes)\t"
-                      "KB/ch\t obj/ch\t"
-                      "(#)\t used\t free\t part\t %%Frag\t "
-                      "(#)\t (KB)\t high (KB)\t high (hrs)\t %%Tot\t"
-                      "(#)\t (KB)\t high (KB)\t high (hrs)\t %%alloc\t"
-                      "(#)\t (KB)\t high (KB)\t"
-                      "(#)\t %%cnt\t %%vol\t"
-                      "(#) / sec\t"
-                      "\n");
+    stream << "Pool\t Obj Size\t"
+    "Chunks\t\t\t\t\t\t\t"
+    "Allocated\t\t\t\t\t"
+    "In Use\t\t\t\t\t"
+    "Idle\t\t\t"
+    "Allocations Saved\t\t\t"
+    "Hit Rate\t"
+    "\n"
+    " \t (bytes)\t"
+    "KB/ch\t obj/ch\t"
+    "(#)\t used\t free\t part\t %%Frag\t "
+    "(#)\t (KB)\t high (KB)\t high (hrs)\t %%Tot\t"
+    "(#)\t (KB)\t high (KB)\t high (hrs)\t %%alloc\t"
+    "(#)\t (KB)\t high (KB)\t"
+    "(#)\t %%cnt\t %%vol\t"
+    "(#) / sec\t"
+    "\n";
     xm_deltat = current_dtime - xm_time;
     xm_time = current_dtime;
 
