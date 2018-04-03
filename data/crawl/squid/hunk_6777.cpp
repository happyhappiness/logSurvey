 static void
 dump_regexlist(StoreEntry * entry, const char *name, relist * var)
 {
-    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
+    storeAppendPrintf(entry, "%s", name);
+    while (var != NULL) {
+	storeAppendPrintf(entry, " %s", var->pattern);
+	var = var->next;
+    }
+    storeAppendPrintf(entry, "\n");
 }
 
 static void