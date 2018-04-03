 	}
     }
     /* append Proxy-Authorization if configured for peer, and proxying */
-    if (!httpHeaderHas(hdr_out, HDR_PROXY_AUTHORIZATION)) {
-	if (request->flags.proxying && orig_request->peer_login &&
+    if (request->flags.proxying && orig_request->peer_login &&
+	    !httpHeaderHas(hdr_out, HDR_PROXY_AUTHORIZATION) &&
 	    strcmp(orig_request->peer_login, "PASS") != 0) {
+	if (*orig_request->peer_login == '*') {
+	    /* Special mode, to pass the username to the upstream cache */
+	    char loginbuf[256];
+	    char *username = "-";
+	    if (orig_request->auth_user_request)
+		username = authenticateUserRequestUsername(orig_request->auth_user_request);
+	    snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login+1);
+	    httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
+		base64_encode(loginbuf));
+	} else {
 	    httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
 		base64_encode(orig_request->peer_login));
 	}