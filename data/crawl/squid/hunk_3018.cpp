                       (int) f->timestamp.tv_sec,
                       (int) f->timestamp.tv_usec,
                       mkrfc1123(f->timestamp.tv_sec));
-    storeAppendPrintf(sentry, "client_http.requests = %d\n",
-                      f->client_http.requests);
-    storeAppendPrintf(sentry, "client_http.hits = %d\n",
-                      f->client_http.hits);
-    storeAppendPrintf(sentry, "client_http.errors = %d\n",
-                      f->client_http.errors);
-    storeAppendPrintf(sentry, "client_http.kbytes_in = %d\n",
-                      (int) f->client_http.kbytes_in.kb);
-    storeAppendPrintf(sentry, "client_http.kbytes_out = %d\n",
-                      (int) f->client_http.kbytes_out.kb);
-    storeAppendPrintf(sentry, "client_http.hit_kbytes_out = %d\n",
-                      (int) f->client_http.hit_kbytes_out.kb);
-
-    storeAppendPrintf(sentry, "server.all.requests = %d\n",
-                      (int) f->server.all.requests);
-    storeAppendPrintf(sentry, "server.all.errors = %d\n",
-                      (int) f->server.all.errors);
-    storeAppendPrintf(sentry, "server.all.kbytes_in = %d\n",
-                      (int) f->server.all.kbytes_in.kb);
-    storeAppendPrintf(sentry, "server.all.kbytes_out = %d\n",
-                      (int) f->server.all.kbytes_out.kb);
-
-    storeAppendPrintf(sentry, "server.http.requests = %d\n",
-                      (int) f->server.http.requests);
-    storeAppendPrintf(sentry, "server.http.errors = %d\n",
-                      (int) f->server.http.errors);
-    storeAppendPrintf(sentry, "server.http.kbytes_in = %d\n",
-                      (int) f->server.http.kbytes_in.kb);
-    storeAppendPrintf(sentry, "server.http.kbytes_out = %d\n",
-                      (int) f->server.http.kbytes_out.kb);
-
-    storeAppendPrintf(sentry, "server.ftp.requests = %d\n",
-                      (int) f->server.ftp.requests);
-    storeAppendPrintf(sentry, "server.ftp.errors = %d\n",
-                      (int) f->server.ftp.errors);
-    storeAppendPrintf(sentry, "server.ftp.kbytes_in = %d\n",
-                      (int) f->server.ftp.kbytes_in.kb);
-    storeAppendPrintf(sentry, "server.ftp.kbytes_out = %d\n",
-                      (int) f->server.ftp.kbytes_out.kb);
-
-    storeAppendPrintf(sentry, "server.other.requests = %d\n",
-                      (int) f->server.other.requests);
-    storeAppendPrintf(sentry, "server.other.errors = %d\n",
-                      (int) f->server.other.errors);
-    storeAppendPrintf(sentry, "server.other.kbytes_in = %d\n",
-                      (int) f->server.other.kbytes_in.kb);
-    storeAppendPrintf(sentry, "server.other.kbytes_out = %d\n",
-                      (int) f->server.other.kbytes_out.kb);
-
-    storeAppendPrintf(sentry, "icp.pkts_sent = %d\n",
-                      f->icp.pkts_sent);
-    storeAppendPrintf(sentry, "icp.pkts_recv = %d\n",
-                      f->icp.pkts_recv);
-    storeAppendPrintf(sentry, "icp.queries_sent = %d\n",
-                      f->icp.queries_sent);
-    storeAppendPrintf(sentry, "icp.replies_sent = %d\n",
-                      f->icp.replies_sent);
-    storeAppendPrintf(sentry, "icp.queries_recv = %d\n",
-                      f->icp.queries_recv);
-    storeAppendPrintf(sentry, "icp.replies_recv = %d\n",
-                      f->icp.replies_recv);
-    storeAppendPrintf(sentry, "icp.query_timeouts = %d\n",
-                      f->icp.query_timeouts);
-    storeAppendPrintf(sentry, "icp.replies_queued = %d\n",
-                      f->icp.replies_queued);
-    storeAppendPrintf(sentry, "icp.kbytes_sent = %d\n",
-                      (int) f->icp.kbytes_sent.kb);
-    storeAppendPrintf(sentry, "icp.kbytes_recv = %d\n",
-                      (int) f->icp.kbytes_recv.kb);
-    storeAppendPrintf(sentry, "icp.q_kbytes_sent = %d\n",
-                      (int) f->icp.q_kbytes_sent.kb);
-    storeAppendPrintf(sentry, "icp.r_kbytes_sent = %d\n",
-                      (int) f->icp.r_kbytes_sent.kb);
-    storeAppendPrintf(sentry, "icp.q_kbytes_recv = %d\n",
-                      (int) f->icp.q_kbytes_recv.kb);
-    storeAppendPrintf(sentry, "icp.r_kbytes_recv = %d\n",
-                      (int) f->icp.r_kbytes_recv.kb);
+    storeAppendPrintf(sentry, "client_http.requests = %ld\n",
+                      (long)f->client_http.requests);
+    storeAppendPrintf(sentry, "client_http.hits = %ld\n",
+                      (long)f->client_http.hits);
+    storeAppendPrintf(sentry, "client_http.errors = %ld\n",
+                      (long)f->client_http.errors);
+    storeAppendPrintf(sentry, "client_http.kbytes_in = %ld\n",
+                      (long)f->client_http.kbytes_in.kb);
+    storeAppendPrintf(sentry, "client_http.kbytes_out = %ld\n",
+                      (long)f->client_http.kbytes_out.kb);
+    storeAppendPrintf(sentry, "client_http.hit_kbytes_out = %ld\n",
+                      (long)f->client_http.hit_kbytes_out.kb);
+
+    storeAppendPrintf(sentry, "server.all.requests = %ld\n",
+                      (long)f->server.all.requests);
+    storeAppendPrintf(sentry, "server.all.errors = %ld\n",
+                      (long) f->server.all.errors);
+    storeAppendPrintf(sentry, "server.all.kbytes_in = %ld\n",
+                      (long) f->server.all.kbytes_in.kb);
+    storeAppendPrintf(sentry, "server.all.kbytes_out = %ld\n",
+                      (long) f->server.all.kbytes_out.kb);
+
+    storeAppendPrintf(sentry, "server.http.requests = %ld\n",
+                      (long) f->server.http.requests);
+    storeAppendPrintf(sentry, "server.http.errors = %ld\n",
+                      (long) f->server.http.errors);
+    storeAppendPrintf(sentry, "server.http.kbytes_in = %ld\n",
+                      (long) f->server.http.kbytes_in.kb);
+    storeAppendPrintf(sentry, "server.http.kbytes_out = %ld\n",
+                      (long) f->server.http.kbytes_out.kb);
+
+    storeAppendPrintf(sentry, "server.ftp.requests = %ld\n",
+                      (long) f->server.ftp.requests);
+    storeAppendPrintf(sentry, "server.ftp.errors = %ld\n",
+                      (long) f->server.ftp.errors);
+    storeAppendPrintf(sentry, "server.ftp.kbytes_in = %ld\n",
+                      (long) f->server.ftp.kbytes_in.kb);
+    storeAppendPrintf(sentry, "server.ftp.kbytes_out = %ld\n",
+                      (long) f->server.ftp.kbytes_out.kb);
+
+    storeAppendPrintf(sentry, "server.other.requests = %ld\n",
+                      (long) f->server.other.requests);
+    storeAppendPrintf(sentry, "server.other.errors = %ld\n",
+                      (long) f->server.other.errors);
+    storeAppendPrintf(sentry, "server.other.kbytes_in = %ld\n",
+                      (long) f->server.other.kbytes_in.kb);
+    storeAppendPrintf(sentry, "server.other.kbytes_out = %ld\n",
+                      (long) f->server.other.kbytes_out.kb);
+
+    storeAppendPrintf(sentry, "icp.pkts_sent = %ld\n",
+                      (long)f->icp.pkts_sent);
+    storeAppendPrintf(sentry, "icp.pkts_recv = %ld\n",
+                      (long)f->icp.pkts_recv);
+    storeAppendPrintf(sentry, "icp.queries_sent = %ld\n",
+                      (long)f->icp.queries_sent);
+    storeAppendPrintf(sentry, "icp.replies_sent = %ld\n",
+                      (long)f->icp.replies_sent);
+    storeAppendPrintf(sentry, "icp.queries_recv = %ld\n",
+                      (long)f->icp.queries_recv);
+    storeAppendPrintf(sentry, "icp.replies_recv = %ld\n",
+                      (long)f->icp.replies_recv);
+    storeAppendPrintf(sentry, "icp.query_timeouts = %ld\n",
+                      (long)f->icp.query_timeouts);
+    storeAppendPrintf(sentry, "icp.replies_queued = %ld\n",
+                      (long)f->icp.replies_queued);
+    storeAppendPrintf(sentry, "icp.kbytes_sent = %ld\n",
+                      (long) f->icp.kbytes_sent.kb);
+    storeAppendPrintf(sentry, "icp.kbytes_recv = %ld\n",
+                      (long) f->icp.kbytes_recv.kb);
+    storeAppendPrintf(sentry, "icp.q_kbytes_sent = %ld\n",
+                      (long) f->icp.q_kbytes_sent.kb);
+    storeAppendPrintf(sentry, "icp.r_kbytes_sent = %ld\n",
+                      (long) f->icp.r_kbytes_sent.kb);
+    storeAppendPrintf(sentry, "icp.q_kbytes_recv = %ld\n",
+                      (long) f->icp.q_kbytes_recv.kb);
+    storeAppendPrintf(sentry, "icp.r_kbytes_recv = %ld\n",
+                      (long) f->icp.r_kbytes_recv.kb);
 
 #if USE_CACHE_DIGESTS
 
-    storeAppendPrintf(sentry, "icp.times_used = %d\n",
-                      f->icp.times_used);
-    storeAppendPrintf(sentry, "cd.times_used = %d\n",
-                      f->cd.times_used);
-    storeAppendPrintf(sentry, "cd.msgs_sent = %d\n",
-                      f->cd.msgs_sent);
-    storeAppendPrintf(sentry, "cd.msgs_recv = %d\n",
-                      f->cd.msgs_recv);
-    storeAppendPrintf(sentry, "cd.memory = %d\n",
-                      (int) f->cd.memory.kb);
-    storeAppendPrintf(sentry, "cd.local_memory = %d\n",
-                      (int) (store_digest ? store_digest->mask_size / 1024 : 0));
-    storeAppendPrintf(sentry, "cd.kbytes_sent = %d\n",
-                      (int) f->cd.kbytes_sent.kb);
-    storeAppendPrintf(sentry, "cd.kbytes_recv = %d\n",
-                      (int) f->cd.kbytes_recv.kb);
+    storeAppendPrintf(sentry, "icp.times_used = %ld\n",
+                      (long)f->icp.times_used);
+    storeAppendPrintf(sentry, "cd.times_used = %ld\n",
+                      (long)f->cd.times_used);
+    storeAppendPrintf(sentry, "cd.msgs_sent = %ld\n",
+                      (long)f->cd.msgs_sent);
+    storeAppendPrintf(sentry, "cd.msgs_recv = %ld\n",
+                      (long)f->cd.msgs_recv);
+    storeAppendPrintf(sentry, "cd.memory = %ld\n",
+                      (long) f->cd.memory.kb);
+    storeAppendPrintf(sentry, "cd.local_memory = %ld\n",
+                      (long) (store_digest ? store_digest->mask_size / 1024 : 0));
+    storeAppendPrintf(sentry, "cd.kbytes_sent = %ld\n",
+                      (long) f->cd.kbytes_sent.kb);
+    storeAppendPrintf(sentry, "cd.kbytes_recv = %ld\n",
+                      (long) f->cd.kbytes_recv.kb);
 #endif
 
-    storeAppendPrintf(sentry, "unlink.requests = %d\n",
-                      f->unlink.requests);
-    storeAppendPrintf(sentry, "page_faults = %d\n",
-                      f->page_faults);
+    storeAppendPrintf(sentry, "unlink.requests = %ld\n",
+                      (long)f->unlink.requests);
+    storeAppendPrintf(sentry, "page_faults = %ld\n",
+                      (long)f->page_faults);
     storeAppendPrintf(sentry, "select_loops = %ld\n",
-                      f->select_loops);
+                      (long)f->select_loops);
     storeAppendPrintf(sentry, "cpu_time = %f\n",
                       f->cputime);
     storeAppendPrintf(sentry, "wall_time = %f\n",
                       tvSubDsec(f->timestamp, current_time));
-    storeAppendPrintf(sentry, "swap.outs = %d\n",
-                      f->swap.outs);
-    storeAppendPrintf(sentry, "swap.ins = %d\n",
-                      f->swap.ins);
-    storeAppendPrintf(sentry, "swap.files_cleaned = %d\n",
-                      f->swap.files_cleaned);
-    storeAppendPrintf(sentry, "aborted_requests = %d\n",
-                      f->aborted_requests);
+    storeAppendPrintf(sentry, "swap.outs = %ld\n",
+                      (long)f->swap.outs);
+    storeAppendPrintf(sentry, "swap.ins = %ld\n",
+                      (long)f->swap.ins);
+    storeAppendPrintf(sentry, "swap.files_cleaned = %ld\n",
+                      (long)f->swap.files_cleaned);
+    storeAppendPrintf(sentry, "aborted_requests = %ld\n",
+                      (long)f->aborted_requests);
 }
 
 void