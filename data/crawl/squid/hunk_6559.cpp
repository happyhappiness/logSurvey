     }
     return buf;
 }
+
+
+#if FORW_VIA_DB
+    
+static void
+fvdbInit(void)
+{
+    via_table = hash_create((HASHCMP *) strcmp, 977, hash4);
+    forw_table = hash_create((HASHCMP *) strcmp, 977, hash4);
+    cachemgrRegister("via_headers", "Via Request Headers", fvdbDumpVia, 0);
+    cachemgrRegister("forw_headers", "X-Forwarded-For Request Headers",
+        fvdbDumpForw, 0);
+}
+
+static void
+fvdbCount(hash_table *hash, const char *key)
+{   
+        fvdb_entry *fv;
+        if (NULL == hash)
+                return;
+        fv = hash_lookup(hash, key);
+        if (NULL == fv) {
+                fv = xcalloc(1, sizeof(fvdb_entry));
+                fv->key = xstrdup(key);
+                hash_join(hash, (hash_link *) fv);
+        }
+        fv->n++;
+}
+
+void
+fvdbCountVia(const char *key)
+{
+	fvdbCount(via_table, key);
+}
+
+void
+fvdbCountForw(const char *key)
+{
+	fvdbCount(forw_table, key);
+}
+
+static void 
+fvdbDumpTable(StoreEntry *e, hash_table *hash)
+{
+        hash_link *h;
+        fvdb_entry *fv;
+        if (hash == NULL)  
+                return;
+        for (h = hash_first(hash); h != NULL; h = hash_next(hash)) {
+                fv = (fvdb_entry *) h;
+                storeAppendPrintf(e, "%9d %s\n", fv->n, fv->key);
+        }
+}
+
+static void
+fvdbDumpVia(StoreEntry *e)
+{
+        fvdbDumpTable(e, via_table);
+}
+    
+static void
+fvdbDumpForw(StoreEntry *e)
+{
+        fvdbDumpTable(e, forw_table); 
+}
+
+static
+void fvdbFreeEntry(void *data)
+{
+	fvdb_entry *fv = data;
+	xfree(fv->key);
+	xfree(fv);
+}
+
+static void
+fvdbClear(void)
+{
+    hashFreeItems(via_table, fvdbFreeEntry);
+    hashFreeItems(forw_table, fvdbFreeEntry);
+}
+
+#endif  
