 print_stats()
 {
 #ifdef WITH_LIB
-        memReport(stdout); 
+    memReport(stdout);
 #endif
-	getrusage(RUSAGE_SELF, &myusage);
-	printf("m/c/f/r=%d/%d/%d/%d\n",mstat.mallocs,mstat.callocs,
-					mstat.frees, mstat.reallocs);
+    getrusage(RUSAGE_SELF, &myusage);
+    printf("m/c/f/r=%d/%d/%d/%d\n", mstat.mallocs, mstat.callocs,
+	mstat.frees, mstat.reallocs);
 #if 0
-	printf("types                 : %d\n",size2id_len);
+    printf("types                 : %d\n", size2id_len);
 #endif
-	printf("user time used        : %d.%d\n", (int)myusage.ru_utime.tv_sec,
-						(int)myusage.ru_utime.tv_usec);
-	printf("system time used      : %d.%d\n", (int)myusage.ru_stime.tv_sec,
-                                                (int)myusage.ru_stime.tv_usec);
-	printf("max resident set size : %d\n",(int)myusage.ru_maxrss);
-	printf("page faults           : %d\n", (int)myusage.ru_majflt);
+    printf("user time used        : %d.%d\n", (int) myusage.ru_utime.tv_sec,
+	(int) myusage.ru_utime.tv_usec);
+    printf("system time used      : %d.%d\n", (int) myusage.ru_stime.tv_sec,
+	(int) myusage.ru_stime.tv_usec);
+    printf("max resident set size : %d\n", (int) myusage.ru_maxrss);
+    printf("page faults           : %d\n", (int) myusage.ru_majflt);
 }
 
 void
-size2id(size_t sz,memitem *mi)
+size2id(size_t sz, memitem * mi)
 {
 #ifdef WITH_LIB
-	mi->pool = sizeToPool(sz);
-	assert(mi->pool);
+    mi->pool = sizeToPool(sz);
+    assert(mi->pool);
 #endif
-	return;
+    return;
 }
 
 void
 badformat()
 {
-    fprintf(stderr,"pummel.bad.format\n");
+    fprintf(stderr, "pummel.bad.format\n");
     exit(1);
 }
 
 /* unused code, saved for parts */
 const char *
 make_nam(int id, int size)
 {
-    const char *buf = malloc(30); /* argh */
-    sprintf((char *)buf, "pl:%d/%d", id, size);
+    const char *buf = malloc(30);	/* argh */
+    sprintf((char *) buf, "pl:%d/%d", id, size);
     return buf;
 }
 
 void
-my_hash_insert(hash_table *h, const char *k, memitem *item)
-{	
-	memitem *l;
-	assert( item->pool);
-	assert( item->my_ptr);	
-	hash_insert(h,k,item);
+my_hash_insert(hash_table * h, const char *k, memitem * item)
+{
+    memitem *l;
+    assert(item->pool);
+    assert(item->my_ptr);
+    hash_insert(h, k, item);
 }
 
 static void *
-xmemAlloc(memitem *item)
+xmemAlloc(memitem * item)
 {
     extern MemPool *StringPool;
     assert(item && item->pool);
