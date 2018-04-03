 void
 httpHeaderPutAuth(HttpHeader * hdr, const char *authScheme, const char *realm)
 {
-    MemBuf mb;
     assert(hdr && authScheme && realm);
-    memBufDefInit(&mb);
-    memBufPrintf(&mb, "%s realm=\"%s\"", authScheme, realm);
-    httpHeaderPutStr(hdr, HDR_WWW_AUTHENTICATE, mb.buf);
-    memBufClean(&mb);
+    httpHeaderPutStrf(hdr, HDR_WWW_AUTHENTICATE, "%s realm=\"%s\"", authScheme, realm);
 }
 
 void
