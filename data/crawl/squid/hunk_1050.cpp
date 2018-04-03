     }
 
     /* check for stale nonce */
-    if (!authDigestNonceIsValid(digest_request->nonce, digest_request->nc)) {
-        debugs(29, 3, "user '" << auth_user->username() << "' validated OK but nonce stale");
-        auth_user->credentials(Auth::Handshake);
-        digest_request->setDenyMessage("Stale nonce");
+    /* check Auth::Pending to avoid loop */
+
+    if (!authDigestNonceIsValid(digest_request->nonce, digest_request->nc) && user()->credentials() != Auth::Pending) {
+        debugs(29, 3, auth_user->username() << "' validated OK but nonce stale: " << digest_request->nonceb64);
+        /* Pending prevent banner and makes a ldap control */
+        auth_user->credentials(Auth::Pending);
+        nonce->flags.valid = false;
+        authDigestNoncePurge(nonce);
         return;
     }
 