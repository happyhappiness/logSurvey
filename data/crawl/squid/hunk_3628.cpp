     for (dlink_node *link = hlp->servers.head; link; link = link->next) {
         helper_stateful_server *srv = (helper_stateful_server *)link->data;
         double tt = 0.001 * tvSubMsec(srv->dispatch_time, srv->flags.busy ? current_time : srv->answer_time);
-        double tr = 0.001 * tvSubMsec(srv->dispatch_time, current_time);
-        storeAppendPrintf(sentry, "%7d\t%7d\t%7d\t%11d\t%c%c%c%c%c\t%7.3f\t%7.3f\t%7d\t%s\n",
+        storeAppendPrintf(sentry, "%7d\t%7d\t%7d\t%11d\t%c%c%c%c%c\t%7.3f\t%7d\t%s\n",
                           srv->index + 1,
                           srv->rfd,
                           srv->pid,
