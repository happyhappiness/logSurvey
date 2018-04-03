     for (link = hlp->servers.head; link; link = link->next) {
         srv = (helper_stateful_server *)link->data;
         tt = 0.001 * tvSubMsec(srv->dispatch_time, current_time);
-        storeAppendPrintf(sentry, "%7d\t%7d\t%7d\t%11d\t%20d\t%%c%c%c%c%c\t%7.3f\t%7d\t%s\n",
+        storeAppendPrintf(sentry, "%7d\t%7d\t%7d\t%11d\t%20d\t%c%c%c%c%c\t%7.3f\t%7d\t%s\n",
                           srv->index + 1,
                           srv->rfd,
                           srv->pid,