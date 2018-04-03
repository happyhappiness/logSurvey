 	fatal_dump("Private key already exists.");
     }
     if (e->key)
-	storeHashDelete(e);
+	storeHashDelete((hash_link *) e);
     if (e->key && !BIT_TEST(e->flag, KEY_URL))
 	safe_free(e->key);
     e->key = xstrdup(newkey);
