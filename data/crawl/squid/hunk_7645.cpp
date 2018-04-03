 	fatal_dump("Private key already exists.");
     }
     if (e->key)
-	storeHashDelete((hash_link *) e);
+	storeHashDelete(e);
     if (e->key && !BIT_TEST(e->flag, KEY_URL))
 	safe_free(e->key);
     e->key = xstrdup(newkey);
