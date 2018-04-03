
    /* append Host if not there already */
    if (!httpHeaderHas(hdr_out, HDR_HOST)) {
	/* use port# only if not default */
	if (orig_request->port == urlDefaultPort(orig_request->protocol)) {
	    httpHeaderPutStr(hdr_out, HDR_HOST, orig_request->host);
	} else {
	    httpHeaderPutStrf(hdr_out, HDR_HOST, "%s:%d",
