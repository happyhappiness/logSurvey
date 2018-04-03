     /* check to see if the auth_user already has a request outstanding */
     if (user()->credentials() == Auth::Pending) {
         /* there is a request with the same credentials already being verified */
-        basic_auth->queueRequest(this, handler, data);
+
+        BasicAuthQueueNode *node = static_cast<BasicAuthQueueNode *>(xcalloc(1, sizeof(BasicAuthQueueNode)));
+        assert(node);
+        node->auth_user_request = this;
+        node->handler = handler;
+        node->data = cbdataReference(data);
+
+        /* queue this validation request to be infored of the pending lookup results */
+        node->next = basic_auth->auth_queue;
+        basic_auth->auth_queue = node;
         return;
     }
-
-    basic_auth->submitRequest(this, handler, data);
+    // otherwise submit this request to the auth helper(s) for validation
+
+    /* mark this user as having verification in progress */
+    user()->credentials(Auth::Pending);
+    char buf[HELPER_INPUT_BUFFER];
+    static char username[HELPER_INPUT_BUFFER];
+    static char pass[HELPER_INPUT_BUFFER];
+    if (static_cast<Auth::Basic::Config*>(user()->config)->utf8) {
+        latin1_to_utf8(username, sizeof(username), user()->username());
+        latin1_to_utf8(pass, sizeof(pass), basic_auth->passwd);
+        xstrncpy(username, rfc1738_escape(username), sizeof(username));
+        xstrncpy(pass, rfc1738_escape(pass), sizeof(pass));
+    } else {
+        xstrncpy(username, rfc1738_escape(user()->username()), sizeof(username));
+        xstrncpy(pass, rfc1738_escape(basic_auth->passwd), sizeof(pass));
+    }
+    int sz = snprintf(buf, sizeof(buf), "%s %s\n", username, pass);
+    if (sz<=0) {
+        debugs(9, DBG_CRITICAL, "ERROR: Basic Authentication Failure. Can not build helper validation request.");
+        handler(data, NULL);
+    } else if (sz>=sizeof(buf)) {
+        debugs(9, DBG_CRITICAL, "ERROR: Basic Authentication Failure. user:password exceeds " << sizeof(buf) << " bytes.");
+        handler(data, NULL);
+    } else
+        helperSubmit(basicauthenticators, buf, AuthBasicUserRequest::HandleReply,
+                     new Auth::StateData(this, handler, data));
 }
 
+void
+AuthBasicUserRequest::HandleReply(void *data, char *reply)
+{
+    Auth::StateData *r = static_cast<Auth::StateData *>(data);
+    BasicAuthQueueNode *tmpnode;
+    char *t = NULL;
+    void *cbdata;
+    debugs(29, 9, HERE << "{" << (reply ? reply : "<NULL>") << "}");
+
+    if (reply) {
+        if ((t = strchr(reply, ' ')))
+            *t++ = '\0';
+
+        if (*reply == '\0')
+            reply = NULL;
+    }
+
+    assert(r->auth_user_request != NULL);
+    assert(r->auth_user_request->user()->auth_type == Auth::AUTH_BASIC);
+
+    /* this is okay since we only play with the Auth::Basic::User child fields below
+     * and dont pass the pointer itself anywhere */
+    Auth::Basic::User *basic_auth = dynamic_cast<Auth::Basic::User *>(r->auth_user_request->user().getRaw());
+
+    assert(basic_auth != NULL);
+
+    if (reply && (strncasecmp(reply, "OK", 2) == 0))
+        basic_auth->credentials(Auth::Ok);
+    else {
+        basic_auth->credentials(Auth::Failed);
+
+        if (t && *t)
+            r->auth_user_request->setDenyMessage(t);
+    }
+
+    basic_auth->expiretime = squid_curtime;
+
+    if (cbdataReferenceValidDone(r->data, &cbdata))
+        r->handler(cbdata, NULL);
+
+    cbdataReferenceDone(r->data);
+
+    while (basic_auth->auth_queue) {
+        tmpnode = basic_auth->auth_queue->next;
+
+        if (cbdataReferenceValidDone(basic_auth->auth_queue->data, &cbdata))
+            basic_auth->auth_queue->handler(cbdata, NULL);
+
+        xfree(basic_auth->auth_queue);
+
+        basic_auth->auth_queue = tmpnode;
+    }
+
+    delete r;
+}