 	(int) f->icp.kbytes_recv.kb);
     storeAppendPrintf(sentry, "cd.times_used = %d\n",
 	f->cd.times_used);
+    storeAppendPrintf(sentry, "cd.msgs_sent = %d\n",
+	f->cd.msgs_sent);
+    storeAppendPrintf(sentry, "cd.msgs_recv = %d\n",
+	f->cd.msgs_recv);
     storeAppendPrintf(sentry, "cd.kbytes_sent = %d\n",
 	(int) f->cd.kbytes_sent.kb);
     storeAppendPrintf(sentry, "cd.kbytes_recv = %d\n",
