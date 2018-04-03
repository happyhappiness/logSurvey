    /* Append X-Cache-Lookup: -- temporary hack, to be removed @?@ @?@ */
    httpHeaderPutStrf(hdr, HDR_X_CACHE_LOOKUP, "%s from %s:%d",
	http->lookup_type ? http->lookup_type : "NONE",
	getMyHostname(), Config.Port.http->i);
#endif
    if (httpReplyBodySize(request->method, rep) < 0) {
	debug(33, 3) ("clientBuildReplyHeader: can't keep-alive, unknown body size\n");
