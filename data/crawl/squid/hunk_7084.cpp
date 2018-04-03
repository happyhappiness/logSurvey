 }
 
 static void
-dump_string(char *var)
+dump_string(StoreEntry *entry, const char *name, char *var)
 {
-    printf("%s", var);
+    if (var != NULL)
+        storeAppendPrintf(entry, "%s %s\n", name, var);
 }
 
 static void
