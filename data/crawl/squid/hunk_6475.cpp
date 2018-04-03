     storeAppendPrintf(sentry, "icp.kbytes_recv = %d\n",
 	(int) f->icp.kbytes_recv.kb);
 
+#if SQUID_PEER_DIGEST
+    storeAppendPrintf(sentry, "cd.msgs_sent = %d\n",
+	f->cd.msgs_sent);
+    storeAppendPrintf(sentry, "cd.msgs_recv = %d\n",
+	f->cd.msgs_recv);
+    storeAppendPrintf(sentry, "cd.memory = %d\n",
+	(int)f->cd.memory.kb);
+    storeAppendPrintf(sentry, "cd.local_memory = %d\n",
+	store_digest ? store_digest->mask_size/1024 : 0);
+    storeAppendPrintf(sentry, "cd.kbytes_sent = %d\n",
+	(int) f->cd.kbytes_sent.kb);
+    storeAppendPrintf(sentry, "cd.kbytes_recv = %d\n",
+	(int) f->cd.kbytes_recv.kb);
+#endif
+
 #if TOO_MUCH_OUTPUT
     storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
     statHistDump(&f->icp.query_svc_time, sentry, NULL);
