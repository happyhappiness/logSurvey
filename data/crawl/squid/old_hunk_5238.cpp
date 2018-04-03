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
