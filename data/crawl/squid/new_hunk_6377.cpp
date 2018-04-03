	String strConnection = httpHeaderGetList(hdr, HDR_CONNECTION);
	const HttpHeaderEntry *e;
	HttpHeaderPos pos = HttpHeaderInitPos;
	/* think: on-average-best nesting of the two loops (hdrEntry and strListItem) @?@ */
	/* maybe we should delete standard stuff ("keep-alive","close") from strConnection first? */
	while ((e = httpHeaderGetEntry(hdr, &pos))) {
	    if (strListIsMember(&strConnection, strBuf(e->name), ','))
		httpHeaderDelAt(hdr, pos);
	}
	httpHeaderDelById(hdr, HDR_CONNECTION);
	stringClean(&strConnection);
    }
    /* Handle Ranges */
    /* move this "if" to a separate function! @?@ @?@ */
    if (http->request->range) {
	const int spec_count = http->request->range->specs.count;
	const char *range_err = NULL;
	debug(33, 1) ("clientBuildReplyHeader: range spec count: %d clen: %d\n",
	    spec_count, rep->content_length);
	/* check if we still want to do ranges */
	if (rep->sline.status != HTTP_OK)
	    range_err = "wrong status code";
	else
	if (httpHeaderHas(hdr, HDR_CONTENT_RANGE))
	    range_err = "origin server does ranges";
	else
	if (rep->content_length < 0)
	    range_err = "unknown length";
	else
	if (rep->content_length != http->entry->mem_obj->reply->content_length)
	    range_err = "INCONSISTENT length"; /* bug? */
	else
	if (!httpHdrRangeCanonize(http->request->range, rep->content_length))
	    range_err = "canonization failed";
	else
	if (httpHdrRangeIsComplex(http->request->range))
	    range_err = "too complex range header";
	/* get rid of our range specs on error */
	if (range_err) {
	    debug(33, 1) ("clientBuildReplyHeader: will not do ranges: %s.\n", range_err);
	    httpHdrRangeDestroy(http->request->range);
	    http->request->range = NULL;
	}
	/* if we still want to do ranges, append appropriate header(s) */ 
	if (http->request->range) {
	    assert(spec_count > 0);
	    if (spec_count == 1) {
		HttpHdrRangePos pos = HttpHdrRangeInitPos;
		HttpHdrRangeSpec spec;
		assert(httpHdrRangeGetSpec(http->request->range, &spec, &pos));
		/* append Content-Range */
		httpHeaderAddContRange(hdr, spec, rep->content_length);
		/* set new Content-Length to the actual number of OCTETs
		 * transmitted in the message-body */
		httpHeaderDelById(hdr, HDR_CONTENT_LENGTH);
		httpHeaderPutInt(hdr, HDR_CONTENT_LENGTH, spec.length);
		debug(33, 1) ("clientBuildReplyHeader: actual content length: %d\n", spec.length);
	    } else {
		/* multipart! */
		/* generate boundary string */
		http->range_iter.boundary = httpHdrRangeBoundaryStr(http);
		/* delete old Content-Type, add ours */
		httpHeaderDelById(hdr, HDR_CONTENT_TYPE);
		httpHeaderPutStrf(hdr, HDR_CONTENT_TYPE,
		    "multipart/byteranges; boundary=\"%s\"",
		    strBuf(http->range_iter.boundary));
		/* no need for Content-Length in multipart responses */
	    }
	}
    }
    /* Append X-Cache */
    httpHeaderPutStrf(hdr, HDR_X_CACHE, "%s from %s",
	is_hit ? "HIT" : "MISS", getMyHostname());
