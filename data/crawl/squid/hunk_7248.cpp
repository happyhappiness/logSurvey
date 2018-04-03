 }
 
 /* Register interest in an object currently being retrieved. */
-int
-storeRegister(StoreEntry * e, int fd, STCB * handler, void *data)
+void
+storeRegister(StoreEntry * e, STCB * callback, void *data, off_t offset)
 {
     int i;
     MemObject *mem = e->mem_obj;
-    debug(20, 3, "storeRegister: FD %d '%s'\n", fd, e->key);
+    struct _store_client *sc;
+    debug(20, 3, "storeRegister: '%s'\n", e->key);
     if ((i = storeClientListSearch(mem, data)) < 0)
 	i = storeClientListAdd(e, data, 0);
-    if (mem->clients[i].callback)
-	fatal_dump("storeRegister: handler already exists");
-    mem->clients[i].callback = handler;
-    mem->clients[i].callback_data = data;
-    return 0;
+    sc = &mem->clients[i];
+    if (sc->callback)
+	fatal_dump("storeRegister: callback already exists");
+    sc->offset = offset;
+    sc->callback = callback;
+    sc->callback_data = data;
+    if (offset < e->object_len) {
+        sc->callback = NULL;
+	/* Don't NULL the callback_data, its used to identify the client */
+        callback(data);
+    }
 }
 
 int
 storeUnregister(StoreEntry * e, void *data)
 {
     int i;
     MemObject *mem = e->mem_obj;
+    struct _store_client *sc;
     if (mem == NULL)
 	return 0;
     debug(20, 3, "storeUnregister: called for '%s'\n", e->key);
     if ((i = storeClientListSearch(mem, data)) < 0)
 	return 0;
-    mem->clients[i].last_offset = 0;
-    mem->clients[i].callback = NULL;
-    mem->clients[i].callback_data = NULL;
+    sc = &mem->clients[i];
+    sc->offset = 0;
+    sc->callback = NULL;
+    sc->callback_data = NULL;
     debug(20, 9, "storeUnregister: returning 1\n");
     return 1;
 }
