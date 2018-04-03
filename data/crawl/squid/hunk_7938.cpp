 	debug(0, 0, "storeChangeKey: NULL key for %s\n", e->url);
 	return;
     }
-    if (table != (HashID) 0) {
-	hash_link *table_entry = hash_lookup(table, e->key);
-	if (table_entry)
-	    result = (StoreEntry *) table_entry;
-	if (result == e) {
-	    storeHashDelete(table_entry);
-
-	    key[0] = '\0';
-	    sprintf(key, "/x%d/%s", keychange_count++, e->key);
-	    if (!(result->flag & KEY_URL))
-		safe_free(result->key);
-	    result->key = xstrdup(key);
-
-	    storeHashInsert(e);
-	    BIT_SET(result->flag, KEY_CHANGE);
-	    BIT_RESET(result->flag, KEY_URL);
-	} else {
-	    debug(0, 1, "storeChangeKey: Key is not unique for key: %s\n", e->key);
-	}
+    if (table == (HashID) 0)
+	fatal_dump("storeUnChangeKey: Hash table 'table' is zero!\n");
+
+    if ((table_entry = hash_lookup(table, e->key)))
+	result = (StoreEntry *) table_entry;
+    if (result != e) {
+	debug(0, 1, "storeChangeKey: Key is not unique for key: %s\n", e->key);
+	return;
+    }
+    storeHashDelete(table_entry);
+    key[0] = '\0';
+    sprintf(key, "/x%d/%s", keychange_count++, e->key);
+    if (!(result->flag & KEY_URL))
+	safe_free(result->key);
+    result->key = xstrdup(key);
+    storeHashInsert(e);
+    BIT_SET(result->flag, KEY_CHANGE);
+    BIT_RESET(result->flag, KEY_URL);
+}
+
+void storeUnChangeKey(e)
+     StoreEntry *e;
+{
+    StoreEntry *result = NULL;
+    static char key[MAX_URL + 32];
+    hash_link *table_entry = NULL;
+    char *t = NULL;
+
+    if (!e)
+	return;
+
+    if (e->key == NULL) {
+	debug(0, 0, "storeUnChangeKey: NULL key for %s\n", e->url);
+	return;
+    }
+    if (table == (HashID) 0)
+	fatal_dump("storeUnChangeKey: Hash table 'table' is zero!\n");
+
+    if ((table_entry = hash_lookup(table, e->key)))
+	result = (StoreEntry *) table_entry;
+    if (result != e) {
+	debug(0, 1, "storeUnChangeKey: Key is not unique for key: %s\n",
+	    e->key);
+	return;
     }
+    storeHashDelete(table_entry);
+    key[0] = '\0';
+    /* find second slash */
+    t = strchr(e->key + 1, '/');
+    if (t == NULL)
+	fatal_dump("storeUnChangeKey: Can't find a second slash.\n");
+    strcpy(key, t + 1);
+    if (!(result->flag & KEY_URL))
+	safe_free(result->key);
+    result->key = xstrdup(key);
+    storeHashInsert(e);
+    BIT_RESET(result->flag, KEY_CHANGE);
+    BIT_SET(result->flag, KEY_URL);
+    debug(0, 0, "storeUnChangeKey: Changed back to '%s'\n", key);
 }
 
 /* return if the current key is the original one. */
