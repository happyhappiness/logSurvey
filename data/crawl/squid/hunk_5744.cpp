     storeAppendPrintf(e, "\tneeded: %3s, usable: %3s, requested: %3s\n",
 	f2s(needed), f2s(usable), f2s(requested));
     storeAppendPrintf(e, "\n\tlast retry delay: %d secs\n",
-	pd->times.retry_delay);
+	(int)pd->times.retry_delay);
     storeAppendPrintf(e, "\tlast request response time: %d secs\n",
-	pd->times.req_delay);
+	(int)pd->times.req_delay);
     storeAppendPrintf(e, "\tlast request result: %s\n",
 	pd->req_result ? pd->req_result : "(none)");
 
