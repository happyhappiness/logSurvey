 }
 
 static void
-proto_newobject(cacheinfo * obj, protocol_t proto_id, int size, int restart)
-{
-    proto_stat *p = &obj->proto_stat_data[proto_id];
-
-    p->object_count++;
-
-    /* Account for 1KB granularity */
-    p->kb.now += ((size + 1023) >> 10);
-
-    if (p->kb.now > p->kb.max)
-	p->kb.max = p->kb.now;
-    if (restart)
-	p->kb.min = p->kb.now;
-}
-
-
-static void
-proto_purgeobject(cacheinfo * obj, protocol_t proto_id, int size)
+statCountersDump(StoreEntry * sentry)
 {
-    proto_stat *p = &obj->proto_stat_data[proto_id];
-
-    p->object_count--;
-
-    /* Scale down to KB */
-    p->kb.now -= ((size + 1023) >> 10);
-
-    if (p->kb.now < p->kb.min)
-	p->kb.min = p->kb.now;
-}
-
-/* update stat for each particular protocol when an object is fetched */
-static void
-proto_touchobject(cacheinfo * obj, protocol_t proto_id, int size)
-{
-    obj->proto_stat_data[proto_id].refcount++;
-    obj->proto_stat_data[proto_id].transferbyte += (1023 + size) >> 10;
+    StatCounters *f = &Counter;
+    struct rusage rusage;
+    squid_getrusage(&rusage);
+    f->page_faults = rusage_pagefaults(&rusage);
+    f->cputime = rusage_cputime(&rusage);
+    storeAppendPrintf(sentry, "client_http.requests = %d\n",
+	f->client_http.requests);
+    storeAppendPrintf(sentry, "client_http.hits = %d\n",
+	f->client_http.hits);
+    storeAppendPrintf(sentry, "client_http.errors = %d\n",
+	f->client_http.errors);
+    storeAppendPrintf(sentry, "client_http.kbytes_in = %d\n",
+	(int) f->client_http.kbytes_in.kb);
+    storeAppendPrintf(sentry, "client_http.kbytes_out = %d\n",
+	(int) f->client_http.kbytes_out.kb);
+    storeAppendPrintf(sentry, "icp.pkts_sent = %d\n",
+	f->icp.pkts_sent);
+    storeAppendPrintf(sentry, "icp.pkts_recv = %d\n",
+	f->icp.pkts_recv);
+    storeAppendPrintf(sentry, "icp.kbytes_sent = %d\n",
+	(int) f->icp.kbytes_sent.kb);
+    storeAppendPrintf(sentry, "icp.kbytes_recv = %d\n",
+	(int) f->icp.kbytes_recv.kb);
+    storeAppendPrintf(sentry, "unlink.requests = %d\n",
+	f->unlink.requests);
+    storeAppendPrintf(sentry, "page_faults = %d\n",
+	f->page_faults);
+    storeAppendPrintf(sentry, "select_loops = %d\n",
+	f->select_loops);
+    storeAppendPrintf(sentry, "cpu_time = %f\n",
+	f->cputime);
+    storeAppendPrintf(sentry, "wall_time = %f\n",
+        tvSubDsec(f->timestamp, current_time));
 }
 
+#define XAVG(X) (dt ? (double) (f->X - l->X) / dt : 0.0)
 static void
-proto_count(cacheinfo * obj, protocol_t proto_id, log_type type)
+statAvgDump(StoreEntry * sentry, int minutes)
 {
-    switch (type) {
-    case LOG_TCP_HIT:
-    case LOG_TCP_IMS_HIT:
-    case LOG_TCP_REFRESH_HIT:
-    case LOG_TCP_REFRESH_FAIL_HIT:
-    case LOG_UDP_HIT:
-    case LOG_UDP_HIT_OBJ:
-	obj->proto_stat_data[proto_id].hit++;
-	break;
-    default:
-	obj->proto_stat_data[proto_id].miss++;
-	break;
-    }
+    StatCounters *f;
+    StatCounters *l;
+    double dt;
+    double ct;
+    assert(N_COUNT_HIST > 1);
+    assert(minutes > 0);
+    f = &CountHist[0];
+    if (minutes > N_COUNT_HIST-1)
+	minutes = N_COUNT_HIST-1;
+    l = &CountHist[minutes];
+    dt = tvSubDsec(l->timestamp, f->timestamp);
+    ct = f->cputime - l->cputime;
+    storeAppendPrintf(sentry, "client_http.requests = %f/sec\n",
+	XAVG(client_http.requests));
+    storeAppendPrintf(sentry, "client_http.hits = %f/sec\n",
+	XAVG(client_http.hits));
+    storeAppendPrintf(sentry, "client_http.errors = %f/sec\n",
+	XAVG(client_http.errors));
+    storeAppendPrintf(sentry, "client_http.kbytes_in = %f/sec\n",
+	XAVG(client_http.kbytes_in.kb));
+    storeAppendPrintf(sentry, "client_http.kbytes_out = %f/sec\n",
+	XAVG(client_http.kbytes_out.kb));
+    storeAppendPrintf(sentry, "icp.pkts_sent = %f/sec\n",
+	XAVG(icp.pkts_sent));
+    storeAppendPrintf(sentry, "icp.pkts_recv = %f/sec\n",
+	XAVG(icp.pkts_recv));
+    storeAppendPrintf(sentry, "icp.kbytes_sent = %f/sec\n",
+	XAVG(icp.kbytes_sent.kb));
+    storeAppendPrintf(sentry, "icp.kbytes_recv = %f/sec\n",
+	XAVG(icp.kbytes_recv.kb));
+    storeAppendPrintf(sentry, "unlink.requests = %f/sec\n",
+	XAVG(unlink.requests));
+    storeAppendPrintf(sentry, "page_faults = %f/sec\n",
+	XAVG(page_faults));
+    storeAppendPrintf(sentry, "select_loops = %f/sec\n",
+	XAVG(select_loops));
+    storeAppendPrintf(sentry, "cpu_time = %f seconds\n", ct);
+    storeAppendPrintf(sentry, "wall_time = %f seconds\n", dt);
+    storeAppendPrintf(sentry, "cpu_usage = %f%%\n",dpercent(ct,dt));
 }
 
-
 void
-stat_init(cacheinfo ** object, const char *logfilename)
+statInit(void)
 {
-    cacheinfo *obj = NULL;
     int i;
-    debug(18, 5) ("stat_init: Initializing...\n");
-    obj = xcalloc(1, sizeof(cacheinfo));
-    if (logfilename)
-	accessLogOpen(logfilename);
-    obj->proto_id = urlParseProtocol;
-    obj->proto_newobject = proto_newobject;
-    obj->proto_purgeobject = proto_purgeobject;
-    obj->proto_touchobject = proto_touchobject;
-    obj->proto_count = proto_count;
-    for (i = PROTO_NONE; i <= PROTO_MAX; i++) {
-	switch (i) {
-	case PROTO_HTTP:
-	    strcpy(obj->proto_stat_data[i].protoname, "HTTP");
-	    break;
-	case PROTO_GOPHER:
-	    strcpy(obj->proto_stat_data[i].protoname, "GOPHER");
-	    break;
-	case PROTO_FTP:
-	    strcpy(obj->proto_stat_data[i].protoname, "FTP");
-	    break;
-	case PROTO_WAIS:
-	    strcpy(obj->proto_stat_data[i].protoname, "WAIS");
-	    break;
-	case PROTO_CACHEOBJ:
-	    strcpy(obj->proto_stat_data[i].protoname, "CACHE_OBJ");
-	    break;
-	case PROTO_MAX:
-	    strcpy(obj->proto_stat_data[i].protoname, "TOTAL");
-	    break;
-	case PROTO_NONE:
-	default:
-	    strcpy(obj->proto_stat_data[i].protoname, "OTHER");
-	    break;
-	}
-	obj->proto_stat_data[i].object_count = 0;
-	obj->proto_stat_data[i].hit = 0;
-	obj->proto_stat_data[i].miss = 0;
-	obj->proto_stat_data[i].hitratio = 0.0;
-	obj->proto_stat_data[i].transferrate = 0;
-	obj->proto_stat_data[i].refcount = 0;
-	obj->proto_stat_data[i].transferbyte = 0;
-	obj->proto_stat_data[i].kb.max = 0;
-	obj->proto_stat_data[i].kb.min = 0;
-	obj->proto_stat_data[i].kb.avg = 0;
-	obj->proto_stat_data[i].kb.now = 0;
-    }
-    *object = obj;
+    debug(18, 5) ("statInit: Initializing...\n");
     for (i = 0; i < PCONN_HIST_SZ; i++) {
 	client_pconn_hist[i] = 0;
 	server_pconn_hist[i] = 0;
     }
+    memset(CountHist, '\0', N_COUNT_HIST * sizeof(StatCounters));
+    for (i=0; i<N_COUNT_HIST; i++)
+	CountHist[i].timestamp = current_time;
+    Counter.timestamp = current_time;
+    eventAdd("statAvgTick", statAvgTick, NULL, 60);
 }
 
 void
