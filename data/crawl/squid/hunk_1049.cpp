         debugs(29, 2, "Username for the nonce does not equal the username for the request");
         nonce = NULL;
     }
-    /* check for stale nonce */
-    if (authDigestNonceIsStale(nonce)) {
-        debugs(29, 3, "The received nonce is stale from " << username);
-        digest_request->setDenyMessage("Stale nonce");
-        nonce = NULL;
-    }
+
     if (!nonce) {
         /* we couldn't find a matching nonce! */
         debugs(29, 2, "Unexpected or invalid nonce received from " << username);
