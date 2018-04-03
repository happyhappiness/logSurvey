     statHistDump(&f->icp.reply_svc_time, sentry, NULL);
     storeAppendPrintf(sentry, "dns.svc_time histogram:\n");
     statHistDump(&f->dns.svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "select_fds_hist histogram:\n");
+    statHistDump(&f->select_fds_hist, sentry, NULL);
 }
 
 static void