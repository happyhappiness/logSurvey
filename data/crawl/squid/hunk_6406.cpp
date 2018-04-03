     memFree(MEM_4K_BUF, ybuf);
     return len;
 }
+#endif
+
+static void
+clientBuildReplyHeader(clientHttpRequest * http, HttpReply *rep)
+{
+    HttpHeader *hdr = &rep->header;
+    int is_hit = isTcpHit(http->log_type);
+#if DONT_FILTER_THESE
+    /* but you might want to if you run Squid as an HTTP accelerator */
+    httpHeaderDelById(hdr, HDR_ACCEPT_RANGES);
+    httpHeaderDelById(hdr, HDR_ETAG);
+#endif
+    httpHeaderDelById(hdr, HDR_PROXY_CONNECTION);
+    /* here: Keep-Alive is a field-name, not a connection directive! */
+    httpHeaderDelByName(hdr, "Keep-Alive");
+    /* remove Set-Cookie if a hit */
+    if (is_hit)
+	httpHeaderDelById(hdr, HDR_SET_COOKIE);
+    /* handle Connection header */
+    if (httpHeaderHas(hdr, HDR_CONNECTION)) {
+	/* anything that matches Connection list member will be deleted */
+	String strConnection = httpHeaderGetList(hdr, HDR_CONNECTION);
+	const HttpHeaderEntry *e;
+	HttpHeaderPos pos = HttpHeaderInitPos;
+	while ((e = httpHeaderGetEntry(hdr, &pos))) {
+	    if (strListIsMember(&strConnection, strBuf(e->name), ','))
+		httpHeaderDelAt(hdr, pos);
+	}
+	httpHeaderDelById(hdr, HDR_CONNECTION);
+	stringClean(&strConnection);
+    }
+    /* Append X-Cache */
+    httpHeaderPutStrf(hdr, HDR_X_CACHE, "%s from %s",
+	is_hit ? "HIT" : "MISS", getMyHostname());
+#if USE_CACHE_DIGESTS
+    /* Append X-Cache-Lookup: -- temporary hack, to be removed @?@ @?@ */
+    httpHeaderPutStrf(hdr, HDR_X_CACHE_LOOKUP, "%s from %s:%d",
+	http->lookup_type ? http->lookup_type : "NONE",
+	getMyHostname(), Config.Port.http->i);
+#endif
+    /* Only replies with valid Content-Length can be sent with keep-alive */
+    if (http->request->method != METHOD_HEAD &&
+	http->entry->mem_obj->reply->content_length < 0)
+	EBIT_CLR(http->request->flags, REQ_PROXY_KEEPALIVE);
+    /* Signal keep-alive if needed */
+    if (EBIT_TEST(http->request->flags, REQ_PROXY_KEEPALIVE))
+	httpHeaderPutStr(hdr, 
+	    http->flags.accel ? HDR_CONNECTION : HDR_PROXY_CONNECTION,
+	    "keep-alive");
+#if ADD_X_REQUEST_URI
+    /*
+     * Knowing the URI of the request is useful when debugging persistent
+     * connections in a client; we cannot guarantee the order of http headers,
+     * but X-Request-URI is likely to be the very last header to ease use from a
+     * debugger [hdr->entries.count-1].
+     */
+     httpHeaderPutStr(hdr, HDR_X_REQUEST_URI,
+	http->entry->mem_obj->url ? http->entry->mem_obj->url : http->uri);
+#endif
+}
+
+static HttpReply*
+clientBuildReply(clientHttpRequest * http, const char *buf, size_t size)
+{
+    HttpReply *rep = httpReplyCreate();
+    assert(size <= 4096); /* httpReplyParse depends on this */
+    if (httpReplyParse(rep, buf)) {
+	/* enforce 1.0 reply version */
+	rep->sline.version = 1.0;
+	/* do header conversions */
+	clientBuildReplyHeader(http, rep);
+    } else {
+	/* parsing failure, get rid of the invalid reply */
+	httpReplyDestroy(rep);
+	rep = NULL;
+    }
+    return rep;
+}
 
 static void
 clientCacheHit(void *data, char *buf, ssize_t size)
