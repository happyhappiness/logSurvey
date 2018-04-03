 static void
 dump_refreshpattern(StoreEntry * entry, const char *name, refresh_t * head)
 {
-    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
+    while (head != NULL) {
+	storeAppendPrintf(entry, "%s %s %d %d%% %d\n",
+	    name, head->pattern,
+	    (int) head->min, head->pct, (int) head->max);
+	head = head->next;
+    }
 }
 
 static void
