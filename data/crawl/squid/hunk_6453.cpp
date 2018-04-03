 
 #if SQUID_PEER_DIGEST
     storeAppendPrintf(sentry, "icp.times_used = %d\n",
-        f->icp.times_used);
+	f->icp.times_used);
     storeAppendPrintf(sentry, "cd.times_used = %d\n",
-        f->cd.times_used);
+	f->cd.times_used);
     storeAppendPrintf(sentry, "cd.msgs_sent = %d\n",
 	f->cd.msgs_sent);
     storeAppendPrintf(sentry, "cd.msgs_recv = %d\n",
 	f->cd.msgs_recv);
     storeAppendPrintf(sentry, "cd.memory = %d\n",
-	(int)f->cd.memory.kb);
+	(int) f->cd.memory.kb);
     storeAppendPrintf(sentry, "cd.local_memory = %d\n",
-        (int) (store_digest ? store_digest->mask_size/1024 : 0));
+	(int) (store_digest ? store_digest->mask_size / 1024 : 0));
     storeAppendPrintf(sentry, "cd.kbytes_sent = %d\n",
 	(int) f->cd.kbytes_sent.kb);
     storeAppendPrintf(sentry, "cd.kbytes_recv = %d\n",
