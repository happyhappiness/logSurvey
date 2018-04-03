     f->cputime = rusage_cputime(&rusage);
 
     storeAppendPrintf(sentry, "sample_time = %d.%d (%s)\n",
-	f->timestamp.tv_sec,
-	f->timestamp.tv_usec,
+	(int) f->timestamp.tv_sec,
+	(int) f->timestamp.tv_usec,
 	mkrfc1123(f->timestamp.tv_sec));
     storeAppendPrintf(sentry, "client_http.requests = %d\n",
 	f->client_http.requests);
