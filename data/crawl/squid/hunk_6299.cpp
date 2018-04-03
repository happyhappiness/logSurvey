 dump_refreshpattern(StoreEntry * entry, const char *name, refresh_t * head)
 {
     while (head != NULL) {
-	storeAppendPrintf(entry, "%s%s %s %d %d%% %d%s%s%s%s\n",
+	storeAppendPrintf(entry, "%s%s %s %d %d%% %d\n",
 	    name,
 	    head->flags.icase ? " -i" : null_string,
 	    head->pattern,
 	    (int) head->min / 60,
 	    (int) (100.0 * head->pct + 0.5),
-	    (int) head->max / 60,
-	    head->flags.override_expire ? " override-expire" : null_string,
-	    head->flags.override_lastmod ? " override-lastmod" : null_string,
-	    head->flags.reload_into_ims ? " reload-into-ims" : null_string,
-	    head->flags.ignore_reload ? " ignore-reload" : null_string);
+	    (int) head->max / 60);
+#if HTTP_VIOLATIONS
+	if (head->flags.override_expire)
+	    storeAppendPrintf(entry, " override-expire");
+	if (head->flags.override_lastmod)
+	    storeAppendPrintf(entry, " override-lastmod");
+	if (head->flags.reload_into_ims)
+	    storeAppendPrintf(entry, " reload-into-ims");
+	if (head->flags.ignore_reload)
+	    storeAppendPrintf(entry, " ignore-reload");
+#endif
+	storeAppendPrintf(entry, "\n");
 	head = head->next;
     }
 }
