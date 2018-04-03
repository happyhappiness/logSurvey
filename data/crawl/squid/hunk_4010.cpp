     }
 }
 
+/**
+ * NOTE: Due to the low-level nature of the library these
+ * objects are part of the dump function must be self-contained.
+ * which means no StoreEntry refrences. Just a basic char* buffer.
+ */
 void
-QosConfig::dumpConfigLine(StoreEntry * entry, const char *name) const
+QosConfig::dumpConfigLine(char *entry, const char *name) const
 {
-    storeAppendPrintf(entry, "%s", name);
+    char *p = entry;
+    snprintf(p, 10, "%s", name); // strlen("qos_flows ");
+    p += strlen(name);
 
     if (tos_local_hit >0) {
-        storeAppendPrintf(entry, " local-hit=%2x", tos_local_hit);
+        snprintf(p, 15, " local-hit=%2x", tos_local_hit);
+        p += 15;
     }
 
     if (tos_sibling_hit >0) {
-        storeAppendPrintf(entry, " sibling-hit=%2x", tos_sibling_hit);
+        snprintf(p, 17, " sibling-hit=%2x", tos_sibling_hit);
+        p += 17;
     }
     if (tos_parent_hit >0) {
-        storeAppendPrintf(entry, " parent-hit=%2x", tos_parent_hit);
+        snprintf(p, 16, " parent-hit=%2x", tos_parent_hit);
+        p += 16;
     }
     if (preserve_miss_tos != 0) {
-        storeAppendPrintf(entry, " disable-preserve-miss");
+        snprintf(p, 22, " disable-preserve-miss");
+        p += 22;
     }
     if (preserve_miss_tos && preserve_miss_tos_mask != 0) {
-        storeAppendPrintf(entry, " miss-mask=%2x", preserve_miss_tos_mask);
+        snprintf(p, 15, " miss-mask=%2x", preserve_miss_tos_mask);
+        p += 15;
     }
-    storeAppendPrintf(entry, "\n");
+    snprintf(p, 1, "\n");
+//    p += 1;
 }
 
 #endif /* USE_ZPH_QOS */
