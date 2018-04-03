 void
 authenticateDigestFixHeader(auth_user_request_t * auth_user_request, HttpReply * rep, http_hdr_type type, request_t * request)
 {
-    digest_request_h *digest_request;
+    if (!digestConfig->authenticate)
+        return;
+
     int stale = 0;
-    digest_nonce_h *nonce = authenticateDigestNonceNew();
 
-    if (auth_user_request && authDigestAuthenticated(auth_user_request) && auth_user_request->scheme_data) {
-        digest_request = static_cast < digest_request_h * >(auth_user_request->scheme_data);
-        stale = authDigestNonceIsStale(digest_request->nonce);
-    }
+    if (auth_user_request && auth_user_request->state()) {
+        digest_request_h *digest_request;
+        digest_request = dynamic_cast < digest_request_h * >(auth_user_request->state());
+        assert (digest_request);
 
-    if (digestConfig->authenticate) {
-        debug(29, 9) ("authenticateFixHeader: Sending type:%d header: 'Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s\n", type, digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
-        /* in the future, for WWW auth we may want to support the domain entry */
-        httpHeaderPutStrf(&rep->header, type, "Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s", digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
+        if (digest_request->authenticated())
+            /* stale indicates that the old nonce can't be used
+             * and we are providing a new one.
+             */
+            stale = authDigestNonceIsStale(digest_request->nonce);
     }
+
+    /* on a 407 or 401 we always use a new nonce */
+    digest_nonce_h *nonce = authenticateDigestNonceNew();
+
+    debug(29, 9) ("authenticateFixHeader: Sending type:%d header: 'Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s\n", type, digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
+
+    /* in the future, for WWW auth we may want to support the domain entry */
+    httpHeaderPutStrf(&rep->header, type, "Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s", digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
 }
 
 static void
 authenticateDigestUserFree(auth_user_t * auth_user)
 {
     digest_user_h *digest_user = static_cast < digest_user_h * >(auth_user->scheme_data);
-    dlink_node *link, *tmplink;
     debug(29, 9) ("authenticateDigestFreeUser: Clearing Digest scheme data\n");
 
     if (!digest_user)
         return;
 
-    safe_free(digest_user->username);
+    delete digest_user;
 
-    link = digest_user->nonces.head;
+    auth_user->scheme_data = NULL;
+}
+
+digest_user_h::~digest_user_h()
+{
+    safe_free(username);
+
+    dlink_node *link, *tmplink;
+    link = nonces.head;
 
     while (link) {
         tmplink = link;
         link = link->next;
-        dlinkDelete(tmplink, &digest_user->nonces);
+        dlinkDelete(tmplink, &nonces);
         authDigestNoncePurge(static_cast < digest_nonce_h * >(tmplink->data));
         authDigestNonceUnlink(static_cast < digest_nonce_h * >(tmplink->data));
         dlinkNodeDelete(tmplink);
     }
-
-    memPoolFree(digest_user_pool, auth_user->scheme_data);
-    auth_user->scheme_data = NULL;
 }
 
 static void
 authenticateDigestHandleReply(void *data, char *reply)
 {
-    DigestAuthenticateStateData *r = static_cast < DigestAuthenticateStateData * >(data);
+    DigestAuthenticateStateData *replyData = static_cast < DigestAuthenticateStateData * >(data);
     auth_user_request_t *auth_user_request;
     digest_request_h *digest_request;
     digest_user_h *digest_user;