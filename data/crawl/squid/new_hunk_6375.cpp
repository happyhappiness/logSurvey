}
#endif

/* adds appropriate Range headers if needed */
static void
clientBuildRangeHeader(clientHttpRequest * http, HttpReply * rep)
{
    HttpHeader *hdr = &rep->header;
    const char *range_err = NULL;
    assert(http->request->range);
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
	range_err = "INCONSISTENT length"; /* a bug? */
    else
    if (!httpHdrRangeCanonize(http->request->range, rep->content_length))
	range_err = "canonization failed";
    else
    if (httpHdrRangeIsComplex(http->request->range))
	range_err = "too complex range header";
    /* get rid of our range specs on error */
    if (range_err) {
	debug(33, 1) ("clientBuildRangeHeader: will not do ranges: %s.\n", range_err);
	httpHdrRangeDestroy(http->request->range);
	http->request->range = NULL;
    } else {
	const int spec_count = http->request->range->specs.count;
	debug(33, 1) ("clientBuildRangeHeader: range spec count: %d clen: %d\n",
	    spec_count, rep->content_length);
	assert(spec_count > 0);
	/* append appropriate header(s) */ 
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
	    debug(33, 1) ("clientBuildRangeHeader: actual content length: %d\n", spec.length);
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

/* filters out unwanted entries from original reply header
 * adds extra entries if we have more info than origin server
 * adds Squid specific entries */
