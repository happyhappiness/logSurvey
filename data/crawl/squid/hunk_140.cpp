 static void
 dump_cachemgrpasswd(StoreEntry * entry, const char *name, Mgr::ActionPasswordList * list)
 {
-    wordlist *w;
-
-    while (list != NULL) {
+    while (list) {
         if (strcmp(list->passwd, "none") && strcmp(list->passwd, "disable"))
             storeAppendPrintf(entry, "%s XXXXXXXXXX", name);
         else
             storeAppendPrintf(entry, "%s %s", name, list->passwd);
 
-        for (w = list->actions; w != NULL; w = w->next) {
-            storeAppendPrintf(entry, " %s", w->key);
-        }
+        for (auto w : list->actions)
+            entry->appendf(" " SQUIDSBUFPH, SQUIDSBUFPRINT(w));
 
         storeAppendPrintf(entry, "\n");
         list = list->next;
