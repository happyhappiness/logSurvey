 	    storeRelease(e);
 	    n_released++;
 	} else {
-	    fatal_dump("storeGetMemSpace: Bad Entry in LRU list");
+	    debug_trap("storeGetMemSpace: Bad Entry in LRU list");
 	}
     }
 
