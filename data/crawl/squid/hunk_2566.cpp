 }
 
 void
-PconnPool::dumpHash(StoreEntry *e)
+PconnPool::dumpHash(StoreEntry *e) const
 {
-    int i;
-    hash_link *walker = NULL;
     hash_table *hid = table;
     hash_first(hid);
 
-    for (i = 0, walker = hid->next; walker; walker = hash_next(hid)) {
+    int i = 0;
+    for (hash_link *walker = hid->next; walker; walker = hash_next(hid)) {
         storeAppendPrintf(e, "\t item %5d: %s\n", i++, (char *)(walker->key));
     }
 }
