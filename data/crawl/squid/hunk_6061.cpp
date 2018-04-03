     storeAppendPrintf(sentry, "avg service time: %d msec\n",
 	hlp->stats.avg_svc_time);
     storeAppendPrintf(sentry, "\n");
-    storeAppendPrintf(sentry, "%7s\t%7s\t%11s\t%s\t%7s\t%7s\n",
+    storeAppendPrintf(sentry, "%7s\t%7s\t%11s\t%s\t%7s\t%7s\t%7s\n",
 	"#",
 	"FD",
 	"# Requests",
 	"Flags",
 	"Time",
-	"Offset");
+	"Offset",
+	"Request");
     for (link = hlp->servers.head; link; link = link->next) {
 	srv = link->data;
 	tt = 0.001 * tvSubMsec(srv->dispatch_time, current_time);
-	storeAppendPrintf(sentry, "%7d\t%7d\t%11d\t%c%c%c%c\t%7.3f\t%7d\n",
+	storeAppendPrintf(sentry, "%7d\t%7d\t%11d\t%c%c%c%c\t%7.3f\t%7d\t%s\n",
 	    srv->index + 1,
 	    srv->rfd,
 	    srv->stats.uses,
