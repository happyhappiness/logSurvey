	}
    }
    /* append Proxy-Authorization if configured for peer, and proxying */
    if (!httpHeaderHas(hdr_out, HDR_PROXY_AUTHORIZATION)) {
	if (request->flags.proxying && orig_request->peer_login &&
	    strcmp(orig_request->peer_login, "PASS") != 0) {
	    httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
		base64_encode(orig_request->peer_login));
	}