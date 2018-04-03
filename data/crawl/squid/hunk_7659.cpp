     e->lock_count++;
     debug(20, 3, "storeLockObject: locks %d: '%s'\n", e->lock_count, e->key);
 
-    if ((e->mem_status == NOT_IN_MEMORY) &&	/* Not in memory */
-	(e->swap_status != SWAP_OK) &&	/* Not on disk */
-	(e->store_status != STORE_PENDING)	/* Not being fetched */
-	) {
-	debug(20, 0, "storeLockObject: NOT_IN_MEMORY && !SWAP_OK && !STORE_PENDING conflict: <URL:%s>. aborting...\n", e->url);
-	/* If this sanity check fails, we should just ... */
-	fatal_dump(NULL);
-    }
+    if (e->mem_status != NOT_IN_MEMORY)
+	/* ok, its either IN_MEMORY or SWAPPING_IN */
+	debug(20,5,"storeLockObject: OK: mem_status is %s\n", memStatusStr[e->mem_status]);
+    else if (e->swap_status == SWAP_OK)
+	/* ok, its NOT_IN_MEMORY, but its swapped out */
+	debug(20,5,"storeLockObject: OK: swap_status is %s\n", swapStatusStr[e->swap_status]);
+    else if (e->store_status == STORE_PENDING)
+	/* ok, we're reading it in right now */
+	debug(20,5,"storeLockObject: OK: store_status is %s\n", storeStatusStr[e->store_status]);
+    else 
+	fatal_dump(storeDescribeStatus(e));
     e->lastref = squid_curtime;
 
     /* If the object is NOT_IN_MEMORY, fault it in. */
