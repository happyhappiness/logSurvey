     cbdataFree(err);
 }
 
-/// \ingroup ErrorPageInternal
-static int
-errorDump(ErrorState * err, MemBuf * mb)
+int
+ErrorState::Dump(MemBuf * mb)
 {
-    HttpRequest *r = err->request;
     MemBuf str;
     const char *p = NULL;	/* takes priority over mb if set */
     char ntoabuf[MAX_IPSTRLEN];
 
     str.reset();
     /* email subject line */
-    str.Printf("CacheErrorInfo - %s", errorPageName(err->type));
+    str.Printf("CacheErrorInfo - %s", errorPageName(type));
     mb->Printf("?subject=%s", rfc1738_escape_part(str.buf));
     str.reset();
     /* email body */
     str.Printf("CacheHost: %s\r\n", getMyHostname());
     /* - Err Msgs */
-    str.Printf("ErrPage: %s\r\n", errorPageName(err->type));
+    str.Printf("ErrPage: %s\r\n", errorPageName(type));
 
-    if (err->xerrno) {
-        str.Printf("Err: (%d) %s\r\n", err->xerrno, strerror(err->xerrno));
+    if (xerrno) {
+        str.Printf("Err: (%d) %s\r\n", xerrno, strerror(xerrno));
     } else {
         str.Printf("Err: [none]\r\n");
     }
 
-    if (err->auth_user_request->denyMessage())
-        str.Printf("Auth ErrMsg: %s\r\n", err->auth_user_request->denyMessage());
+    if (auth_user_request->denyMessage())
+        str.Printf("Auth ErrMsg: %s\r\n", auth_user_request->denyMessage());
 
-    if (err->dnsserver_msg) {
-        str.Printf("DNS Server ErrMsg: %s\r\n", err->dnsserver_msg);
+    if (dnsserver_msg) {
+        str.Printf("DNS Server ErrMsg: %s\r\n", dnsserver_msg);
     }
 
     /* - TimeStamp */
     str.Printf("TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));
 
     /* - IP stuff */
-    str.Printf("ClientIP: %s\r\n", err->src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));
+    str.Printf("ClientIP: %s\r\n", src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));
 
-    if (r && r->hier.host) {
-        str.Printf("ServerIP: %s\r\n", r->hier.host);
+    if (request && request->hier.host) {
+        str.Printf("ServerIP: %s\r\n", request->hier.host);
     }
 
     str.Printf("\r\n");
     /* - HTTP stuff */
     str.Printf("HTTP Request:\r\n");
 
-    if (NULL != r) {
+    if (NULL != request) {
         Packer p;
         str.Printf("%s %s HTTP/%d.%d\n",
-                   RequestMethodStr(r->method),
-                   r->urlpath.size() ? r->urlpath.buf() : "/",
-                   r->http_ver.major, r->http_ver.minor);
+                   RequestMethodStr(request->method),
+                   request->urlpath.size() ? request->urlpath.buf() : "/",
+                   request->http_ver.major, request->http_ver.minor);
         packerToMemInit(&p, &str);
-        r->header.packInto(&p);
+        request->header.packInto(&p);
         packerClean(&p);
-    } else if (err->request_hdrs) {
-        p = err->request_hdrs;
+    } else if (request_hdrs) {
+        p = request_hdrs;
     } else {
         p = "[none]";
     }
 
     str.Printf("\r\n");
     /* - FTP stuff */
 
-    if (err->ftp.request) {
-        str.Printf("FTP Request: %s\r\n", err->ftp.request);
-        str.Printf("FTP Reply: %s\r\n", err->ftp.reply);
+    if (ftp.request) {
+        str.Printf("FTP Request: %s\r\n", ftp.request);
+        str.Printf("FTP Reply: %s\r\n", ftp.reply);
         str.Printf("FTP Msg: ");
-        wordlistCat(err->ftp.server_msg, &str);
+        wordlistCat(ftp.server_msg, &str);
         str.Printf("\r\n");
     }
 
