        } else if (strcmp(orig_request->peer_login, "PASS") == 0) {
            if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
                char loginbuf[256];
                snprintf(loginbuf, sizeof(loginbuf), "%s:%s", orig_request->extacl_user.c_str(), orig_request->extacl_passwd.c_str());
                httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
                                  base64_encode(loginbuf));
            }
