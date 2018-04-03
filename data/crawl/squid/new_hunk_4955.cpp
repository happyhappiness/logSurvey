    helperStatefulStats(sentry, ntlmauthenticators);
}


/* send the initial data to a stateful ntlm authenticator module */
void
AuthNTLMUserRequest::module_start(RH * handler, void *data)
{
    authenticateStateData *r = NULL;
    static char buf[8192];
    ntlm_user_t *ntlm_user;
    auth_user_t *auth_user = user();

    assert(data);
    assert(handler);
    assert(auth_user);
    assert(auth_user->auth_type == AUTH_NTLM);

    ntlm_user = dynamic_cast<ntlm_user_t *>(user());

    debug(29, 8) ("AuthNTLMUserRequest::module_start: auth state is '%d'\n", auth_state);

    if (ntlmConfig.authenticate == NULL) {
        debug(29, 0) ("AuthNTLMUserRequest::module_start: no NTLM program specified.");
        handler(data, NULL);
        return;
    }

    r = cbdataAlloc(authenticateStateData);
    r->handler = handler;
    cbdataReference(data);
    r->data = data;
    r->auth_user_request = this;

    lock()

        ;
    if (auth_state == AUTHENTICATE_STATE_INITIAL) {
        snprintf(buf, 8192, "YR %s\n", client_blob); //CHECKME: can ever client_blob be 0 here?
    } else {
        snprintf(buf, 8192, "KK %s\n", client_blob);
    }

    waiting = 1;

    safe_free(client_blob);
    helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, authserver);
}

/* clear the NTLM helper of being reserved for future requests */
static void
authenticateNTLMReleaseServer(auth_user_request_t * auth_user_request)
{
    AuthNTLMUserRequest *ntlm_request;
    assert(auth_user_request->user()->auth_type == AUTH_NTLM);
    ntlm_request = dynamic_cast< AuthNTLMUserRequest *>(auth_user_request);
    debug(29, 9) ("authenticateNTLMReleaseServer: releasing server '%p'\n", ntlm_request->authserver);
    /* is it possible for the server to be NULL? hno seems to think so.
     * Let's see what happens, might segfault in helperStatefulReleaseServer
     * if it does. I leave it like this not to cover possibly problematic
     * code-paths. Kinkie */
    helperStatefulReleaseServer(ntlm_request->authserver);
    ntlm_request->authserver = NULL;
}

/* clear any connection related authentication details */
void
AuthNTLMUserRequest::onConnectionClose(ConnStateData *connection)
{
    assert(connection != NULL);

    debug(29,8)("AuthNTLMUserRequest::onConnectionClose: closing connection '%p' (this is '%p')\n",connection,this);

    if (connection->auth_user_request == NULL) {
        debug(29,8)("AuthNTLMUserRequest::onConnectionClose: no auth_user_request\n");
        return;
    }

    if (authserver != NULL)
        authenticateNTLMReleaseServer(this);

    /* unlock the connection based lock */
    debug(29, 9) ("AuthNTLMUserRequest::onConnectionClose: Unlocking auth_user from the connection '%p'.\n",connection);

    /* This still breaks the abstraction, but is at least read only now.
    * If needed, this could be ignored, as the conn deletion will also unlock
    * the auth user request.
    */
    unlock();

    connection->auth_user_request = NULL;
}

/*
 * Decode a NTLM [Proxy-]Auth string, placing the results in the passed
 * Auth_user structure.
 */
AuthUserRequest *
