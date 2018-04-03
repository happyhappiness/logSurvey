 	fatal_dump("ipcache_dnsHandleRead: bad status");
     if (strstr(dnsData->ip_inbuf, "$end\n")) {
 	/* end of record found */
-	svc_time = tvSubMsec(dnsData->dispatch_time, current_time);
-	if (n > IPCACHE_AV_FACTOR)
-	    n = IPCACHE_AV_FACTOR;
-	IpcacheStats.avg_svc_time
-	    = (IpcacheStats.avg_svc_time * (n - 1) + svc_time) / n;
+	IpcacheStats.avg_svc_time = intAverage(IpcacheStats.avg_svc_time,
+	    tvSubMsec(dnsData->dispatch_time, current_time),
+	    n, IPCACHE_AV_FACTOR);
 	if ((x = ipcache_parsebuffer(dnsData->ip_inbuf, dnsData)) == NULL) {
 	    debug(14, 0, "ipcache_dnsHandleRead: ipcache_parsebuffer failed?!\n");
 	} else {
