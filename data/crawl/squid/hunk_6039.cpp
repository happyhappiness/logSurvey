 	if (mem->swapout.sio)
 	    storeAppendPrintf(s, "\tswapout: %d bytes written\n",
 		(int) storeOffset(mem->swapout.sio));
-        for (i = 0, node = mem->clients.head; node; node = node->next, i++) {
-            sc = (store_client *)node->data;
+	for (i = 0, node = mem->clients.head; node; node = node->next, i++) {
+	    sc = (store_client *) node->data;
 	    if (sc->callback_data == NULL)
 		continue;
 	    storeAppendPrintf(s, "\tClient #%d, %p\n", i, sc->callback_data);
