 static void
 dump_cachemgrpasswd(StoreEntry * entry, const char *name, cachemgr_passwd * list)
 {
-    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
+    wordlist *w;
+    while (list != NULL) {
+	storeAppendPrintf(entry, "%s XXXXXXXXXX", name);
+	for (w = list->actions; w != NULL; w = w->next) {
+	    storeAppendPrintf(entry, " %s", w->key);
+	}
+	storeAppendPrintf(entry, "\n");
+	list = list->next;
+    }
 }
 
 static void
