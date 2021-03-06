     helperStatefulStats(sentry, ntlmauthenticators, "NTLM Authenticator Statistics");
 }
 
-
-/* send the initial data to a stateful ntlm authenticator module */
-void
-AuthNTLMUserRequest::module_start(RH * handler, void *data)
-{
-    authenticateStateData *r = NULL;
-    static char buf[8192];
-    ntlm_user_t *ntlm_user;
-    AuthUser *auth_user = user();
-
-    assert(data);
-    assert(handler);
-    assert(auth_user);
-    assert(auth_user->auth_type == AUTH_NTLM);
-
-    ntlm_user = dynamic_cast<ntlm_user_t *>(user());
-
-    debugs(29, 8, "AuthNTLMUserRequest::module_start: auth state is '" << auth_state << "'");
-
-    if (ntlmConfig.authenticate == NULL) {
-        debugs(29, 0, "AuthNTLMUserRequest::module_start: no NTLM program specified.");
-        handler(data, NULL);
-        return;
-    }
-
-    r = cbdataAlloc(authenticateStateData);
-    r->handler = handler;
-    r->data = cbdataReference(data);
-    r->auth_user_request = this;
-    AUTHUSERREQUESTLOCK(r->auth_user_request, "r");
-
-    if (auth_state == AUTHENTICATE_STATE_INITIAL) {
-        snprintf(buf, 8192, "YR %s\n", client_blob); //CHECKME: can ever client_blob be 0 here?
-    } else {
-        snprintf(buf, 8192, "KK %s\n", client_blob);
-    }
-
-    waiting = 1;
-
-    safe_free(client_blob);
-    helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, authserver);
-}
-
-/**
- * Atomic action: properly release the NTLM auth helpers which may have been reserved
- * for this request connections use.
- */
-void
-AuthNTLMUserRequest::releaseAuthServer()
-{
-    if (authserver) {
-        debugs(29, 6, HERE << "releasing NTLM auth server '" << authserver << "'");
-        helperStatefulReleaseServer(authserver);
-        authserver = NULL;
-    } else
-        debugs(29, 6, HERE << "No NTLM auth server to release.");
-}
-
-/* clear any connection related authentication details */
-void
-AuthNTLMUserRequest::onConnectionClose(ConnStateData *conn)
-{
-    assert(conn != NULL);
-
-    debugs(29, 8, "AuthNTLMUserRequest::onConnectionClose: closing connection '" << conn << "' (this is '" << this << "')");
-
-    if (conn->auth_user_request == NULL) {
-        debugs(29, 8, "AuthNTLMUserRequest::onConnectionClose: no auth_user_request");
-        return;
-    }
-
-    // unlock / un-reserve the helpers
-    releaseAuthServer();
-
-    /* unlock the connection based lock */
-    debugs(29, 9, "AuthNTLMUserRequest::onConnectionClose: Unlocking auth_user from the connection '" << conn << "'.");
-
-    AUTHUSERREQUESTUNLOCK(conn->auth_user_request, "conn");
-}
-
 /*
  * Decode a NTLM [Proxy-]Auth string, placing the results in the passed
  * Auth_user structure.
  */
-AuthUserRequest *
+AuthUserRequest::Pointer
 AuthNTLMConfig::decode(char const *proxy_auth)
 {
-    NTLMUser *newUser = new NTLMUser(&ntlmConfig);
-    AuthNTLMUserRequest *auth_user_request = new AuthNTLMUserRequest ();
+    NTLMUser *newUser = new NTLMUser(AuthConfig::Find("ntlm"));
+    AuthUserRequest::Pointer auth_user_request = new AuthNTLMUserRequest();
     assert(auth_user_request->user() == NULL);
+
     auth_user_request->user(newUser);
     auth_user_request->user()->auth_type = AUTH_NTLM;
-    auth_user_request->user()->addRequest(auth_user_request);
 
     /* all we have to do is identify that it's NTLM - the helper does the rest */
     debugs(29, 9, "AuthNTLMConfig::decode: NTLM authentication");
     return auth_user_request;
 }
 
-int
-AuthNTLMUserRequest::authenticated() const
-{
-    if (auth_state == AUTHENTICATE_STATE_DONE) {
-        debugs(29, 9, "AuthNTLMUserRequest::authenticated: user authenticated.");
-        return 1;
-    }
-
-    debugs(29, 9, "AuthNTLMUserRequest::authenticated: user not fully authenticated.");
-
-    return 0;
-}
-
-void
-AuthNTLMUserRequest::authenticate(HttpRequest * aRequest, ConnStateData * conn, http_hdr_type type)
-{
-    const char *proxy_auth, *blob;
-
-    /* TODO: rename this!! */
-    AuthUser *local_auth_user;
-    ntlm_user_t *ntlm_user;
-
-    local_auth_user = user();
-    assert(local_auth_user);
-    assert(local_auth_user->auth_type == AUTH_NTLM);
-    ntlm_user = dynamic_cast<ntlm_user_t *>(local_auth_user);
-    assert (this);
-
-    /* Check that we are in the client side, where we can generate
-     * auth challenges */
-
-    if (conn == NULL || !cbdataReferenceValid(conn)) {
-        auth_state = AUTHENTICATE_STATE_FAILED;
-        debugs(29, 1, "AuthNTLMUserRequest::authenticate: attempt to perform authentication without a connection!");
-        return;
-    }
-
-    if (waiting) {
-        debugs(29, 1, "AuthNTLMUserRequest::authenticate: waiting for helper reply!");
-        return;
-    }
-
-    if (server_blob) {
-        debugs(29, 2, "AuthNTLMUserRequest::authenticate: need to challenge client '" << server_blob << "'!");
-        return;
-    }
-
-    /* get header */
-    proxy_auth = aRequest->header.getStr(type);
-
-    /* locate second word */
-    blob = proxy_auth;
-
-    /* if proxy_auth is actually NULL, we'd better not manipulate it. */
-    if (blob) {
-        while (xisspace(*blob) && *blob)
-            blob++;
-
-        while (!xisspace(*blob) && *blob)
-            blob++;
-
-        while (xisspace(*blob) && *blob)
-            blob++;
-    }
-
-    switch (auth_state) {
-
-    case AUTHENTICATE_STATE_NONE:
-        /* we've received a ntlm request. pass to a helper */
-        debugs(29, 9, "AuthNTLMUserRequest::authenticate: auth state ntlm none. Received blob: '" << proxy_auth << "'");
-        auth_state = AUTHENTICATE_STATE_INITIAL;
-        safe_free(client_blob);
-        client_blob=xstrdup(blob);
-        conn->auth_type = AUTH_NTLM;
-        assert(conn->auth_user_request == NULL);
-        conn->auth_user_request = this;
-        AUTHUSERREQUESTLOCK(conn->auth_user_request, "conn");
-        request = aRequest;
-        HTTPMSGLOCK(request);
-        return;
-
-        break;
-
-    case AUTHENTICATE_STATE_INITIAL:
-        debugs(29, 1, "AuthNTLMUserRequest::authenticate: need to ask helper");
-
-        return;
-
-        break;
-
-
-    case AUTHENTICATE_STATE_IN_PROGRESS:
-        /* we should have received a blob from the client. Hand it off to
-         * some helper */
-        safe_free(client_blob);
-
-        client_blob = xstrdup (blob);
-
-        if (request)
-            HTTPMSGUNLOCK(request);
-        request = aRequest;
-        HTTPMSGLOCK(request);
-        return;
-
-        break;
-
-    case AUTHENTICATE_STATE_DONE:
-        fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
-
-        break;
-
-    case AUTHENTICATE_STATE_FAILED:
-        /* we've failed somewhere in authentication */
-        debugs(29, 9, "AuthNTLMUserRequest::authenticate: auth state ntlm failed. " << proxy_auth);
-
-        return;
-
-        break;
-    }
-
-    return;
-}
-
-AuthNTLMUserRequest::AuthNTLMUserRequest() :
-        /*conn(NULL),*/ auth_state(AUTHENTICATE_STATE_NONE),
-        _theUser(NULL)
-{
-    waiting=0;
-    client_blob=0;
-    server_blob=0;
-    authserver=NULL;
-    request = NULL;
-}
-
-AuthNTLMUserRequest::~AuthNTLMUserRequest()
-{
-    safe_free(server_blob);
-    safe_free(client_blob);
-
-    releaseAuthServer();
-
-    if (request) {
-        HTTPMSGUNLOCK(request);
-        request = NULL;
-    }
-}
-
 void
 NTLMUser::deleteSelf() const
 {
