     /* on a 407 or 401 we always use a new nonce */
     digest_nonce_h *nonce = authenticateDigestNonceNew();
 
-    debug(29, 9) ("authenticateFixHeader: Sending type:%d header: 'Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s\n", type, digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
+    debug(29, 9) ("authenticateFixHeader: Sending type:%d header: 'Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s\n", type, digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
 
     /* in the future, for WWW auth we may want to support the domain entry */
-    httpHeaderPutStrf(&rep->header, type, "Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s", digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
+    httpHeaderPutStrf(&rep->header, type, "Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s", digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
 }
 
-static void
-authenticateDigestUserFree(auth_user_t * auth_user)
+DigestUser::~DigestUser()
 {
-    digest_user_h *digest_user = static_cast < digest_user_h * >(auth_user->scheme_data);
-    debug(29, 9) ("authenticateDigestFreeUser: Clearing Digest scheme data\n");
-
-    if (!digest_user)
-        return;
-
-    delete digest_user;
-
-    auth_user->scheme_data = NULL;
-}
-
-digest_user_h::~digest_user_h()
-{
-    safe_free(username);
 
     dlink_node *link, *tmplink;
     link = nonces.head;
