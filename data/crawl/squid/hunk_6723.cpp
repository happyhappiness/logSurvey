     c->page_faults = rusage_pagefaults(&rusage);
     c->cputime = rusage_cputime(&rusage);
     c->timestamp = current_time;
+    /* even if NCountHist is small, we already Init()ed the tail */
+    statCountersClean(CountHist+N_COUNT_HIST-1);
     xmemmove(p, t, (N_COUNT_HIST - 1) * sizeof(StatCounters));
+#if 0
     memcpy(t, c, sizeof(StatCounters));
+#endif
+    statCountersCopy(t, c);
     NCountHist++;
 }
 
-void
-statCounters(StoreEntry * e)
+/* add special cases here as they arrive */
+static void
+statCountersInit(StatCounters *C)
 {
-    statCountersDump(e);
+    assert(C);
+    C->timestamp = current_time;
+    /*
+     * HTTP svc_time hist is kept in milli-seconds; max of 3 hours.
+     */
+    statHistLogInit(&C->client_http.all_svc_time, 300, 0.0, 3600000.0 * 3.0);
+    statHistLogInit(&C->client_http.miss_svc_time, 300, 0.0, 3600000.0 * 3.0);
+    statHistLogInit(&C->client_http.nm_svc_time, 300, 0.0, 3600000.0 * 3.0);
+    statHistLogInit(&C->client_http.hit_svc_time, 300, 0.0, 3600000.0 * 3.0);
+    /*
+     * ICP svc_time hist is kept in micro-seconds; max of 1 minute.
+     */
+    statHistLogInit(&C->icp.query_svc_time, 300, 0.0, 1000000.0 * 60.0);
+    statHistLogInit(&C->icp.reply_svc_time, 300, 0.0, 1000000.0 * 60.0);
+    /*
+     * DNS svc_time hist is kept in milli-seconds; max of 10 minutes.
+     */
+    statHistLogInit(&C->dns.svc_time, 300, 0.0, 60000.0 * 10.0);
 }
 
+/* add special cases here as they arrive */
 void
-statAvg5min(StoreEntry * e)
+statCountersClean(StatCounters *C)
 {
-    statAvgDump(e, 5);
+    assert(C);
+    statHistClean(&C->client_http.all_svc_time);
+    statHistClean(&C->client_http.miss_svc_time);
+    statHistClean(&C->client_http.nm_svc_time);
+    statHistClean(&C->client_http.hit_svc_time);
+    statHistClean(&C->icp.query_svc_time);
+    statHistClean(&C->icp.reply_svc_time);
+    statHistClean(&C->dns.svc_time);
 }
 
+/* add special cases here as they arrive */
 void
-statAvg60min(StoreEntry * e)
+statCountersCopy(StatCounters *dest, const StatCounters *orig)
 {
-    statAvgDump(e, 60);
+    assert(dest && orig);
+    /* prepare space where to copy */
+    statCountersInit(dest);
+    /* this should take care of most of the fields */
+    memcpy(dest, orig, sizeof(*dest));
+    /* now handle spacial cases */
+    /* note: we assume that histogram capacities do not change */
+    statHistCopy(&dest->client_http.all_svc_time, &orig->client_http.all_svc_time);
+    statHistCopy(&dest->client_http.miss_svc_time, &orig->client_http.miss_svc_time);
+    statHistCopy(&dest->client_http.nm_svc_time, &orig->client_http.nm_svc_time);
+    statHistCopy(&dest->client_http.hit_svc_time, &orig->client_http.hit_svc_time);
+    statHistCopy(&dest->icp.query_svc_time, &orig->icp.query_svc_time);
+    statHistCopy(&dest->icp.reply_svc_time, &orig->icp.reply_svc_time);
+    statHistCopy(&dest->dns.svc_time, &orig->dns.svc_time);
 }
 
-void
-statLogHistInit(StatLogHist * H, double min, double max)
+static void
+statCountersDump(StoreEntry * sentry)
 {
-    H->min = min;
-    H->max = max;
-    H->scale = (STAT_LOG_HIST_BINS - 1) / log(1.0 + max - min);
+    StatCounters *f = &Counter;
+    struct rusage rusage;
+    squid_getrusage(&rusage);
+    f->page_faults = rusage_pagefaults(&rusage);
+    f->cputime = rusage_cputime(&rusage);
+
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
+    storeAppendPrintf(sentry, "client_http.all_svc_time histogram:\n");
+    statHistDump(&f->client_http.all_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.miss_svc_time histogram:\n");
+    statHistDump(&f->client_http.miss_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.nm_svc_time histogram:\n");
+    statHistDump(&f->client_http.nm_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "client_http.hit_svc_time histogram:\n");
+    statHistDump(&f->client_http.hit_svc_time, sentry, NULL);
+
+    storeAppendPrintf(sentry, "server.requests = %d\n",
+	(int) f->server.requests);
+    storeAppendPrintf(sentry, "server.errors = %d\n",
+	(int) f->server.errors);
+    storeAppendPrintf(sentry, "server.kbytes_in = %d\n",
+	(int) f->server.kbytes_in.kb);
+    storeAppendPrintf(sentry, "server.kbytes_out = %d\n",
+	(int) f->server.kbytes_out.kb);
+
+    storeAppendPrintf(sentry, "icp.pkts_sent = %d\n",
+	f->icp.pkts_sent);
+    storeAppendPrintf(sentry, "icp.pkts_recv = %d\n",
+	f->icp.pkts_recv);
+    storeAppendPrintf(sentry, "icp.kbytes_sent = %d\n",
+	(int) f->icp.kbytes_sent.kb);
+    storeAppendPrintf(sentry, "icp.kbytes_recv = %d\n",
+	(int) f->icp.kbytes_recv.kb);
+    storeAppendPrintf(sentry, "icp.query_svc_time histogram:\n");
+    statHistDump(&f->icp.query_svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "icp.reply_svc_time histogram:\n");
+    statHistDump(&f->icp.reply_svc_time, sentry, NULL);
+
+    storeAppendPrintf(sentry, "dns.svc_time histogram:\n");
+    statHistDump(&f->dns.svc_time, sentry, NULL);
+    storeAppendPrintf(sentry, "unlink.requests = %d\n",
+	f->unlink.requests);
+    storeAppendPrintf(sentry, "page_faults = %d\n",
+	f->page_faults);
+    storeAppendPrintf(sentry, "select_loops = %d\n",
+	f->select_loops);
+    storeAppendPrintf(sentry, "cpu_time = %f\n",
+	f->cputime);
+    storeAppendPrintf(sentry, "wall_time = %f\n",
+	tvSubDsec(f->timestamp, current_time));
 }
 
 void
-statLogHistCount(StatLogHist * H, double val)
+statCounters(StoreEntry * e)
 {
-    int bin = statLogHistBin(H, val);
-    assert(H->scale != 0.0);	/* make sure it got initialized */
-    assert(0 <= bin && bin < STAT_LOG_HIST_BINS);
-    H->bins[bin]++;
+    statCountersDump(e);
 }
 
-double
-statLogHistDeltaMedian(StatLogHist * A, StatLogHist * B)
+void
+statAvg5min(StoreEntry * e)
 {
-    StatLogHist D;
-    int i;
-    int s1 = 0;
-    int h = 0;
-    int a = 0;
-    int b = 0;
-    int I = 0;
-    int J = STAT_LOG_HIST_BINS;
-    int K;
-    double f;
-    memset(&D, '\0', sizeof(StatLogHist));
-    for (i = 0; i < STAT_LOG_HIST_BINS; i++) {
-	assert(B->bins[i] >= A->bins[i]);
-	D.bins[i] = B->bins[i] - A->bins[i];
-    }
-    for (i = 0; i < STAT_LOG_HIST_BINS; i++)
-	s1 += D.bins[i];
-    h = s1 >> 1;
-    for (i = 0; i < STAT_LOG_HIST_BINS; i++) {
-	J = i;
-	b += D.bins[J];
-	if (a <= h && h <= b)
-	    break;
-	I = i;
-	a += D.bins[I];
-    }
-    if (s1 == 0)
-	return 0.0;
-    if (a > h) {
-	debug(0, 0) ("statLogHistDeltaMedian: a=%d, h=%d\n", a, h);
-	return 0.0;
-    }
-    if (a >= b) {
-	debug(0, 0) ("statLogHistDeltaMedian: a=%d, b=%d\n", a, b);
-	return 0.0;
-    }
-    if (I >= J) {
-	debug(0, 0) ("statLogHistDeltaMedian: I=%d, J=%d\n", I, J);
-	return 0.0;
-    }
-    f = (h - a) / (b - a);
-    K = f * (double) (J - I) + I;
-    return statLogHistVal(A, K);
+    statAvgDump(e, 5);
 }
 
-static int
-statLogHistBin(StatLogHist * H, double v)
+void
+statAvg60min(StoreEntry * e)
 {
-    int bin;
-    double x = 1.0 + v - H->min;
-    if (x < 0.0)
-	return 0;
-    bin = (int) (H->scale * log(x) + 0.5);
-    if (bin < 0)
-	bin = 0;
-    if (bin > STAT_LOG_HIST_BINS - 1)
-	bin = STAT_LOG_HIST_BINS - 1;
-    return bin;
+    statAvgDump(e, 60);
 }
 
-static double
-statLogHistVal(StatLogHist * H, double bin)
-{
-    return exp(bin / H->scale) + H->min - 1.0;
-}
 
 enum {
     HTTP_SVC, ICP_SVC, DNS_SVC
