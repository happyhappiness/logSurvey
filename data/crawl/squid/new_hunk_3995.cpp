                hdr_out->putStr(HDR_AUTHORIZATION, auth);
            } else if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
                char loginbuf[256];
                snprintf(loginbuf, sizeof(loginbuf), "%s:%s", orig_request->extacl_user.unsafeBuf(), orig_request->extacl_passwd.unsafeBuf());
                httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
                                  base64_encode(loginbuf));
            }
