 int
 main(int argc, char *argv[])
 {
-    CacheIndex *they = NULL;
     FileIterator **fis = NULL;
     const int fi_count = argc-1;
-    int i, j;
+    int active_fi_count = 0;
+    Cache *them, *us;
+    int i;
 
     if (argc < 3)
 	return usage(argv[0]);
 
+    them = cacheCreate("them");
+    us = cacheCreate("us");
+    them->peer = us;
+    us->peer = them;
+
     fis = xcalloc(fi_count, sizeof(FileIterator *));
     /* init iterators with files */
     fis[0] = fileIteratorCreate(argv[1], accessLogReader);
     for (i = 2; i < argc; ++i) {
 	fis[i-1] = fileIteratorCreate(argv[i], swapStateReader);
     }
-    /* read prefix to get start-up contents of peer cache */
+    /* read prefix to get start-up contents of the peer cache */
     for (i = 1; i < fi_count; ++i) {
-	fileIteratorScan(fis[i], swapStatePrefixScanner);
+	FileIterator *fi = fis[i];
+	while (fi->inner_time > 0) {
+	    if (((storeSwapLogData*)fi->entry)->op != SWAP_LOG_ADD) {
+		break;
+	    } else {
+		cacheStore(them, fi->entry, 0);
+		fileIteratorAdvance(fi);
+	    }
+	}
     }
     /* digest peer cache content */
-    /* ...resetDigest() */
-    /* iterate */
+    cacheResetDigest(them);
+    us->digest = cacheDigestClone(them->digest); /* @netw@ */
+
+    /* iterate, use the iterator with the smallest positive inner_time */
     cur_time = -1;
-    for (i = 0; i < fi_count; ++i) {
-	int next_i = -1;
-	time_t next_time = -1;
-	for (j = 0; j < fi_count; ++j) {
-	    if (fis[j].inner_time > next_time) 
+    do {
+        int next_i = -1;
+        time_t next_time = -1;
+	active_fi_count = 0;
+	for (i = 0; i < fi_count; ++i) {
+	    if (fis[i]->inner_time >= 0) {
+	        if (!active_fi_count || fis[i]->inner_time < next_time) {
+		    next_i = i;
+		    next_time = fis[i]->inner_time;
+		}
+		active_fi_count++;
+	    }
 	}
-    }
-    /* cleaning */
-    for (int i = 0; i < argc-1; ++i) {
+	if (next_i >= 0) {
+	    /* skip access log entries recorder before creation of swap.state */
+	    if (cur_time > 0 || next_i > 0) {
+		cur_time = next_time;
+		/*fprintf(stderr, "%2d time: %d %s", next_i, (int)cur_time, ctime(&cur_time));*/
+		if (next_i == 0)
+		    cacheFetch(us, fis[next_i]->entry);
+		else
+		    cacheUpdateStore(them, fis[next_i]->entry, 0);
+	    }
+	    fileIteratorAdvance(fis[next_i]);
+	}
+    } while (active_fi_count);
+
+    /* report */
+    cacheQueryReport(us, &us->qstats);
+
+    /* clean */
+    for (i = 0; i < argc-1; ++i) {
 	fileIteratorDestroy(fis[i]);
     }
     xfree(fis);
-
+    cacheDestroy(them);
+    cacheDestroy(us);
     return 0;
 }