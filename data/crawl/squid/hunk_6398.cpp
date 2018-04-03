     statHistDump(&f->icp.reply_svc_time, sentry, NULL);
     storeAppendPrintf(sentry, "dns.svc_time histogram:\n");
     statHistDump(&f->dns.svc_time, sentry, NULL);
-#endif
-    storeAppendPrintf(sentry, "comm_incoming histogram:\n");
-    statHistDump(&f->comm_incoming, sentry, statHistIntDumper);
 }
 
 static void
