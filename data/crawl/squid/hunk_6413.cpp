     statHistCopy(&dest->icp.reply_svc_time, &orig->icp.reply_svc_time);
     statHistCopy(&dest->dns.svc_time, &orig->dns.svc_time);
     statHistCopy(&dest->cd.on_xition_count, &orig->cd.on_xition_count);
+    statHistCopy(&dest->comm_incoming, &orig->comm_incoming);
 }
 
 static void
 statCountersHistograms(StoreEntry * sentry)
 {
+    StatCounters *f = &Counter;
 #if TOO_MUCH_OUTPUT
     storeAppendPrintf(sentry, "client_http.all_svc_time histogram:\n");
     statHistDump(&f->client_http.all_svc_time, sentry, NULL);
