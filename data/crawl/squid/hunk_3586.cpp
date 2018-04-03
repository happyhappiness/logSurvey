 
     /* Nothing to do unless we are forwarding to a peer */
     if (!request->flags.proxying)
-	return;
+        return;
 
     /* Needs to be explicitly enabled */
     if (!orig_request->peer_login)
-	return;
+        return;
 
     /* Maybe already dealt with? */
     if (hdr_out->has(header))
-	return;
+        return;
 
     /* Nothing to do here for PASSTHRU */
     if (strcmp(orig_request->peer_login, "PASSTHRU") == 0)
-	return;
+        return;
 
     /* PROXYPASS is a special case, single-signon to servers with the proxy password (basic only) */
     if (flags.originpeer && strcmp(orig_request->peer_login, "PROXYPASS") == 0 && hdr_in->has(HDR_PROXY_AUTHORIZATION)) {
-	const char *auth = hdr_in->getStr(HDR_PROXY_AUTHORIZATION);
+        const char *auth = hdr_in->getStr(HDR_PROXY_AUTHORIZATION);
 
-	if (auth && strncasecmp(auth, "basic ", 6) == 0) {
-	    hdr_out->putStr(header, auth);
-	    return;
-	}
+        if (auth && strncasecmp(auth, "basic ", 6) == 0) {
+            hdr_out->putStr(header, auth);
+            return;
+        }
     }
 
     /* Special mode to pass the username to the upstream cache */
     if (*orig_request->peer_login == '*') {
-	char loginbuf[256];
-	const char *username = "-";
+        char loginbuf[256];
+        const char *username = "-";
 
-	if (orig_request->extacl_user.size())
-	    username = orig_request->extacl_user.termedBuf();
-	else if (orig_request->auth_user_request)
-	    username = orig_request->auth_user_request->username();
+        if (orig_request->extacl_user.size())
+            username = orig_request->extacl_user.termedBuf();
+        else if (orig_request->auth_user_request)
+            username = orig_request->auth_user_request->username();
 
-	snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);
+        snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);
 
-	httpHeaderPutStrf(hdr_out, header, "Basic %s",
-			  base64_encode(loginbuf));
-	return;
+        httpHeaderPutStrf(hdr_out, header, "Basic %s",
+                          base64_encode(loginbuf));
+        return;
     }
 
     /* external_acl provided credentials */
     if (orig_request->extacl_user.size() && orig_request->extacl_passwd.size() &&
-	    (strcmp(orig_request->peer_login, "PASS") == 0 ||
-	     strcmp(orig_request->peer_login, "PROXYPASS") == 0)) {
-	char loginbuf[256];
-	snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
-		 SQUIDSTRINGPRINT(orig_request->extacl_user),
-		 SQUIDSTRINGPRINT(orig_request->extacl_passwd));
-	httpHeaderPutStrf(hdr_out, header, "Basic %s",
-			  base64_encode(loginbuf));
-	return;
+            (strcmp(orig_request->peer_login, "PASS") == 0 ||
+             strcmp(orig_request->peer_login, "PROXYPASS") == 0)) {
+        char loginbuf[256];
+        snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
+                 SQUIDSTRINGPRINT(orig_request->extacl_user),
+                 SQUIDSTRINGPRINT(orig_request->extacl_passwd));
+        httpHeaderPutStrf(hdr_out, header, "Basic %s",
+                          base64_encode(loginbuf));
+        return;
     }
 
     /* Kerberos login to peer */
