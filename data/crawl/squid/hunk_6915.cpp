     dnsData->offset += len;
     dnsData->ip_inbuf[dnsData->offset] = '\0';
     i = dnsData->data;
-    if (i == NULL) {
-	debug_trap("NULL ipcache_entry");
-	return;
-    }
-    if (i->status != IP_DISPATCHED)
-	fatal_dump("ipcache_dnsHandleRead: bad status");
+    assert(i != NULL);
+    assert(i->status == IP_DISPATCHED);
     if (strstr(dnsData->ip_inbuf, "$end\n")) {
 	/* end of record found */
 	IpcacheStats.avg_svc_time = intAverage(IpcacheStats.avg_svc_time,
