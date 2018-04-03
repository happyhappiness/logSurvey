 	srv = link->data;
 	tt = 0.001 * tvSubMsec(srv->dispatch_time,
 	    srv->flags.busy ? current_time : srv->answer_time);
-	storeAppendPrintf(sentry, "%7d\t%7d\t%11d\t%c%c%c%c\t%7.3f\t%7d\t%s\n",
+	storeAppendPrintf(sentry, "%7d\t%7d\t%7d\t%11d\t%c%c%c%c\t%7.3f\t%7d\t%s\n",
 	    srv->index + 1,
 	    srv->rfd,
+	    src->pid,
 	    srv->stats.uses,
 	    srv->flags.alive ? 'A' : ' ',
 	    srv->flags.busy ? 'B' : ' ',