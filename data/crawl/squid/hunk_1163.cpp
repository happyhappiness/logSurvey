  *          a ClientSocketContext structure on success or failure.
  */
 ClientSocketContext *
-parseHttpRequest(ConnStateData *csd, HttpParser *hp, HttpRequestMethod * method_p, Http::ProtocolVersion *http_ver)
+parseHttpRequest(ConnStateData *csd, const Http1::RequestParserPointer &hp)
 {
-    char *req_hdr = NULL;
-    char *end;
-    size_t req_sz;
-    ClientHttpRequest *http;
-    ClientSocketContext *result;
-    StoreIOBuffer tempBuffer;
-    int r;
-
-    /* pre-set these values to make aborting simpler */
-    *method_p = Http::METHOD_NONE;
-
-    /* NP: don't be tempted to move this down or remove again.
-     * It's the only DDoS protection old-String has against long URL */
-    if ( hp->bufsiz <= 0) {
-        debugs(33, 5, "Incomplete request, waiting for end of request line");
-        return NULL;
-    } else if ( (size_t)hp->bufsiz >= Config.maxRequestHeaderSize && headersEnd(hp->buf, Config.maxRequestHeaderSize) == 0) {
-        debugs(33, 5, "parseHttpRequest: Too large request");
-        hp->request_parse_status = Http::scHeaderTooLarge;
-        return csd->abortRequestParsing("error:request-too-large");
-    }
-
-    /* Attempt to parse the first line; this'll define the method, url, version and header begin */
-    r = HttpParserParseReqLine(hp);
-
-    if (r == 0) {
-        debugs(33, 5, "Incomplete request, waiting for end of request line");
-        return NULL;
-    }
-
-    if (r == -1) {
-        return csd->abortRequestParsing("error:invalid-request");
-    }
+    /* Attempt to parse the first line; this will define where the method, url, version and header begin */
+    {
+        const bool parsedOk = hp->parse(csd->in.buf);
 
-    /* Request line is valid here .. */
-    *http_ver = Http::ProtocolVersion(hp->req.v_maj, hp->req.v_min);
+        // sync the buffers after parsing.
+        csd->in.buf = hp->remaining();
 
-    /* This call scans the entire request, not just the headers */
-    if (hp->req.v_maj > 0) {
-        if ((req_sz = headersEnd(hp->buf, hp->bufsiz)) == 0) {
-            debugs(33, 5, "Incomplete request, waiting for end of headers");
+        if (hp->needsMoreData()) {
+            debugs(33, 5, "Incomplete request, waiting for end of request line");
             return NULL;
         }
-    } else {
-        debugs(33, 3, "parseHttpRequest: Missing HTTP identifier");
-        req_sz = HttpParserReqSz(hp);
-    }
-
-    /* We know the whole request is in hp->buf now */
-
-    assert(req_sz <= (size_t) hp->bufsiz);
 
-    /* Will the following be true with HTTP/0.9 requests? probably not .. */
-    /* So the rest of the code will need to deal with '0'-byte headers (ie, none, so don't try parsing em) */
-    assert(req_sz > 0);
+        if (!parsedOk) {
+            if (hp->request_parse_status == Http::scRequestHeaderFieldsTooLarge || hp->request_parse_status == Http::scUriTooLong)
+                return csd->abortRequestParsing("error:request-too-large");
 
-    hp->hdr_end = req_sz - 1;
-
-    hp->hdr_start = hp->req.end + 1;
-
-    /* Enforce max_request_size */
-    if (req_sz >= Config.maxRequestHeaderSize) {
-        debugs(33, 5, "parseHttpRequest: Too large request");
-        hp->request_parse_status = Http::scHeaderTooLarge;
-        return csd->abortRequestParsing("error:request-too-large");
+            return csd->abortRequestParsing("error:invalid-request");
+        }
     }
 
-    /* Set method_p */
-    *method_p = HttpRequestMethod(&hp->buf[hp->req.m_start], &hp->buf[hp->req.m_end]+1);
+    /* We know the whole request is in parser now */
+    debugs(11, 2, "HTTP Client " << csd->clientConnection);
+    debugs(11, 2, "HTTP Client REQUEST:\n---------\n" <<
+           hp->method() << " " << hp->requestUri() << " " << hp->messageProtocol() << "\n" <<
+           hp->mimeHeader() <<
+           "\n----------");
 
     /* deny CONNECT via accelerated ports */
-    if (*method_p == Http::METHOD_CONNECT && csd->port != NULL && csd->port->flags.accelSurrogate) {
+    if (hp->method() == Http::METHOD_CONNECT && csd->port != NULL && csd->port->flags.accelSurrogate) {
         debugs(33, DBG_IMPORTANT, "WARNING: CONNECT method received on " << csd->transferProtocol << " Accelerator port " << csd->port->s.port());
-        /* XXX need a way to say "this many character length string" */
-        debugs(33, DBG_IMPORTANT, "WARNING: for request: " << hp->buf);
+        debugs(33, DBG_IMPORTANT, "WARNING: for request: " << hp->method() << " " << hp->requestUri() << " " << hp->messageProtocol());
         hp->request_parse_status = Http::scMethodNotAllowed;
         return csd->abortRequestParsing("error:method-not-allowed");
     }
 
-    if (*method_p == Http::METHOD_NONE) {
-        /* XXX need a way to say "this many character length string" */
-        debugs(33, DBG_IMPORTANT, "clientParseRequestMethod: Unsupported method in request '" << hp->buf << "'");
+    if (hp->method() == Http::METHOD_NONE) {
+        debugs(33, DBG_IMPORTANT, "WARNING: Unsupported method: " << hp->method() << " " << hp->requestUri() << " " << hp->messageProtocol());
         hp->request_parse_status = Http::scMethodNotAllowed;
         return csd->abortRequestParsing("error:unsupported-request-method");
     }
 
-    /*
-     * Process headers after request line
-     * TODO: Use httpRequestParse here.
-     */
-    /* XXX this code should be modified to take a const char * later! */
-    req_hdr = (char *) hp->buf + hp->req.end + 1;
-
-    debugs(33, 3, "parseHttpRequest: req_hdr = {" << req_hdr << "}");
-
-    end = (char *) hp->buf + hp->hdr_end;
-
-    debugs(33, 3, "parseHttpRequest: end = {" << end << "}");
-
-    debugs(33, 3, "parseHttpRequest: prefix_sz = " <<
-           (int) HttpParserRequestLen(hp) << ", req_line_sz = " <<
-           HttpParserReqSz(hp));
+    // Process headers after request line
+    debugs(33, 3, "complete request received. " <<
+           "prefix_sz = " << hp->messageHeaderSize() <<
+           ", request-line-size=" << hp->firstLineSize() <<
+           ", mime-header-size=" << hp->headerBlockSize() <<
+           ", mime header block:\n" << hp->mimeHeader() << "\n----------");
 
     /* Ok, all headers are received */
-    http = new ClientHttpRequest(csd);
+    ClientHttpRequest *http = new ClientHttpRequest(csd);
 
-    http->req_sz = HttpParserRequestLen(hp);
-    result = new ClientSocketContext(csd->clientConnection, http);
+    http->req_sz = hp->messageHeaderSize();
+    ClientSocketContext *result = new ClientSocketContext(csd->clientConnection, http);
+
+    StoreIOBuffer tempBuffer;
     tempBuffer.data = result->reqbuf;
     tempBuffer.length = HTTP_REQBUF_SZ;
 
