         }
     }
 
-    /* append Proxy-Authorization if configured for peer, and proxying */
-    if (request->flags.proxying && orig_request->peer_login &&
-            !hdr_out->has(HDR_PROXY_AUTHORIZATION)) {
-        if (*orig_request->peer_login == '*') {
-            /* Special mode, to pass the username to the upstream cache */
-            char loginbuf[256];
-            const char *username = "-";
-
-            if (orig_request->extacl_user.size())
-                username = orig_request->extacl_user.termedBuf();
-            else if (orig_request->auth_user_request)
-                username = orig_request->auth_user_request->username();
-
-            snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);
-
-            httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
-                              base64_encode(loginbuf));
-        } else if (strcmp(orig_request->peer_login, "PASS") == 0) {
-            if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
-                char loginbuf[256];
-                snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
-                         SQUIDSTRINGPRINT(orig_request->extacl_user),
-                         SQUIDSTRINGPRINT(orig_request->extacl_passwd));
-                httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
-                                  base64_encode(loginbuf));
-            }
-        } else if (strcmp(orig_request->peer_login, "PROXYPASS") == 0) {
-            /* Nothing to do */
-        } else if (strcmp(orig_request->peer_login, "PASSTHRU") == 0) {
-            /* Nothing to do (yet) */
-        } else {
-            httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
-                              base64_encode(orig_request->peer_login));
-        }
-    }
-
-    /* append WWW-Authorization if configured for peer */
-    if (flags.originpeer && orig_request->peer_login &&
-            !hdr_out->has(HDR_AUTHORIZATION)) {
-        if (strcmp(orig_request->peer_login, "PASS") == 0) {
-            /* No credentials to forward.. (should have been done above if available) */
-        } else if (strcmp(orig_request->peer_login, "PASSTHRU") == 0) {
-            /* Nothing to do (yet) */
-        } else if (strcmp(orig_request->peer_login, "PROXYPASS") == 0) {
-            /* Special mode, convert proxy authentication to WWW authentication
-            * (also applies to authentication provided by external acl)
-             */
-            const char *auth = hdr_in->getStr(HDR_PROXY_AUTHORIZATION);
-
-            if (auth && strncasecmp(auth, "basic ", 6) == 0) {
-                hdr_out->putStr(HDR_AUTHORIZATION, auth);
-            } else if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size()) {
-                char loginbuf[256];
-                snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
-                         SQUIDSTRINGPRINT(orig_request->extacl_user),
-                         SQUIDSTRINGPRINT(orig_request->extacl_passwd));
-                httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
-                                  base64_encode(loginbuf));
-            }
-        } else if (*orig_request->peer_login == '*') {
-            /* Special mode, to pass the username to the upstream cache */
-            char loginbuf[256];
-            const char *username = "-";
+    /* Fixup (Proxy-)Authorization special cases. Plain relaying dealt with above */
+    httpFixupAuthentication(request, orig_request, hdr_in, hdr_out, flags);
 
-            if (orig_request->auth_user_request)
-                username = orig_request->auth_user_request->username();
-            else if (orig_request->extacl_user.size())
-                username = orig_request->extacl_user.termedBuf();
-
-            snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);
-
-            httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
-                              base64_encode(loginbuf));
-        } else {
-            /* Fixed login string */
-            httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
-                              base64_encode(orig_request->peer_login));
-        }
-    }
-
-    /* append Cache-Control, add max-age if not there already */ {
+    /* append Cache-Control, add max-age if not there already */
+    {
         HttpHdrCc *cc = hdr_in->getCc();
 
         if (!cc)
