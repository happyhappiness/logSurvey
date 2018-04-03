	if (orig_request->port == urlDefaultPort(orig_request->protocol)) {
	    httpHeaderPutStr(hdr_out, HDR_HOST, orig_request->host);
	} else {
	    httpHeaderPutStrf(hdr_out, HDR_HOST, "%s:%d",
		orig_request->host, (int) orig_request->port);
	}
    }
    /* append Cache-Control, add max-age if not there already */
