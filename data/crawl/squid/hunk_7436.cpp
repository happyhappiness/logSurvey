 int
 storeRegister(StoreEntry * e, int fd, PIF handler, void *data)
 {
-    PendingEntry *pe = NULL;
-    int old_size;
     int i;
-    int j;
     MemObject *mem = e->mem_obj;
     debug(20, 3, "storeRegister: FD %d '%s'\n", fd, e->key);
-    pe = xcalloc(1, sizeof(PendingEntry));
-    pe->fd = fd;
-    pe->handler = handler;
-    pe->data = data;
-    /* find an empty slot */
-    for (i = 0; i < (int) mem->pending_list_size; i++) {
-	if (mem->pending[i] == NULL)
-	    break;
-    }
-    if (i == mem->pending_list_size) {
-	/* grow the array */
-	struct pentry **tmp = NULL;
-	old_size = mem->pending_list_size;
-	/* set list_size to an appropriate amount */
-	mem->pending_list_size += MIN_PENDING;
-	/* allocate, and copy old pending list over to the new one */
-	tmp = xcalloc(mem->pending_list_size, sizeof(struct pentry *));
-	for (j = 0; j < old_size; j++)
-	    tmp[j] = mem->pending[j];
-	/* free the old list and set the new one */
-	safe_free(mem->pending);
-	mem->pending = tmp;
-	debug(20, 9, "storeRegister: grew pending list to %d for slot %d.\n",
-	    mem->pending_list_size, i);
-    }
-    mem->pending[i] = pe;
+    if ((i = storeClientListSearch(mem, fd)) < 0)
+	i = storeClientListAdd(e, fd, 0);
+    if (mem->clients[i].callback)
+	fatal_dump("storeRegister: handler already exists");
+    mem->clients[i].callback = handler;
+    mem->clients[i].callback_data = data;
     return 0;
 }
 
-/* remove handler assoicate to that fd from store pending list */
-/* Also remove entry from client_list if exist. */
-/* return number of successfully free pending entries */
 int
 storeUnregister(StoreEntry * e, int fd)
 {
     int i;
-    int freed = 0;
     MemObject *mem = e->mem_obj;
     if (mem == NULL)
 	return 0;
     debug(20, 3, "storeUnregister: called for FD %d '%s'\n", fd, e->key);
-    /* look for entry in client_list */
-    if ((i = storeClientListSearch(mem, fd)) > -1) {
-	safe_free(mem->client_list[i]);
-	mem->client_list[i] = NULL;
-    }
-    /* walk the entire list looking for matched fd */
-    for (i = 0; i < (int) mem->pending_list_size; i++) {
-	if (mem->pending[i] == NULL)
-	    continue;
-	if (mem->pending[i]->fd != fd)
-	    continue;
-	/* found the match fd */
-	safe_free(mem->pending[i]);
-	mem->pending[i] = NULL;
-	freed++;
-    }
+    if ((i = storeClientListSearch(mem, fd)) < 0)
+	return 0;
+    mem->clients[i].fd = -1;
+    mem->clients[i].last_offset = 0;
+    mem->clients[i].callback = NULL;
+    mem->clients[i].callback_data = NULL;
     if (mem->fd_of_first_client == fd)
 	mem->fd_of_first_client = -1;
-    debug(20, 9, "storeUnregister: returning %d\n", freed);
-    return freed;
+    debug(20, 9, "storeUnregister: returning 1\n");
+    return 1;
 }
 
 int
