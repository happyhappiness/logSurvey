         storeAppendPrintf(e, " max-size=%"PRId64, max_objsize);
 }
 
-/* Swapdirs do not have an index of their own - thus they ask their parent..
- * but the parent child relationship isn't implemented yet
- */
+// some SwapDirs may maintain their indexes and be able to lookup an entry key
 StoreEntry *
 SwapDir::get(const cache_key *key)
 {
-    return Store::Root().get(key);
+    return NULL;
 }
 
 void
