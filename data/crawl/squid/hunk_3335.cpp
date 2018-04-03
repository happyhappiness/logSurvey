     }
 }
 
-static void
-authenticateDigestHandleReply(void *data, char *reply)
+int32_t
+DigestUser::ttl() const
 {
-    DigestAuthenticateStateData *replyData = static_cast < DigestAuthenticateStateData * >(data);
-    AuthUserRequest *auth_user_request;
-    AuthDigestUserRequest *digest_request;
-    digest_user_h *digest_user;
-    char *t = NULL;
-    void *cbdata;
-    debugs(29, 9, "authenticateDigestHandleReply: {" << (reply ? reply : "<NULL>") << "}");
-
-    if (reply) {
-        if ((t = strchr(reply, ' ')))
-            *t++ = '\0';
-
-        if (*reply == '\0' || *reply == '\n')
-            reply = NULL;
-    }
+    int32_t global_ttl = static_cast<int32_t>(expiretime - squid_curtime + Config.authenticateTTL);
 
-    assert(replyData->auth_user_request != NULL);
-    auth_user_request = replyData->auth_user_request;
-    digest_request = dynamic_cast < AuthDigestUserRequest * >(auth_user_request);
-    assert(digest_request);
-
-    digest_user = dynamic_cast < digest_user_h * >(auth_user_request->user());
-    assert(digest_user != NULL);
-
-    if (reply && (strncasecmp(reply, "ERR", 3) == 0)) {
-        digest_request->credentials(AuthDigestUserRequest::Failed);
-        digest_request->flags.invalid_password = 1;
+    /* find the longest lasting nonce. */
+    int32_t latest_nonce = -1;
+    dlink_node *link = nonces.head;
+    while (link) {
+        digest_nonce_h *nonce = static_cast<digest_nonce_h *>(link->data);
+        if (nonce->flags.valid && nonce->noncedata.creationtime > latest_nonce)
+            latest_nonce = nonce->noncedata.creationtime;
 
-        if (t && *t)
-            digest_request->setDenyMessage(t);
-    } else if (reply) {
-        CvtBin(reply, digest_user->HA1);
-        digest_user->HA1created = 1;
+        link = link->next;
     }
+    if (latest_nonce == -1)
+        return min(-1, global_ttl);
 
-    if (cbdataReferenceValidDone(replyData->data, &cbdata))
-        replyData->handler(cbdata, NULL);
+    int32_t nonce_ttl = latest_nonce - current_time.tv_sec + static_cast<AuthDigestConfig*>(AuthConfig::Find("digest"))->noncemaxduration;
 
-    //we know replyData->auth_user_request != NULL, or we'd have asserted
-    AUTHUSERREQUESTUNLOCK(replyData->auth_user_request, "replyData");
-
-    cbdataFree(replyData);
+    return min(nonce_ttl, global_ttl);
 }
 
 /* Initialize helpers and the like for this auth scheme. Called AFTER parsing the
