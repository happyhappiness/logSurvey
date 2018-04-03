     /* on a 407 or 401 we always use a new nonce */
     digest_nonce_h *nonce = authenticateDigestNonceNew();
 
-    debugs(29, 9, "authenticateFixHeader: Sending type:" << type <<
+    debugs(29, 9, "authenticateFixHeader: Sending type:" << hdrType <<
            " header: 'Digest realm=\"" << digestAuthRealm << "\", nonce=\"" <<
            authenticateDigestNonceNonceb64(nonce) << "\", qop=\"" << QOP_AUTH <<
            "\", stale=" << (stale ? "true" : "false"));
 
     /* in the future, for WWW auth we may want to support the domain entry */
-    httpHeaderPutStrf(&rep->header, type, "Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s", digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
+    httpHeaderPutStrf(&rep->header, hdrType, "Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s", digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
 }
 
 DigestUser::~DigestUser()
