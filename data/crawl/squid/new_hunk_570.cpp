    // CONNECT response was successfully parsed
    *status_ptr = rep.sline.status();

    // we need to relay the 401/407 responses when login=PASS(THRU)
    const char *pwd = server.conn->getPeer()->login;
    const bool relay = pwd && (strcmp(pwd, "PASS") != 0 || strcmp(pwd, "PASSTHRU") != 0) &&
                       (*status_ptr == Http::scProxyAuthenticationRequired ||
                        *status_ptr == Http::scUnauthorized);

    // bail if we did not get an HTTP 200 (Connection Established) response
    if (rep.sline.status() != Http::scOkay) {
        // if we ever decide to reuse the peer connection, we must extract the error response first
        informUserOfPeerError("unsupported CONNECT response status code", (relay ? rep.hdr_sz : 0));
        return;
    }
