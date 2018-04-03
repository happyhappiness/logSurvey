 	    IpcacheStats.hits++;
 	ipcacheAddPending(i, fd, handler, handlerData);
 	ipcache_call_pending(i);
-	return 0;
+	return;
     } else if (i->status == IP_PENDING || i->status == IP_DISPATCHED) {
 	debug(14, 4, "ipcache_nbgethostbyname: PENDING for '%s'\n", name);
 	IpcacheStats.pending_hits++;
 	ipcacheAddPending(i, fd, handler, handlerData);
-	return 0;
+	return;
     } else {
 	fatal_dump("ipcache_nbgethostbyname: BAD ipcache_entry status");
     }
