	if (orig_request->port == urlDefaultPort(orig_request->protocol)) {
	    httpHeaderPutStr(hdr_out, HDR_HOST, orig_request->host);
	} else {
	    snprintf(bbuf, BBUF_SZ, "%s:%d",
		orig_request->host, (int) orig_request->port);
	    httpHeaderPutStr(hdr_out, HDR_HOST, bbuf);
	}
    }
    /* append Cache-Control, add max-age if not there already */
