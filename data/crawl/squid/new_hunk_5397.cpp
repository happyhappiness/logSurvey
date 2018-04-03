	    snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);
	    httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
		base64_encode(loginbuf));
	} else if (strcmp(orig_request->peer_login, "PASS") == 0) {
	    /* Nothing to do */
	} else if (strcmp(orig_request->peer_login, "PROXYPASS") == 0) {
	    /* Nothing to do */
	} else {
	    httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
		base64_encode(orig_request->peer_login));
	}
    }
    /* append WWW-Authorization if configured for peer */
    if (flags.originpeer && orig_request->peer_login &&
	    !httpHeaderHas(hdr_out, HDR_AUTHORIZATION)) {
	if (strcmp(orig_request->peer_login, "PASS") == 0) {
	    /* No credentials to forward.. (should have been done above if available) */
	} else if (strcmp(orig_request->peer_login, "PROXYPASS") == 0) {
	    /* Special mode, convert proxy authentication to WWW authentication
	     */
	    const char *auth = httpHeaderGetStr(hdr_in, HDR_PROXY_AUTHORIZATION);
	    if (auth && strncasecmp(auth, "basic ", 6) == 0) {
		httpHeaderPutStr(hdr_out, HDR_AUTHORIZATION, auth);
	    }
	} else if (*orig_request->peer_login == '*') {
	    /* Special mode, to pass the username to the upstream cache */
	    char loginbuf[256];
	    const char *username = "-";
	    if (orig_request->auth_user_request)
	    username = authenticateUserRequestUsername(orig_request->auth_user_request);
	    snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);
	    httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
		base64_encode(loginbuf));
	} else {
	    /* Fixed login string */
	    httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
		base64_encode(orig_request->peer_login));
	}
    }
    /* append Cache-Control, add max-age if not there already */
    {
	HttpHdrCc *cc = httpHeaderGetCc(hdr_in);
