     l = &CountHist[minutes];
     dt = tvSubDsec(l->timestamp, f->timestamp);
     ct = f->cputime - l->cputime;
+
     storeAppendPrintf(sentry, "client_http.requests = %f/sec\n",
 	XAVG(client_http.requests));
     storeAppendPrintf(sentry, "client_http.hits = %f/sec\n",
