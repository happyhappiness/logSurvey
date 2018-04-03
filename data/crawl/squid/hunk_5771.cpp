 const HttpHeaderStat *dump_stat = NULL;
 
 static void
-httpHeaderFieldStatDumper(StoreEntry * sentry, int idx, double val, double size, int count)
+httpHeaderFieldStatDumper (StoreEntry * sentry, int idx, double val, double size, int count)
 {
-    const int id = (int) val;
-    const int valid_id = id >= 0 && id < HDR_ENUM_END;
-    const char *name = valid_id ? strBuf(Headers[id].name) : "INVALID";
-    int visible = count > 0;
-    /* for entries with zero count, list only those that belong to current type of message */
-    if (!visible && valid_id && dump_stat->owner_mask)
-	visible = CBIT_TEST(*dump_stat->owner_mask, id);
-    if (visible)
-	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
-	    id, name, count, xdiv(count, dump_stat->busyDestroyedCount));
+  const int id = (int) val;
+  const int valid_id = id >= 0 && id < HDR_ENUM_END;
+  const char *name = valid_id ? strBuf (Headers[id].name) : "INVALID";
+  int visible = count > 0;
+  /* for entries with zero count, list only those that belong to current type of message */
+  if (!visible && valid_id && dump_stat->owner_mask)
+    visible = CBIT_TEST (*dump_stat->owner_mask, id);
+  if (visible)
+    storeAppendPrintf (sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
+	      id, name, count, xdiv (count, dump_stat->busyDestroyedCount));
 }
 
 static void
-httpHeaderFldsPerHdrDumper(StoreEntry * sentry, int idx, double val, double size, int count)
+httpHeaderFldsPerHdrDumper (StoreEntry * sentry, int idx, double val, double size, int count)
 {
-    if (count)
-	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\t %6.2f\n",
-	    idx, (int) val, count,
-	    xpercent(count, dump_stat->destroyedCount));
+  if (count)
+    storeAppendPrintf (sentry, "%2d\t %5d\t %5d\t %6.2f\n",
+		       idx, (int) val, count,
+		       xpercent (count, dump_stat->destroyedCount));
 }
 
 
 static void
-httpHeaderStatDump(const HttpHeaderStat * hs, StoreEntry * e)
+httpHeaderStatDump (const HttpHeaderStat * hs, StoreEntry * e)
 {
-    assert(hs && e);
-
-    dump_stat = hs;
-    storeAppendPrintf(e, "\nHeader Stats: %s\n", hs->label);
-    storeAppendPrintf(e, "\nField type distribution\n");
-    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
-	"id", "name", "count", "#/header");
-    statHistDump(&hs->fieldTypeDistr, e, httpHeaderFieldStatDumper);
-    storeAppendPrintf(e, "\nCache-control directives distribution\n");
-    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
-	"id", "name", "count", "#/cc_field");
-    statHistDump(&hs->ccTypeDistr, e, httpHdrCcStatDumper);
-    storeAppendPrintf(e, "\nNumber of fields per header distribution\n");
-    storeAppendPrintf(e, "%2s\t %-5s\t %5s\t %6s\n",
-	"id", "#flds", "count", "%total");
-    statHistDump(&hs->hdrUCountDistr, e, httpHeaderFldsPerHdrDumper);
-    dump_stat = NULL;
+  assert (hs && e);
+
+  dump_stat = hs;
+  storeAppendPrintf (e, "\nHeader Stats: %s\n", hs->label);
+  storeAppendPrintf (e, "\nField type distribution\n");
+  storeAppendPrintf (e, "%2s\t %-20s\t %5s\t %6s\n",
+		     "id", "name", "count", "#/header");
+  statHistDump (&hs->fieldTypeDistr, e, httpHeaderFieldStatDumper);
+  storeAppendPrintf (e, "\nCache-control directives distribution\n");
+  storeAppendPrintf (e, "%2s\t %-20s\t %5s\t %6s\n",
+		     "id", "name", "count", "#/cc_field");
+  statHistDump (&hs->ccTypeDistr, e, httpHdrCcStatDumper);
+  storeAppendPrintf (e, "\nNumber of fields per header distribution\n");
+  storeAppendPrintf (e, "%2s\t %-5s\t %5s\t %6s\n",
+		     "id", "#flds", "count", "%total");
+  statHistDump (&hs->hdrUCountDistr, e, httpHeaderFldsPerHdrDumper);
+  dump_stat = NULL;
 }
 
 void
-httpHeaderStoreReport(StoreEntry * e)
+httpHeaderStoreReport (StoreEntry * e)
 {
-    int i;
-    http_hdr_type ht;
-    assert(e);
-
-    HttpHeaderStats[0].parsedCount =
-	HttpHeaderStats[hoRequest].parsedCount + HttpHeaderStats[hoReply].parsedCount;
-    HttpHeaderStats[0].ccParsedCount =
-	HttpHeaderStats[hoRequest].ccParsedCount + HttpHeaderStats[hoReply].ccParsedCount;
-    HttpHeaderStats[0].destroyedCount =
-	HttpHeaderStats[hoRequest].destroyedCount + HttpHeaderStats[hoReply].destroyedCount;
-    HttpHeaderStats[0].busyDestroyedCount =
-	HttpHeaderStats[hoRequest].busyDestroyedCount + HttpHeaderStats[hoReply].busyDestroyedCount;
-
-    for (i = 1; i < HttpHeaderStatCount; i++) {
-	httpHeaderStatDump(HttpHeaderStats + i, e);
-	storeAppendPrintf(e, "%s\n", "<br>");
+  int i;
+  http_hdr_type ht;
+  assert (e);
+
+  HttpHeaderStats[0].parsedCount =
+    HttpHeaderStats[hoRequest].parsedCount + HttpHeaderStats[hoReply].parsedCount;
+  HttpHeaderStats[0].ccParsedCount =
+    HttpHeaderStats[hoRequest].ccParsedCount + HttpHeaderStats[hoReply].ccParsedCount;
+  HttpHeaderStats[0].destroyedCount =
+    HttpHeaderStats[hoRequest].destroyedCount + HttpHeaderStats[hoReply].destroyedCount;
+  HttpHeaderStats[0].busyDestroyedCount =
+    HttpHeaderStats[hoRequest].busyDestroyedCount + HttpHeaderStats[hoReply].busyDestroyedCount;
+
+  for (i = 1; i < HttpHeaderStatCount; i++)
+    {
+      httpHeaderStatDump (HttpHeaderStats + i, e);
+      storeAppendPrintf (e, "%s\n", "<br>");
     }
-    /* field stats for all messages */
-    storeAppendPrintf(e, "\nHttp Fields Stats (replies and requests)\n");
-    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\t %6s\n",
-	"id", "name", "#alive", "%err", "%repeat");
-    for (ht = 0; ht < HDR_ENUM_END; ht++) {
-	HttpHeaderFieldInfo *f = Headers + ht;
-	storeAppendPrintf(e, "%2d\t %-20s\t %5d\t %6.3f\t %6.3f\n",
-	    f->id, strBuf(f->name), f->stat.aliveCount,
-	    xpercent(f->stat.errCount, f->stat.parsCount),
-	    xpercent(f->stat.repCount, f->stat.seenCount));
+  /* field stats for all messages */
+  storeAppendPrintf (e, "\nHttp Fields Stats (replies and requests)\n");
+  storeAppendPrintf (e, "%2s\t %-20s\t %5s\t %6s\t %6s\n",
+		     "id", "name", "#alive", "%err", "%repeat");
+  for (ht = 0; ht < HDR_ENUM_END; ht++)
+    {
+      HttpHeaderFieldInfo *f = Headers + ht;
+      storeAppendPrintf (e, "%2d\t %-20s\t %5d\t %6.3f\t %6.3f\n",
+			 f->id, strBuf (f->name), f->stat.aliveCount,
+			 xpercent (f->stat.errCount, f->stat.parsCount),
+			 xpercent (f->stat.repCount, f->stat.seenCount));
     }
-    storeAppendPrintf(e, "Headers Parsed: %d + %d = %d\n",
-	HttpHeaderStats[hoRequest].parsedCount,
-	HttpHeaderStats[hoReply].parsedCount,
-	HttpHeaderStats[0].parsedCount);
-    storeAppendPrintf(e, "Hdr Fields Parsed: %d\n", HeaderEntryParsedCount);
+  storeAppendPrintf (e, "Headers Parsed: %d + %d = %d\n",
+		     HttpHeaderStats[hoRequest].parsedCount,
+		     HttpHeaderStats[hoReply].parsedCount,
+		     HttpHeaderStats[0].parsedCount);
+  storeAppendPrintf (e, "Hdr Fields Parsed: %d\n", HeaderEntryParsedCount);
 }
 
 int
-httpHeaderIdByName(const char *name, int name_len, const HttpHeaderFieldInfo * info, int end)
+httpHeaderIdByName (const char *name, int name_len, const HttpHeaderFieldInfo * info, int end)
 {
-    int i;
-    for (i = 0; i < end; ++i) {
-	if (name_len >= 0 && name_len != strLen(info[i].name))
-	    continue;
-	if (!strncasecmp(name, strBuf(info[i].name),
-		name_len < 0 ? strLen(info[i].name) + 1 : name_len))
-	    return i;
+  int i;
+  for (i = 0; i < end; ++i)
+    {
+      if (name_len >= 0 && name_len != strLen (info[i].name))
+	continue;
+      if (!strncasecmp (name, strBuf (info[i].name),
+			name_len < 0 ? strLen (info[i].name) + 1 : name_len))
+	return i;
     }
-    return -1;
+  return -1;
 }
 
 int
-httpHeaderIdByNameDef(const char *name, int name_len)
+httpHeaderIdByNameDef (const char *name, int name_len)
 {
-    if (!Headers)
-	Headers = httpHeaderBuildFieldsInfo(HeadersAttrs, HDR_ENUM_END);
-    return httpHeaderIdByName(name, name_len, Headers, HDR_ENUM_END);
+  if (!Headers)
+    Headers = httpHeaderBuildFieldsInfo (HeadersAttrs, HDR_ENUM_END);
+  return httpHeaderIdByName (name, name_len, Headers, HDR_ENUM_END);
 }
 
 const char *
-httpHeaderNameById(int id)
+httpHeaderNameById (int id)
 {
-    if (!Headers)
-	Headers = httpHeaderBuildFieldsInfo(HeadersAttrs, HDR_ENUM_END);
-    assert(id >= 0 && id < HDR_ENUM_END);
-    return HeadersAttrs[id].name;
+  if (!Headers)
+    Headers = httpHeaderBuildFieldsInfo (HeadersAttrs, HDR_ENUM_END);
+  assert (id >= 0 && id < HDR_ENUM_END);
+  return HeadersAttrs[id].name;
 }
