 {
     StoreEntry *e2 = NULL;
     hash_link *table_entry = NULL;
+    char *newkey = NULL;
 
     if (e->key && BIT_TEST(e->flag, KEY_PRIVATE))
 	return;			/* is already private */
 
-    if (e->key) {
-	if ((table_entry = hash_lookup(table, e->key)))
-	    e2 = (StoreEntry *) table_entry;
-	if (e2 != e) {
-	    debug(20, 0, "storeSetPrivateKey: non-unique key: '%s'\n", e->key);
-	    return;
-	}
-	storeHashDelete(table_entry);
-	if (!BIT_TEST(e->flag, KEY_URL))
-	    safe_free(e->key);
+    newkey = storeGeneratePrivateKey(e->url, e->type_id, 0);
+    if ((table_entry = hash_lookup(table, newkey))) {
+	e2 = (StoreEntry *) table_entry;
+	debug(20, 0, "storeSetPrivateKey: Entry already exists with key '%s'\n",
+	    newkey);
+	debug(20, 0, "storeSetPrivateKey: Entry Dump:\n%s\n", storeToString(e2));
+	fatal_dump("Private key already exists.");
     }
-    e->key = xstrdup(storeGeneratePrivateKey(e->url, e->type_id, 0));
+    if (e->key)
+	storeHashDelete(e);
+    if (e->key && !BIT_TEST(e->flag, KEY_URL))
+	safe_free(e->key);
+    e->key = xstrdup(newkey);
     storeHashInsert(e);
     BIT_RESET(e->flag, KEY_URL);
     BIT_SET(e->flag, KEY_CHANGE);
