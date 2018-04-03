         } else if (strcmp(orig_request->peer_login, "PASS") == 0) {
             if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
                 char loginbuf[256];
-                snprintf(loginbuf, sizeof(loginbuf), "%.*s:%.*s",
-                    orig_request->extacl_user.psize(),
-                    orig_request->extacl_user.rawBuf(),
-                    orig_request->extacl_passwd.psize(),
-                    orig_request->extacl_passwd.rawBuf());
+                snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
+                    SQUIDSTRINGPRINT(orig_request->extacl_user),
+                    SQUIDSTRINGPRINT(orig_request->extacl_passwd));
                 httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
                                   base64_encode(loginbuf));
             }
