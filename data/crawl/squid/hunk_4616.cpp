                 hdr_out->putStr(HDR_AUTHORIZATION, auth);
             } else if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
                 char loginbuf[256];
-                snprintf(loginbuf, sizeof(loginbuf), "%s:%s", orig_request->extacl_user.buf(), orig_request->extacl_passwd.buf());
+                snprintf(loginbuf, sizeof(loginbuf), "%s:%s", orig_request->extacl_user.c_str(), orig_request->extacl_passwd.c_str());
                 httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
                                   base64_encode(loginbuf));
             }
