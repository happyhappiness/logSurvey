     storeAppendPrintf(sentry, "client_http.kbytes_out = %d\n",
 	(int) f->client_http.kbytes_out.kb);
 
-#if TOO_MUCH_OUTPUT
-    storeAppendPrintf(sentry, "client_http.all_svc_time histogram:\n");
-    statHistDump(&f->client_http.all_svc_time, sentry, NULL);
-    storeAppendPrintf(sentry, "client_http.miss_svc_time histogram:\n");
-    statHistDump(&f->client_http.miss_svc_time, sentry, NULL);
-    storeAppendPrintf(sentry, "client_http.nm_svc_time histogram:\n");
-    statHistDump(&f->client_http.nm_svc_time, sentry, NULL);
-    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
-    statHistDump(&f->client_http.hit_svc_time, sentry, NULL);
-#endif
-
     storeAppendPrintf(sentry, "server.all.requests = %d\n",
 	(int) f->server.all.requests);
     storeAppendPrintf(sentry, "server.all.errors = %d\n",
