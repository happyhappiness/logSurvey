     return 1;
 }
 
-clientSocketContext *
+ClientSocketContext *
 connGetCurrentContext(ConnStateData * conn)
 {
     assert(conn);
-    return (clientSocketContext *)conn->currentobject;
+    return (ClientSocketContext *)conn->currentobject;
 }
 
 void
-contextDeferRecipientForLater(clientSocketContext * context, clientStreamNode * node, HttpReply * rep, StoreIOBuffer recievedData)
-{
-    debug(33, 2) ("clientSocketRecipient: Deferring %s\n", context->http->uri);
-    assert(context->flags.deferred == 0);
-    context->flags.deferred = 1;
-    context->deferredparams.node = node;
-    context->deferredparams.rep = rep;
-    context->deferredparams.queuedBuffer = recievedData;
+ClientSocketContext::deferRecipientForLater(clientStreamNode * node, HttpReply * rep, StoreIOBuffer recievedData)
+{
+    debug(33, 2) ("clientSocketRecipient: Deferring %s\n", http->uri);
+    assert(flags.deferred == 0);
+    flags.deferred = 1;
+    deferredparams.node = node;
+    deferredparams.rep = rep;
+    deferredparams.queuedBuffer = recievedData;
     return;
 }
 
 int
-responseFinishedOrFailed(HttpReply * rep, StoreIOBuffer recievedData)
+responseFinishedOrFailed(HttpReply * rep, StoreIOBuffer const & recievedData)
 {
     if (rep == NULL && recievedData.data == NULL && recievedData.length == 0)
 	return 1;
     return 0;
 }
 
 int
-contextStartOfOutput(clientSocketContext * context)
+contextStartOfOutput(ClientSocketContext * context)
 {
     return context->http->out.size == 0 ? 1 : 0;
 }
 
+size_t
+ClientSocketContext::lengthToSend(size_t maximum)
+{
+    if (!http->request->range)
+	return maximum;
+    assert (canPackMoreRanges());
+    if (http->range_iter.debt() == -1)
+	return maximum;
+    assert (http->range_iter.debt() > 0);
+    return XMIN(http->range_iter.debt(), (ssize_t)maximum);
+}
+
 void
-contextSendBody(clientSocketContext * context, HttpReply * rep, StoreIOBuffer bodyData)
+ClientSocketContext::noteSentBodyBytes(size_t bytes)
+{
+    http->out.offset += bytes;
+    if (!http->request->range)
+	return;
+    if (http->range_iter.debt() != -1) {
+	http->range_iter.debt(http->range_iter.debt() - bytes);
+	assert (http->range_iter.debt() >= 0);
+    }
+    assert (http->range_iter.debt() == -1 ||
+	    http->range_iter.debt() >= 0);
+}
+ 
+bool
+ClientHttpRequest::multipartRangeRequest() const
+{
+    return request->multipartRangeRequest();
+}
+
+bool
+ClientSocketContext::multipartRangeRequest() const
+{
+    return http->multipartRangeRequest();
+}
+
+void
+ClientSocketContext::sendBody(HttpReply * rep, StoreIOBuffer bodyData)
 {
     assert(rep == NULL);
-    context->http->out.offset += bodyData.length;
-    comm_write(context->http->conn->fd, bodyData.data, bodyData.length,
-	clientWriteBodyComplete, context);
+
+    if (!multipartRangeRequest()) {
+	size_t length = lengthToSend(bodyData.length);
+	noteSentBodyBytes (length);
+	comm_write(fd(), bodyData.data, length,
+		   clientWriteBodyComplete, this);
+	return;
+    }
+
+    MemBuf mb;
+    memBufDefInit(&mb);
+    char const *t = bodyData.data;
+    packRange(&t, bodyData.length, &mb);
+    /* write */
+    comm_old_write_mbuf(fd(), mb, clientWriteComplete, this);
     return;
 }
 
+/* put terminating boundary for multiparts */
+static void
+clientPackTermBound(String boundary, MemBuf * mb)
+{
+    memBufPrintf(mb, "\r\n--%s--\r\n", boundary.buf());
+    debug(33, 6) ("clientPackTermBound: buf offset: %ld\n", (long int) mb->size);
+}
+
+/* appends a "part" HTTP header (as in a multi-part/range reply) to the buffer */
+static void
+clientPackRangeHdr(const HttpReply * rep, const HttpHdrRangeSpec * spec, String boundary, MemBuf * mb)
+{
+    HttpHeader hdr;
+    Packer p;
+    assert(rep);
+    assert(spec);
+
+    /* put boundary */
+    debug(33, 5) ("clientPackRangeHdr: appending boundary: %s\n", boundary.buf());
+    /* rfc2046 requires to _prepend_ boundary with <crlf>! */
+    memBufPrintf(mb, "\r\n--%s\r\n", boundary.buf());
+
+    /* stuff the header with required entries and pack it */
+    httpHeaderInit(&hdr, hoReply);
+    if (httpHeaderHas(&rep->header, HDR_CONTENT_TYPE))
+	httpHeaderPutStr(&hdr, HDR_CONTENT_TYPE, httpHeaderGetStr(&rep->header, HDR_CONTENT_TYPE));
+    httpHeaderAddContRange(&hdr, *spec, rep->content_length);
+    packerToMemInit(&p, mb);
+    httpHeaderPackInto(&hdr, &p);
+    packerClean(&p);
+    httpHeaderClean(&hdr);
+
+    /* append <crlf> (we packed a header, not a reply) */
+    memBufPrintf(mb, "\r\n");
+}
+
+/*
+ * extracts a "range" from *buf and appends them to mb, updating
+ * all offsets and such.
+ */
 void
-contextSendStartOfMessage(clientSocketContext * context, HttpReply * rep, StoreIOBuffer bodyData)
+ClientSocketContext::packRange(const char **buf,
+    size_t size,
+    MemBuf * mb)
+{
+    HttpHdrRangeIter * i = &http->range_iter;
+    size_t available = size;
+    while (i->currentSpec() && available) {
+	const size_t copy_sz = lengthToSend(available);
+	/*
+	 * intersection of "have" and "need" ranges must not be empty
+	 */
+	assert(http->out.offset < i->currentSpec()->offset + i->currentSpec()->length);
+	assert(http->out.offset + available > (size_t)i->currentSpec()->offset);
+
+	/*
+	 * put boundary and headers at the beginning of a range in a
+	 * multi-range
+	 */
+	if (http->multipartRangeRequest() && i->debt() == i->currentSpec()->length) {
+	    assert(http->entry->mem_obj);
+	    clientPackRangeHdr(
+		http->entry->mem_obj->getReply(),	/* original reply */
+		i->currentSpec(),		/* current range */
+		i->boundary,	/* boundary, the same for all */
+		mb);
+	}
+	/*
+	 * append content
+	 */
+	debug(33, 3) ("clientPackRange: appending %ld bytes\n", (long int) copy_sz);
+	noteSentBodyBytes (copy_sz);
+	memBufAppend(mb, *buf, copy_sz);
+	/*
+	 * update offsets
+	 */
+	available -= copy_sz;
+	//body_off += copy_sz;
+	*buf += copy_sz;
+	/*
+	 * paranoid check
+	 */
+	assert(available >= 0 && i->debt() >= 0 || i->debt() == -1);
+	if (i->debt() == 0)
+	    /* put terminating boundary for multiparts */
+	    clientPackTermBound(i->boundary, mb);
+	if (!canPackMoreRanges())
+	    return;
+	off_t next = getNextRangeOffset();
+	assert (next >= http->out.offset);
+	size_t skip = next - http->out.offset;
+	if (available <= skip)
+	    return;
+	available -= skip;
+	*buf += skip;
+    }
+}
+
+/* returns expected content length for multi-range replies
+ * note: assumes that httpHdrRangeCanonize has already been called
+ * warning: assumes that HTTP headers for individual ranges at the
+ *          time of the actuall assembly will be exactly the same as
+ *          the headers when clientMRangeCLen() is called */
+int
+ClientHttpRequest::mRangeCLen()
 {
+    int clen = 0;
     MemBuf mb;
-    /* write headers and/or body if any */
-    assert(rep || (bodyData.data && bodyData.length));
-    /* init mb; put status line and headers if any */
-    if (rep) {
-	mb = httpReplyPack(rep);
-	/* Save length of headers for persistent conn checks */
-	context->http->out.headers_sz = mb.size;
-#if HEADERS_LOG
-	headersLog(0, 0, context->http->request->method, rep);
+
+    assert(entry->mem_obj);
+
+    memBufDefInit(&mb);
+    HttpHdrRange::iterator pos = request->range->begin();
+    while (pos != request->range->end()) {
+	/* account for headers for this range */
+	memBufReset(&mb);
+	clientPackRangeHdr(entry->mem_obj->getReply(),
+	    *pos, range_iter.boundary, &mb);
+	clen += mb.size;
+
+	/* account for range content */
+	clen += (*pos)->length;
+
+	debug(33, 6) ("clientMRangeCLen: (clen += %ld + %ld) == %d\n",
+	    (long int) mb.size, (long int) (*pos)->length, clen);
+	++pos;
+    }
+    /* account for the terminating boundary */
+    memBufReset(&mb);
+    clientPackTermBound(range_iter.boundary, &mb);
+    clen += mb.size;
+
+    memBufClean(&mb);
+    return clen;
+}
+
+/*
+ * returns true if If-Range specs match reply, false otherwise
+ */
+static int
+clientIfRangeMatch(clientHttpRequest * http, HttpReply * rep)
+{
+    const TimeOrTag spec = httpHeaderGetTimeOrTag(&http->request->header, HDR_IF_RANGE);
+    /* check for parsing falure */
+    if (!spec.valid)
+	return 0;
+    /* got an ETag? */
+    if (spec.tag.str) {
+	ETag rep_tag = httpHeaderGetETag(&rep->header, HDR_ETAG);
+	debug(33, 3) ("clientIfRangeMatch: ETags: %s and %s\n",
+	    spec.tag.str, rep_tag.str ? rep_tag.str : "<none>");
+	if (!rep_tag.str)
+	    return 0;		/* entity has no etag to compare with! */
+	if (spec.tag.weak || rep_tag.weak) {
+	    debug(33, 1) ("clientIfRangeMatch: Weak ETags are not allowed in If-Range: %s ? %s\n",
+		spec.tag.str, rep_tag.str);
+	    return 0;		/* must use strong validator for sub-range requests */
+	}
+	return etagIsEqual(&rep_tag, &spec.tag);
+    }
+    /* got modification time? */
+    if (spec.time >= 0) {
+	return http->entry->lastmod <= spec.time;
+    }
+    assert(0);			/* should not happen */
+    return 0;
+}
+
+/* generates a "unique" boundary string for multipart responses
+ * the caller is responsible for cleaning the string */
+String
+ClientHttpRequest::rangeBoundaryStr() const
+{
+    assert(this);
+    const char *key;
+    String b (full_appname_string);
+    b.append (":",1);
+    key = entry->getMD5Text();
+    b.append(key, strlen(key));
+    return b;
+}
+
+/* adds appropriate Range headers if needed */
+void
+ClientSocketContext::buildRangeHeader(HttpReply * rep)
+{
+    HttpHeader *hdr = rep ? &rep->header : 0;
+    const char *range_err = NULL;
+    request_t *request = http->request;
+    assert(request->range);
+    /* check if we still want to do ranges */
+    if (!rep)
+	range_err = "no [parse-able] reply";
+    else if ((rep->sline.status != HTTP_OK) && (rep->sline.status != HTTP_PARTIAL_CONTENT))
+	range_err = "wrong status code";
+#if 0
+    else if (httpHeaderHas(hdr, HDR_CONTENT_RANGE))
+	range_err = "origin server does ranges";
+#endif
+    else if (rep->content_length < 0)
+	range_err = "unknown length";
+    else if (rep->content_length != http->entry->mem_obj->getReply()->content_length)
+	range_err = "INCONSISTENT length";	/* a bug? */
+    else if (httpHeaderHas(&http->request->header, HDR_IF_RANGE) && !clientIfRangeMatch(http, rep))
+	range_err = "If-Range match failed";
+    else if (!http->request->range->canonize(rep))
+	range_err = "canonization failed";
+    else if (http->request->range->isComplex())
+	range_err = "too complex range header";
+    else if (!request->flags.cachable)	/* from we_do_ranges in http.c */
+	range_err = "non-cachable request";
+#if 0
+    else if (!logTypeIsATcpHit(http->logType); && http->request->range->offsetLimitExceeded())
+	range_err = "range outside range_offset_limit";
 #endif
-	httpReplyDestroy(rep);
-	rep = NULL;
+    /* get rid of our range specs on error */
+    if (range_err) {
+	/* XXX Why do we do this here, and not when parsing the request ? */
+	debug(33, 3) ("clientBuildRangeHeader: will not do ranges: %s.\n", range_err);
+	http->request->range->deleteSelf();
+	http->request->range = NULL;
     } else {
-	memBufDefInit(&mb);
+	const int spec_count = http->request->range->specs.count;
+	int actual_clen = -1;
+
+	debug(33, 3) ("clientBuildRangeHeader: range spec count: %d virgin clen: %d\n",
+	    spec_count, rep->content_length);
+	assert(spec_count > 0);
+	/* ETags should not be returned with Partial Content replies? */
+	httpHeaderDelById(hdr, HDR_ETAG);
+	/* append appropriate header(s) */
+	if (spec_count == 1) {
+	    HttpHdrRange::iterator pos = http->request->range->begin();
+	    assert(*pos);
+	    /* append Content-Range */
+	    if (!httpHeaderHas(hdr, HDR_CONTENT_RANGE)) {
+		/* No content range, so this was a full object we are 
+		 * sending parts of.
+		 */
+		httpHeaderAddContRange(hdr, **pos, rep->content_length);
+	    }
+	    /* set new Content-Length to the actual number of bytes
+	     * transmitted in the message-body */
+	    actual_clen = (*pos)->length;
+	} else {
+	    /* multipart! */
+	    /* generate boundary string */
+	    http->range_iter.boundary = http->rangeBoundaryStr();
+	    /* delete old Content-Type, add ours */
+	    httpHeaderDelById(hdr, HDR_CONTENT_TYPE);
+	    httpHeaderPutStrf(hdr, HDR_CONTENT_TYPE,
+		"multipart/byteranges; boundary=\"%s\"",
+		http->range_iter.boundary.buf());
+	    /* Content-Length is not required in multipart responses
+	     * but it is always nice to have one */
+	    actual_clen = http->mRangeCLen();
+	}
+
+	/* replace Content-Length header */
+	assert(actual_clen >= 0);
+	httpHeaderDelById(hdr, HDR_CONTENT_LENGTH);
+	httpHeaderPutInt(hdr, HDR_CONTENT_LENGTH, actual_clen);
+	debug(33, 3) ("clientBuildRangeHeader: actual content length: %d\n", actual_clen);
+	/* And start the range iter off */
+	http->range_iter.updateSpec();
     }
+}
+
+void
+ClientSocketContext::prepareReply(HttpReply * rep)
+{
+    if (http->request->range)
+	buildRangeHeader(rep);
+}
+
+void
+ClientSocketContext::sendStartOfMessage(HttpReply * rep, StoreIOBuffer bodyData)
+{
+    prepareReply(rep);
+    /* init mb; put status line and headers if any */
+    assert (rep);
+    MemBuf mb = httpReplyPack(rep);
+    /* Save length of headers for persistent conn checks */
+    http->out.headers_sz = mb.size;
+#if HEADERS_LOG
+    headersLog(0, 0, http->request->method, rep);
+#endif
+    httpReplyDestroy(rep);
+    rep = NULL;
     if (bodyData.data && bodyData.length) {
-	context->http->out.offset += bodyData.length;
-	memBufAppend(&mb, bodyData.data, bodyData.length);
+	if (!multipartRangeRequest()) {
+	    size_t length = lengthToSend(bodyData.length);
+	    noteSentBodyBytes (length);
+	    
+	    memBufAppend(&mb, bodyData.data, length);
+	} else {
+	    char const *t = bodyData.data;
+	    packRange(&t,
+			    bodyData.length,
+			    &mb);
+	}
     }
     /* write */
-    comm_old_write_mbuf(context->http->conn->fd, mb, clientWriteComplete, context);
+    comm_old_write_mbuf(fd(), mb, clientWriteComplete, this);
     /* if we don't do it, who will? */
 }
 
