
            if (orig_request->auth_user_request)
                username = orig_request->auth_user_request->username();
            else if (orig_request->extacl_user.size())
                username = orig_request->extacl_user.buf();

            snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);

            httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
                              base64_encode(loginbuf));
        } else if (strcmp(orig_request->peer_login, "PASS") == 0) {
            if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
                char loginbuf[256];
                snprintf(loginbuf, sizeof(loginbuf), "%s:%s", orig_request->extacl_user.buf(), orig_request->extacl_passwd.buf());
                httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
                                  base64_encode(loginbuf));
            }
        } else if (strcmp(orig_request->peer_login, "PROXYPASS") == 0) {
            /* Nothing to do */
        } else {
