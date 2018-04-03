     if (mem != NULL) {
 	storeAppendPrintf(s, "\tinmem_lo: %d\n", (int) mem->inmem_lo);
 	storeAppendPrintf(s, "\tinmem_hi: %d\n", (int) mem->inmem_hi);
-	storeAppendPrintf(s, "\tswapout: %d bytes done, %d queued, FD %d\n",
-	    (int) mem->swapout.done_offset,
-	    (int) mem->swapout.queue_offset,
-	    mem->swapout.fd);
+	storeAppendPrintf(s, "\tswapout: %d bytes queued\n",
+	    (int) mem->swapout.queue_offset);
+	if (mem->swapout.sio)
+	    storeAppendPrintf(s, "\tswapout: %d bytes written\n",
+	        (int) storeOffset(mem->swapout.sio));
 	for (i = 0, sc = &mem->clients[i]; sc != NULL; sc = sc->next, i++) {
 	    if (sc->callback_data == NULL)
 		continue;
