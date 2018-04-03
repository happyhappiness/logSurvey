 	debug(20, 0, "%s", storeToString(e));
 	fatal_dump(NULL);
     }
-    return ((e->lock_count) ||
-	(e->store_status == STORE_PENDING) ||
-	(e->swap_status == SWAPPING_OUT) ||
-	(e->mem_status == SWAPPING_IN)
-	);
+    if (e->lock_count)
+	return 1;
+    if (e->swap_status == SWAPPING_OUT)
+	return 1;
+    if (e->mem_status == SWAPPING_IN)
+	return 1;
+    return 0;
 }
 
 /*  use this for internal call only */
