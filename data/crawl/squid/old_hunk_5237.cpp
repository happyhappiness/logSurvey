
            if (orig_request->auth_user_request)
                username = orig_request->auth_user_request->username();

            snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);

            httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
                              base64_encode(loginbuf));
        } else if (strcmp(orig_request->peer_login, "PASS") == 0) {
            /* Nothing to do */
        } else if (strcmp(orig_request->peer_login, "PROXYPASS") == 0) {
            /* Nothing to do */
        } else {
