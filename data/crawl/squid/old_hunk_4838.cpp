
    /* append WWW-Authorization if configured for peer */
    if (flags.originpeer && orig_request->peer_login &&
            !httpHeaderHas(hdr_out, HDR_AUTHORIZATION)) {
        if (strcmp(orig_request->peer_login, "PASS") == 0) {
            /* No credentials to forward.. (should have been done above if available) */
        } else if (strcmp(orig_request->peer_login, "PROXYPASS") == 0) {
            /* Special mode, convert proxy authentication to WWW authentication
            * (also applies to authentication provided by external acl)
             */
            const char *auth = httpHeaderGetStr(hdr_in, HDR_PROXY_AUTHORIZATION);

            if (auth && strncasecmp(auth, "basic ", 6) == 0) {
                httpHeaderPutStr(hdr_out, HDR_AUTHORIZATION, auth);
            } else if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
                char loginbuf[256];
                snprintf(loginbuf, sizeof(loginbuf), "%s:%s", orig_request->extacl_user.buf(), orig_request->extacl_passwd.buf());
