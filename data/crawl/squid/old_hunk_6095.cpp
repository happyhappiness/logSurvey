    }
    /* append Proxy-Authorization if configured for peer, and proxying */
    if (!httpHeaderHas(hdr_out, HDR_PROXY_AUTHORIZATION)) {
	if (request->flags.proxying && request->peer_login) {
	    httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
		base64_encode(request->peer_login));
	}
    }
    /* append Cache-Control, add max-age if not there already */
