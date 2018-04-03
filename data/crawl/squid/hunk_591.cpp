 HttpHeader::putAuth(const char *auth_scheme, const char *realm)
 {
     assert(auth_scheme && realm);
-    httpHeaderPutStrf(this, HDR_WWW_AUTHENTICATE, "%s realm=\"%s\"", auth_scheme, realm);
+    httpHeaderPutStrf(this, Http::HdrType::WWW_AUTHENTICATE, "%s realm=\"%s\"", auth_scheme, realm);
 }
 
 void
 HttpHeader::putCc(const HttpHdrCc * cc)
 {
     assert(cc);
     /* remove old directives if any */
-    delById(HDR_CACHE_CONTROL);
+    delById(Http::HdrType::CACHE_CONTROL);
     /* pack into mb */
     MemBuf mb;
     mb.init();
     cc->packInto(&mb);
     /* put */
-    addEntry(new HttpHeaderEntry(HDR_CACHE_CONTROL, NULL, mb.buf));
+    addEntry(new HttpHeaderEntry(Http::HdrType::CACHE_CONTROL, NULL, mb.buf));
     /* cleanup */
     mb.clean();
 }
