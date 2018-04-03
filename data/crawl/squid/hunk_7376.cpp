  * storeAbort()
  * {http,ftp,gopher,wais}Start()
  */
-int
-storeLockObject(StoreEntry * e, SIH handler, void *data)
+void
+storeLockObject(StoreEntry * e, SIH callback, void *callback_data)
 {
-    int status = 0;
+    lock_ctrl_t *ctrlp;
     e->lock_count++;
     debug(20, 3, "storeLockObject: key '%s' count=%d\n",
 	e->key, (int) e->lock_count);
     if (e->mem_status != NOT_IN_MEMORY)
-	/* ok, its either IN_MEMORY or SWAPPING_IN */
-	debug(20, 5, "storeLockObject: OK: mem_status is %s\n", memStatusStr[e->mem_status]);
+	(void) 0;
     else if (e->swap_status == SWAP_OK)
-	/* ok, its NOT_IN_MEMORY, but its swapped out */
-	debug(20, 5, "storeLockObject: OK: swap_status is %s\n", swapStatusStr[e->swap_status]);
+	(void) 0;
     else if (e->store_status == STORE_PENDING)
-	/* ok, we're reading it in right now */
-	debug(20, 5, "storeLockObject: OK: store_status is %s\n", storeStatusStr[e->store_status]);
+	(void) 0;
     else
 	fatal_dump(storeDescribeStatus(e));
     e->lastref = squid_curtime;
     /* If the object is NOT_IN_MEMORY, fault it in. */
-    if ((e->mem_status == NOT_IN_MEMORY) && (e->swap_status == SWAP_OK)) {
+    if (e->mem_status == NOT_IN_MEMORY && e->swap_status == SWAP_OK) {
 	/* object is in disk and no swapping daemon running. Bring it in. */
-	if ((status = storeSwapInStart(e, handler, data)) < 0) {
-	    /* We couldn't find or couldn't open object's swapfile.
-	     * So, return a -1 here, indicating that we will treat
-	     * the reference like a MISS_TTL, force a keychange and
-	     storeRelease.  */
-	    e->lock_count--;
-	}
-    } else if (e->mem_status == IN_MEMORY && handler) {
-	/* its already in memory, so call the handler */
-	handler(0, data);
-    } else if (handler) {
-	/* The object is probably in state SWAPPING_IN, not much we can do.
-	 * Instead of returning failure here, we should have a list of complete
-	 * handlers which we could append to... */
-	handler(1, data);
+	if (callback == NULL)
+	    debug(20, 0, "storeLockObject: NULL callback\n");
+	ctrlp = xmalloc(sizeof(lock_ctrl_t));
+	ctrlp->callback = callback;
+	ctrlp->callback_data = callback_data;
+	ctrlp->e = e;
+	storeSwapInStart(e, storeLockObjectComplete, ctrlp);
+    } else {
+	if (callback)
+	    (callback) (callback_data, 0);
     }
-    return status;
+}
+
+static void
+storeLockObjectComplete(void *data, int status)
+{
+    lock_ctrl_t *ctrlp = (lock_ctrl_t *) data;
+    if (status < 0)
+	ctrlp->e->lock_count--;
+    if (ctrlp->callback)
+	(ctrlp->callback) (ctrlp->callback_data, status);
+    xfree(ctrlp);
 }
 
 void
