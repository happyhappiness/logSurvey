            } else if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
                char loginbuf[256];
                snprintf(loginbuf, sizeof(loginbuf), "%.*s:%.*s",
                    orig_request->extacl_user.psize(),
                    orig_request->extacl_user.rawBuf(),
                    orig_request->extacl_passwd.psize(),
                    orig_request->extacl_passwd.rawBuf());
                httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
                                  base64_encode(loginbuf));
