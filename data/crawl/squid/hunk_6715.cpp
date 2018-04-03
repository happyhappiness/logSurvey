     return httpHeaderExtFieldCreate(f->name, f->value);
 }
 
-#if 0 /* save for parts */
-
-/*
- * returns the space requred to put a field (and terminating <CRLF>!) into a
- * buffer
- */
-static size_t
-httpHeaderFieldBufSize(const HttpHeaderExtField *fld)
-{
-    return strlen(fld->name)+2+strlen(fld->value)+2;
-}
-
 /*
- * returns true if fld.name is a "known" splitable field; 
- * always call this function to check because the detection algortihm may change
+ * Reports
  */
-static int
-httpHeaderFieldIsList(const HttpHeaderExtField *fld) {
-    int i;
-    assert(fld);
-    /* "onten" should not match "Content"! */
-    for (i = 0; i < KnownSplitableFieldCount; ++i)
-	if (strcasecmp(KnownSplitableFields[i], fld->name))
-	    return 1;
-    return 0;
-}
-
-#endif
 
 static void
-httpHeaderStoreAReport(StoreEntry *e, void (*reportPacker)(Packer *p))
+httpHeaderFieldStatDumper(StoreEntry * sentry, int idx, double val, double size, int count)
 {
-    Packer p;
-    assert(e);
-    packerToStoreInit(&p, e);
-    (*reportPacker)(&p);
-    packerClean(&p);
+    const int id = (int) val;
+    const int valid_id = id >= 0 && id < HDR_ENUM_END;
+    const char *name = valid_id ? Headers[id].name : "INVALID";
+    if (count || valid_id)
+	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
+	    id, name, count, xdiv(count, HeaderParsedCount));
 }
 
-void
-httpHeaderStoreReport(StoreEntry *e)
+static void
+httpHeaderCCStatDumper(StoreEntry * sentry, int idx, double val, double size, int count)
 {
-    httpHeaderStoreAReport(e, &httpHeaderPackReport); 
+    const int id = (int) val;
+    const int valid_id = id >= 0 && id < SCC_ENUM_END;
+    const char *name = valid_id ? SccAttrs[id].name : "INVALID";
+    if (count || valid_id)
+	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
+	    id, name, count, xdiv(count, CcPasredCount));
 }
 
-void
-httpHeaderStoreReqReport(StoreEntry *e)
-{
-    httpHeaderStoreAReport(e, &httpHeaderPackReqReport); 
-}
 
-void
-httpHeaderStoreRepReport(StoreEntry *e)
+static void
+httpHeaderFldsPerHdrDumper(StoreEntry * sentry, int idx, double val, double size, int count)
 {
-    httpHeaderStoreAReport(e, &httpHeaderPackRepReport); 
+    if (count)
+	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\t %6.2f\n",
+	    idx, ((int)(val+size)), count, xpercent(count, HeaderEntryParsedCount));
 }
 
 
 static void
-httpHeaderPackReport(Packer *p)
-{
-    assert(p);
-
-    httpHeaderPackRepReport(p);
-    httpHeaderPackReqReport(p);
-
-    /* low level totals; reformat this? @?@ */
-    packerPrintf(p,
-	"hdrs totals: %uld+%uld %s lstr: +%uld-%uld<(%uld=%uld)\n",
-	shortHeadersCount,
-	longHeadersCount,
-	memPoolReport(shortStrings),
-	longStrAllocCount,
-	longStrFreeCount,
-	longStrHighWaterCount,
-	longStrHighWaterSize);
+httpHeaderStatDump(const HttpHeaderStat *hs, StoreEntry *e)
+{
+    assert(hs && e);
+
+    storeAppendPrintf(e, "\n<h3>Header Stats: %s</h3>\n", hs->label);
+    storeAppendPrintf(e, "\t<h3>Field type distribution</h3>\n");
+    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
+	"id", "name", "count", "#/header");
+    statHistDump(&hs->fieldTypeDistr, e, httpHeaderFieldStatDumper);
+    storeAppendPrintf(e, "\t<h3>Cache-control directives distribution</h3>\n");
+    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
+	"id", "name", "count", "#/cc_field");
+    statHistDump(&hs->ccTypeDistr, e, httpHeaderCCStatDumper);
+    storeAppendPrintf(e, "\t<h3>Number of fields per header distribution (init size: %d)</h3>\n",
+	INIT_FIELDS_PER_HEADER);
+    storeAppendPrintf(e, "%2s\t %-5s\t %5s\t %6s\n",
+	"id", "#flds", "count", "%total");
+    statHistDump(&hs->hdrUCountDistr, e, httpHeaderFldsPerHdrDumper);
 }
 
 static void
-httpHeaderPackRepReport(Packer *p)
-{
-    assert(p);
-#if 0 /* implement this */
-    httpHeaderPackAReport(p, &ReplyHeaderStats);
-    for (i = SCC_PUBLIC; i < SCC_ENUM_END; i++)
-	storeAppendPrintf(entry, "Cache-Control %s: %d\n",
-	    HttpServerCCStr[i],
-	    ReplyHeaderStats.cc[i]);
-#endif
+shortStringStatDump(StoreEntry *e)
+{
+    storeAppendPrintf(e, "<h3>Short String Stats</h3>\n<p>%s\n</p>\n",
+	memPoolReport(shortStrings));
+    storeAppendPrintf(e, "<br><h3>Long String Stats</h3>\n");
+    storeAppendPrintf(e, "\talive: %3d (%5.1f KB) high-water:  %3d (%5.1f KB)\n",
+	longStrAliveCount, longStrAliveSize/1024.,
+	longStrHighWaterCount, longStrHighWaterSize/1024.);
 }
 
-static void
-httpHeaderPackReqReport(Packer *p)
+void
+httpHeaderStoreReport(StoreEntry *e)
 {
-    assert(p);
-#if 0 /* implement this */
-    httpHeaderPackAReport(p, &RequestHeaderStats);
-#endif
-}
+    int i;
+    http_hdr_type ht;
+    assert(e);
 
-#if 0 /* implement this */
-static void
-httpHeaderPackAReport(Packer *p, HttpHeaderStats *stats)
-{
-    assert(p);
-    assert(stats);
-    assert(0);
-    http_server_cc_t i;
-    http_hdr_misc_t j;
-    storeAppendPrintf(entry, "HTTP Reply Headers:\n");
-    storeAppendPrintf(entry, "       Headers parsed: %d\n",
-	ReplyHeaderStats.parsed);
-    for (j = HDR_AGE; j < HDR_MISC_END; j++)
-	storeAppendPrintf(entry, "%21.21s: %d\n",
-	    HttpHdrMiscStr[j],
-	    ReplyHeaderStats.misc[j]);
+    /* fix this (including summing for totals) for req hdrs @?@ */
+    for (i = 0; i < 1 /*HttpHeaderStatCount*/; i++) {
+	httpHeaderStatDump(HttpHeaderStats+i, e);
+	storeAppendPrintf(e, "%s\n", "<br>");
+    }
+    storeAppendPrintf(e, "%s\n", "<hr size=1 noshade>");
+    /* field stats */
+    storeAppendPrintf(e, "<h3>Http Fields Stats (replies and requests)</h3>\n");
+    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\t %6s\n",
+	"id", "name", "#alive", "%err", "%repeat");
+    for (ht = 0; ht < HDR_ENUM_END; ht++) {
+	field_attrs_t *f = Headers+ht;
+	storeAppendPrintf(e, "%2d\t %-20s\t %5d\t %6.3f\t %6.3f\n",
+	    f->id, f->name, f->stat.aliveCount,
+	    xpercent(f->stat.errCount, f->stat.parsCount), 
+	    xpercent(f->stat.repCount, f->stat.parsCount));
+    }
+    storeAppendPrintf(e, "%s\n", "<hr size=1 noshade>");
+    /* short strings */
+    shortStringStatDump(e);
 }
-#endif
 
-/* "short string" routines below are trying to recycle memory for short strings */
+
+/*
+ * "short string" routines below are trying to recycle memory for short strings
+ */
+
 static char *
 dupShortStr(const char *str)
 {
