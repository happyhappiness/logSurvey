 	(int) f->client_http.kbytes_in.kb);
     storeAppendPrintf(sentry, "client_http.kbytes_out = %d\n",
 	(int) f->client_http.kbytes_out.kb);
+    storeAppendPrintf(sentry, "client_http.hit_kbytes_out = %d\n",
+	(int) f->client_http.hit_kbytes_out.kb);
 
     storeAppendPrintf(sentry, "server.all.requests = %d\n",
 	(int) f->server.all.requests);
