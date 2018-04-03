     return e;
 }
 
-#if OLD_CODE
-/* Register interest in an object currently being retrieved. */
-void
-storeRegister(StoreEntry * e, STCB * callback, void *data, off_t offset)
-{
-    int i;
-    MemObject *mem = e->mem_obj;
-    struct _store_client *sc;
-    debug(20, 3, "storeRegister: '%s'\n", e->key);
-    if ((i = storeClientListSearch(mem, data)) < 0)
-	i = storeClientListAdd(e, data, 0);
-    sc = &mem->clients[i];
-    if (sc->callback)
-	fatal_dump("storeRegister: callback already exists");
-    sc->offset = offset;
-    sc->callback = callback;
-    sc->callback_data = data;
-    if (offset < e->object_len) {
-	sc->callback = NULL;
-	/* Don't NULL the callback_data, its used to identify the client */
-	callback(data);
-    }
-}
-#endif
-
 int
 storeUnregister(StoreEntry * e, void *data)
 {
