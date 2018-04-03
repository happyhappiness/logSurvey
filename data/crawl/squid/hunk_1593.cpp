 
     /* now the nonce */
     nonce = authenticateDigestNonceFindNonce(digest_request->nonceb64);
+    /* check that we're not being hacked / the username hasn't changed */
+    if (nonce && nonce->user && strcmp(username, nonce->user->username())) {
+        debugs(29, 2, "Username for the nonce does not equal the username for the request");
+        nonce = NULL;
+    }
+    /* check for stale nonce */
+    if (authDigestNonceIsStale(nonce)) {
+        debugs(29, 3, "The received nonce is stale from " << username);
+        digest_request->setDenyMessage("Stale nonce");
+        nonce = NULL;
+    }
     if (!nonce) {
         /* we couldn't find a matching nonce! */
-        debugs(29, 2, "Unexpected or invalid nonce received");
-        if (digest_request->user() != NULL)
-            digest_request->user()->credentials(Auth::Failed);
-        rv = authDigestLogUsername(username, digest_request, aRequestRealm);
+        debugs(29, 2, "Unexpected or invalid nonce received from " << username);
+        Auth::UserRequest::Pointer auth_request = authDigestLogUsername(username, digest_request, aRequestRealm);
+        auth_request->user()->credentials(Auth::Handshake);
         safe_free(username);
-        return rv;
+        return auth_request;
     }
 
     digest_request->nonce = nonce;
