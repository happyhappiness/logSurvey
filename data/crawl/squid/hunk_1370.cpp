     }
 }
 
-void
-Auth::Config::dump(StoreEntry *entry, const char *name, Auth::Config *scheme)
+bool
+Auth::Config::dump(StoreEntry *entry, const char *name, Auth::Config *scheme) const
 {
+    if (!authenticateProgram)
+        return false; // not configured
+
+    wordlist *list = authenticateProgram;
+    storeAppendPrintf(entry, "%s %s", name, scheme->type());
+    while (list != NULL) {
+        storeAppendPrintf(entry, " %s", list->key);
+        list = list->next;
+    }
+    storeAppendPrintf(entry, "\n");
+
     storeAppendPrintf(entry, "%s %s realm " SQUIDSBUFPH "\n", name, scheme->type(), SQUIDSBUFPRINT(realm));
 
     storeAppendPrintf(entry, "%s %s children %d startup=%d idle=%d concurrency=%d\n",
