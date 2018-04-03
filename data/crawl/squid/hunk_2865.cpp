 }
 
 bool
-SwapDir::optionMaxSizeParse(char const *option, const char *value, int isaReconfig)
+SwapDir::optionObjectSizeParse(char const *option, const char *value, int isaReconfig)
 {
-    if (strcmp(option, "max-size") != 0)
+    int64_t *val;
+    if (strcmp(option, "max-size") == 0) {
+        val = &max_objsize;
+    } else if (strcmp(option, "min-size") == 0) {
+        val = &min_objsize;
+    } else
         return false;
 
     if (!value)
         self_destruct();
 
     int64_t size = strtoll(value, NULL, 10);
 
-    if (isaReconfig && max_objsize != size)
-        debugs(3, 1, "Cache dir '" << path << "' max object size now " << size);
+    if (isaReconfig && *val != size)
+        debugs(3, 1, "Cache dir '" << path << "' object " << option << " now " << size);
 
-    max_objsize = size;
+    *val = size;
 
     return true;
 }
 
 void
-SwapDir::optionMaxSizeDump(StoreEntry * e) const
+SwapDir::optionObjectSizeDump(StoreEntry * e) const
 {
+    if (min_objsize != -1)
+        storeAppendPrintf(e, " min-size=%"PRId64, min_objsize);
+
     if (max_objsize != -1)
         storeAppendPrintf(e, " max-size=%"PRId64, max_objsize);
 }
