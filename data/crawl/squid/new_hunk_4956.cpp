    auth_user_request->user()->addRequest(auth_user_request);

    /* all we have to do is identify that it's NTLM - the helper does the rest */
    debug(29, 9) ("AuthNTLMConfig::decode: NTLM authentication\n");
    return auth_user_request;
}

int
AuthNTLMUserRequest::authenticated() const
{
    if (auth_state == AUTHENTICATE_STATE_FINISHED) {
        debug(29, 9) ("AuthNTLMUserRequest::authenticated: user authenticated.\n");
        return 1;
    }

    debug(29, 9) ("AuthNTLMUserRequest::authenticated: user not fully authenticated.\n");

    return 0;
}

void
AuthNTLMUserRequest::authenticate(HttpRequest * request, ConnStateData::Pointer conn, http_hdr_type type)
{
    const char *proxy_auth, *blob;

    //ProxyAuthCachePointer *proxy_auth_hash = NULL;
    auth_user_hash_pointer *usernamehash;

    /* TODO: rename this!! */
    auth_user_t *local_auth_user;
    ntlm_user_t *ntlm_user;

    local_auth_user = user();
    assert(local_auth_user);
    assert(local_auth_user->auth_type == AUTH_NTLM);
    ntlm_user = dynamic_cast<ntlm_user_t *>(local_auth_user);
    assert (this);

    /* Check that we are in the client side, where we can generate
     * auth challenges */

    if (conn.getRaw() == NULL) {
        auth_state = AUTHENTICATE_STATE_FAILED;
        debug(29, 1) ("AuthNTLMUserRequest::authenticate: attempt to perform authentication without a connection!\n");
        return;
    }

    if (waiting) {
        debug(29, 1) ("AuthNTLMUserRequest::authenticate: waiting for helper reply!\n");
        return;
    }

    if (server_blob) {
        debug(29,2)("AuthNTLMUserRequest::authenticate: need to challenge client '%s'!\n", server_blob);
        return;
    }

    /* get header */
    proxy_auth = httpHeaderGetStr(&request->header, type);

    blob = proxy_auth + strlen("NTLM");

    while (xisspace(*blob))     // trim leading spaces in blob
        blob++;

    switch (auth_state) {

    case AUTHENTICATE_STATE_NONE:
        /* we've recieved a ntlm request. pass to a helper */
        debug(29, 9) ("AuthNTLMUserRequest::authenticate: auth state ntlm none. Received blob: '%s'\n", proxy_auth);
        auth_state = AUTHENTICATE_STATE_INITIAL;
        safe_free(client_blob);
        client_blob=xstrdup(blob);
        conn->auth_type = AUTH_NTLM;
        conn->auth_user_request = this;
        conn = conn;

        lock()

            ;
        return;

        break;

    case AUTHENTICATE_STATE_INITIAL:
        debug(29,1)("AuthNTLMUserRequest::authenticate: need to ask helper\n");

        return;

        break;


    case AUTHENTICATE_STATE_IN_PROGRESS:
        /* we should have received a blob from the client. Hand it off to
         * some helper */
        safe_free(client_blob);

        client_blob = xstrdup (blob);

        return;

        break;

    case AUTHENTICATE_STATE_FINISHED:
        /* connection is authenticated */
        debug(29, 4) ("AuthNTLMUserRequest::authenticate: authenticated user %s\n", ntlm_user->username());

        /* see if this is an existing user with a different proxy_auth
         * string */
        usernamehash = static_cast<AuthUserHashPointer *>(hash_lookup(proxy_auth_username_cache, ntlm_user->username()));

        while (usernamehash && (usernamehash->user()->auth_type != AUTH_NTLM || strcmp(usernamehash->user()->username(), ntlm_user->username()) != 0))
            usernamehash = static_cast<AuthUserHashPointer *>(usernamehash->next);

        if (usernamehash) {
            /* we can't seamlessly recheck the username due to the
             * challenge-response nature of the protocol.
             * Just free the temporary auth_user */
            usernamehash->user()->absorb(local_auth_user);
            //authenticateAuthUserMerge(local_auth_user, usernamehash->user());
            local_auth_user = usernamehash->user();
            _auth_user = local_auth_user;
        } else {
            /* store user in hash's */
            local_auth_user->addToNameCache();
            // authenticateUserNameCacheAdd(local_auth_user);
        }

        /* set these to now because this is either a new login from an
         * existing user or a new user */
        local_auth_user->expiretime = current_time.tv_sec;

        authenticateNTLMReleaseServer(this);

        auth_state = AUTHENTICATE_STATE_DONE;

        return;

        break;

    case AUTHENTICATE_STATE_DONE:
        fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");

        break;

    case AUTHENTICATE_STATE_FAILED:
        /* we've failed somewhere in authentication */
        debug(29, 9) ("AuthNTLMUserRequest::authenticate: auth state ntlm failed. %s\n", proxy_auth);

        return;

        break;
    }

    return;
}

AuthNTLMUserRequest::AuthNTLMUserRequest() :
        conn(NULL), auth_state(AUTHENTICATE_STATE_NONE),
        _theUser(NULL)
{
    waiting=0;
    client_blob=0;
    server_blob=0;
    authserver=NULL;
}

AuthNTLMUserRequest::~AuthNTLMUserRequest()
{
    safe_free(server_blob);
    safe_free(client_blob);

    if (authserver != NULL) {
        debug(29, 9) ("AuthNTLMUserRequest::~AuthNTLMUserRequest: releasing server '%p'\n", authserver);
        helperStatefulReleaseServer(authserver);
        authserver = NULL;
    }
