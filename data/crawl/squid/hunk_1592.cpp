 
     if ((static_cast<Auth::Digest::Config*>(Auth::Config::Find("digest"))->authenticateProgram) && authDigestNonceLastRequest(nonce)) {
         flags.authinfo_sent = true;
-        debugs(29, 9, HERE << "Sending type:" << type << " header: 'nextnonce=\"" << authenticateDigestNonceNonceb64(nonce) << "\"");
-        httpHeaderPutStrf(&rep->header, type, "nextnonce=\"%s\"", authenticateDigestNonceNonceb64(nonce));
+        Auth::Digest::User *digest_user = dynamic_cast<Auth::Digest::User *>(user().getRaw());
+        digest_nonce_h *nextnonce = digest_user->currentNonce();
+        if (!nextnonce || authDigestNonceLastRequest(nonce)) {
+            nextnonce = authenticateDigestNonceNew();
+            authDigestUserLinkNonce(digest_user, nextnonce);
+        }
+        debugs(29, 9, "Sending type:" << type << " header: 'nextnonce=\"" << authenticateDigestNonceNonceb64(nextnonce) << "\"");
+        httpHeaderPutStrf(&rep->header, type, "nextnonce=\"%s\"", authenticateDigestNonceNonceb64(nextnonce));
     }
 }
 
