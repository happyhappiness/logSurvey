 
 // some SwapDirs may maintain their indexes and be able to lookup an entry key
 StoreEntry *
-SwapDir::get(const cache_key *key)
+SwapDir::get(const cache_key *)
 {
     return NULL;
 }
 
 void
-SwapDir::get(String const key, STOREGETCLIENT aCallback, void *aCallbackData)
+SwapDir::get(String const, STOREGETCLIENT, void *)
 {
     fatal("not implemented");
 }
