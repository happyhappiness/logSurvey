 }
 
 void
-storeClientCopyOld(store_client *sc, StoreEntry *e, off_t seen_offset,
-   off_t copy_offset, size_t size, char *buf, STCB *callback, void *data)
+storeClientCopyOld(store_client * sc, StoreEntry * e, off_t seen_offset,
+    off_t copy_offset, size_t size, char *buf, STCB * callback, void *data)
 {
     /* OLD API -- adrian */
     fatal("storeClientCopyOld() has been called!\n");
