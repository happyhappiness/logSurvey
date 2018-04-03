 
 /* test if a field is present */
 int
-httpHeaderHas(const HttpHeader * hdr, http_hdr_type id)
+HttpHeader::has(http_hdr_type id) const
 {
-    assert(hdr);
     assert_eid(id);
     assert(id != HDR_OTHER);
-    debug(55, 9) ("%p lookup for %d\n", hdr, id);
-    return CBIT_TEST(hdr->mask, id);
+    debug(55, 9) ("%p lookup for %d\n", this, id);
+    return CBIT_TEST(mask, id);
 }
 
 void
-httpHeaderPutInt(HttpHeader * hdr, http_hdr_type id, int number)
+HttpHeader::putInt(http_hdr_type id, int number)
 {
     assert_eid(id);
     assert(Headers[id].type == ftInt);	/* must be of an appropriate type */
     assert(number >= 0);
-    httpHeaderAddEntry(hdr, httpHeaderEntryCreate(id, NULL, xitoa(number)));
+    addEntry(httpHeaderEntryCreate(id, NULL, xitoa(number)));
 }
 
 void
-httpHeaderPutTime(HttpHeader * hdr, http_hdr_type id, time_t htime)
+HttpHeader::putTime(http_hdr_type id, time_t htime)
 {
     assert_eid(id);
     assert(Headers[id].type == ftDate_1123);	/* must be of an appropriate type */
     assert(htime >= 0);
-    httpHeaderAddEntry(hdr, httpHeaderEntryCreate(id, NULL, mkrfc1123(htime)));
+    addEntry(httpHeaderEntryCreate(id, NULL, mkrfc1123(htime)));
 }
 
 void
-httpHeaderInsertTime(HttpHeader * hdr, http_hdr_type id, time_t htime)
+HttpHeader::insertTime(http_hdr_type id, time_t htime)
 {
     assert_eid(id);
     assert(Headers[id].type == ftDate_1123);	/* must be of an appropriate type */
     assert(htime >= 0);
-    httpHeaderInsertEntry(hdr, httpHeaderEntryCreate(id, NULL, mkrfc1123(htime)));
+    insertEntry(httpHeaderEntryCreate(id, NULL, mkrfc1123(htime)));
 }
 
 void
-httpHeaderPutStr(HttpHeader * hdr, http_hdr_type id, const char *str)
+HttpHeader::putStr(http_hdr_type id, const char *str)
 {
     assert_eid(id);
     assert(Headers[id].type == ftStr);	/* must be of an appropriate type */
     assert(str);
-    httpHeaderAddEntry(hdr, httpHeaderEntryCreate(id, NULL, str));
+    addEntry(httpHeaderEntryCreate(id, NULL, str));
 }
 
 void
-httpHeaderPutAuth(HttpHeader * hdr, const char *auth_scheme, const char *realm)
+HttpHeader::putAuth(const char *auth_scheme, const char *realm)
 {
-    assert(hdr && auth_scheme && realm);
-    httpHeaderPutStrf(hdr, HDR_WWW_AUTHENTICATE, "%s realm=\"%s\"", auth_scheme, realm);
+    assert(auth_scheme && realm);
+    httpHeaderPutStrf(this, HDR_WWW_AUTHENTICATE, "%s realm=\"%s\"", auth_scheme, realm);
 }
 
 void
-httpHeaderPutCc(HttpHeader * hdr, const HttpHdrCc * cc)
+HttpHeader::putCc(const HttpHdrCc * cc)
 {
     MemBuf mb;
     Packer p;
-    assert(hdr && cc);
+    assert(cc);
     /* remove old directives if any */
-    httpHeaderDelById(hdr, HDR_CACHE_CONTROL);
+    delById(HDR_CACHE_CONTROL);
     /* pack into mb */
     mb.init();
     packerToMemInit(&p, &mb);
     httpHdrCcPackInto(cc, &p);
     /* put */
-    httpHeaderAddEntry(hdr, httpHeaderEntryCreate(HDR_CACHE_CONTROL, NULL, mb.buf));
+    addEntry(httpHeaderEntryCreate(HDR_CACHE_CONTROL, NULL, mb.buf));
     /* cleanup */
     packerClean(&p);
     mb.clean();
 }
 
 void
-httpHeaderPutContRange(HttpHeader * hdr, const HttpHdrContRange * cr)
+HttpHeader::putContRange(const HttpHdrContRange * cr)
 {
     MemBuf mb;
     Packer p;
-    assert(hdr && cr);
+    assert(cr);
     /* remove old directives if any */
-    httpHeaderDelById(hdr, HDR_CONTENT_RANGE);
+    delById(HDR_CONTENT_RANGE);
     /* pack into mb */
     mb.init();
     packerToMemInit(&p, &mb);
     httpHdrContRangePackInto(cr, &p);
     /* put */
-    httpHeaderAddEntry(hdr, httpHeaderEntryCreate(HDR_CONTENT_RANGE, NULL, mb.buf));
+    addEntry(httpHeaderEntryCreate(HDR_CONTENT_RANGE, NULL, mb.buf));
     /* cleanup */
     packerClean(&p);
     mb.clean();
 }
 
 void
-httpHeaderPutRange(HttpHeader * hdr, const HttpHdrRange * range)
+HttpHeader::putRange(const HttpHdrRange * range)
 {
     MemBuf mb;
     Packer p;
-    assert(hdr && range);
+    assert(range);
     /* remove old directives if any */
-    httpHeaderDelById(hdr, HDR_RANGE);
+    delById(HDR_RANGE);
     /* pack into mb */
     mb.init();
     packerToMemInit(&p, &mb);
     range->packInto(&p);
     /* put */
-    httpHeaderAddEntry(hdr, httpHeaderEntryCreate(HDR_RANGE, NULL, mb.buf));
+    addEntry(httpHeaderEntryCreate(HDR_RANGE, NULL, mb.buf));
     /* cleanup */
     packerClean(&p);
     mb.clean();
 }
 
 void
-httpHeaderPutSc(HttpHeader *hdr, const HttpHdrSc *sc)
+HttpHeader::putSc(HttpHdrSc *sc)
 {
     MemBuf mb;
     Packer p;
-    assert(hdr && sc);
+    assert(sc);
     /* remove old directives if any */
-    httpHeaderDelById(hdr, HDR_RANGE);
+    delById(HDR_RANGE);
     /* pack into mb */
     mb.init();
     packerToMemInit(&p, &mb);
     httpHdrScPackInto(sc, &p);
     /* put */
-    httpHeaderAddEntry(hdr, httpHeaderEntryCreate(HDR_SURROGATE_CONTROL, NULL, mb.buf));
+    addEntry(httpHeaderEntryCreate(HDR_SURROGATE_CONTROL, NULL, mb.buf));
     /* cleanup */
     packerClean(&p);
     mb.clean();
 }
 
 /* add extension header (these fields are not parsed/analyzed/joined, etc.) */
 void
-httpHeaderPutExt(HttpHeader * hdr, const char *name, const char *value)
+HttpHeader::putExt(const char *name, const char *value)
 {
     assert(name && value);
-    debug(55, 8) ("%p adds ext entry '%s: %s'\n", hdr, name, value);
-    httpHeaderAddEntry(hdr, httpHeaderEntryCreate(HDR_OTHER, name, value));
+    debug(55, 8) ("%p adds ext entry '%s: %s'\n", this, name, value);
+    addEntry(httpHeaderEntryCreate(HDR_OTHER, name, value));
 }
 
 int
