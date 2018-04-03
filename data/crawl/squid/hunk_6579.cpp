 	Counter.icp.pkts_recv);
     storeAppendPrintf(sentry, "\tNumber of ICP messages sent:\t%u\n",
 	Counter.icp.pkts_sent);
+    storeAppendPrintf(sentry, "\tNumber of queued ICP replies:\t%u\n",
+	Counter.icp.replies_queued);
     storeAppendPrintf(sentry, "\tRequest failure ratio:\t%5.2f%%\n",
 	request_failure_ratio);
 
