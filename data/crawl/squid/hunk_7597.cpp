 
     /* Kick LRU out until we have enough memory space */
     for (i = 0; i < list_count; i++) {
-	if (meta_data.hot_vm > store_hotobj_low) {
-	    storePurgeMem(*(list + i));
-	    n_purged++;
-	} else if ((store_mem_size + size) > store_mem_low) {
-	    storePurgeMem(*(list + i));
-	    n_purged++;
-	} else
-	    break;
+	if (meta_data.hot_vm < store_hotobj_low)
+	    if (store_mem_size + size < store_mem_low)
+		break;
+	e = *(list + i);
+	if (storeCheckPurgeMem(e)) {
+		storePurgeMem(e);
+		n_purged++;
+	} else if (!storeEntryLocked(e)) {
+		storeRelease(e);
+		n_released++;
+	} else {
+		fatal_dump("storeGetMemSpace: Bad Entry in LRU list");
+	}
     }
 
-    debug(20, 2, "storeGetMemSpace: After freeing size: %7d bytes\n", store_mem_size);
-    debug(20, 2, "storeGetMemSpace: Purged:             %7d items\n", n_purged);
+    i = 3;
     if (meta_data.hot_vm > store_hotobj_high) {
 	if (squid_curtime - last_warning > 600) {
 	    debug(20, 0, "WARNING: Over hot_vm object count (%d > %d)\n",
 		meta_data.hot_vm, store_hotobj_high);
-	    debug(20, 0, "       : %d objects locked in memory\n", n_locked);
-	    debug(20, 0, "       : purged %d of %d candidates\n",
-		n_purged,
-		list_count);
 	    last_warning = squid_curtime;
+	    i = 0;
 	}
-    } else if ((store_mem_size + size) > store_mem_high) {
+    } else if (store_mem_size + size > store_mem_high) {
 	if (squid_curtime - last_warning > 600) {
 	    debug(20, 0, "WARNING: Over store_mem high-water mark (%d > %d)\n",
 		store_mem_size + size, store_mem_high);
-	    debug(20, 0, "       : %d objects locked in memory\n", n_locked);
-	    debug(20, 0, "       : released %d of %d candidates\n",
-		n_purged,
-		list_count);
 	    last_warning = squid_curtime;
+	    i = 0;
 	}
     }
-    debug(20, 2, "storeGetMemSpace: Done.\n");
+    debug(20, i, "storeGetMemSpace stats:\n");
+    debug(20, i, "  %6d objects locked in memory\n", n_locked);
+    debug(20, i, "  %6d LRU candidates\n", list_count);
+    debug(20, i, "  %6d were purged\n", n_purged);
+    debug(20, i, "  %6d were released\n", n_released);
     xfree(list);
     return 0;
 }