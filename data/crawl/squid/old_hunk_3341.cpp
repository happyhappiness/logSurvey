    helperStatefulStats(sentry, negotiateauthenticators, "Negotiate Authenticator Statistics");
}


/** send the initial data to a stateful negotiate authenticator module */
void
AuthNegotiateUserRequest::module_start(RH * handler, void *data)
{
    authenticateStateData *r = NULL;
    static char buf[MAX_AUTHTOKEN_LEN];
    negotiate_user_t *negotiate_user;
    AuthUser *auth_user = user();

    assert(data);
    assert(handler);
    assert(auth_user);
    assert(auth_user->auth_type == AUTH_NEGOTIATE);

    negotiate_user = dynamic_cast<negotiate_user_t *>(user());

    debugs(29, 8, "AuthNegotiateUserRequest::module_start: auth state is '" << auth_state << "'");

    if (negotiateConfig.authenticate == NULL) {
        debugs(29, 0, "AuthNegotiateUserRequest::module_start: no Negotiate program specified.");
        handler(data, NULL);
        return;
    }

    r = cbdataAlloc(authenticateStateData);
    r->handler = handler;
    r->data = cbdataReference(data);
    r->auth_user_request = this;
    AUTHUSERREQUESTLOCK(r->auth_user_request, "r");

    if (auth_state == AUTHENTICATE_STATE_INITIAL) {
        snprintf(buf, MAX_AUTHTOKEN_LEN, "YR %s\n", client_blob); //CHECKME: can ever client_blob be 0 here?
    } else {
        snprintf(buf, MAX_AUTHTOKEN_LEN, "KK %s\n", client_blob);
    }

    waiting = 1;

    safe_free(client_blob);
    helperStatefulSubmit(negotiateauthenticators, buf, authenticateNegotiateHandleReply, r, authserver);
}

/**
 * Atomic action: properly release the Negotiate auth helpers which may have been reserved
 * for this request connections use.
 */
void
AuthNegotiateUserRequest::releaseAuthServer()
{
    if (authserver) {
        debugs(29, 6, HERE << "releasing Negotiate auth server '" << authserver << "'");
        helperStatefulReleaseServer(authserver);
        authserver = NULL;
    } else
        debugs(29, 6, HERE << "No Negotiate auth server to release.");
}

/* clear any connection related authentication details */
void
AuthNegotiateUserRequest::onConnectionClose(ConnStateData *conn)
{
    assert(conn != NULL);

    debugs(29, 8, "AuthNegotiateUserRequest::onConnectionClose: closing connection '" << conn << "' (this is '" << this << "')");

    if (conn->auth_user_request == NULL) {
        debugs(29, 8, "AuthNegotiateUserRequest::onConnectionClose: no auth_user_request");
        return;
    }

    releaseAuthServer();

    /* unlock the connection based lock */
    debugs(29, 9, "AuthNegotiateUserRequest::onConnectionClose: Unlocking auth_user from the connection '" << conn << "'.");

    AUTHUSERREQUESTUNLOCK(conn->auth_user_request, "conn");
}

/*
 * Decode a Negotiate [Proxy-]Auth string, placing the results in the passed
 * Auth_user structure.
 */
AuthUserRequest *
AuthNegotiateConfig::decode(char const *proxy_auth)
{
    NegotiateUser *newUser = new NegotiateUser(&negotiateConfig);
    AuthNegotiateUserRequest *auth_user_request = new AuthNegotiateUserRequest ();
    assert(auth_user_request->user() == NULL);
    auth_user_request->user(newUser);
    auth_user_request->user()->auth_type = AUTH_NEGOTIATE;
    auth_user_request->user()->addRequest(auth_user_request);

    /* all we have to do is identify that it's Negotiate - the helper does the rest */
    debugs(29, 9, "AuthNegotiateConfig::decode: Negotiate authentication");
    return auth_user_request;
}

int
AuthNegotiateUserRequest::authenticated() const
{
    if (auth_state == AUTHENTICATE_STATE_DONE) {
        debugs(29, 9, "AuthNegotiateUserRequest::authenticated: user authenticated.");
        return 1;
    }

    debugs(29, 9, "AuthNegotiateUserRequest::authenticated: user not fully authenticated.");

    return 0;
}

void
AuthNegotiateUserRequest::authenticate(HttpRequest * aRequest, ConnStateData * conn, http_hdr_type type)
{
    const char *proxy_auth, *blob;

    /** \todo rename this!! */
    AuthUser *local_auth_user;
    negotiate_user_t *negotiate_user;

    local_auth_user = user();
    assert(local_auth_user);
    assert(local_auth_user->auth_type == AUTH_NEGOTIATE);
    negotiate_user = dynamic_cast<negotiate_user_t *>(local_auth_user);
    assert (this);

    /** Check that we are in the client side, where we can generate
     * auth challenges */

    if (conn == NULL) {
        auth_state = AUTHENTICATE_STATE_FAILED;
        debugs(29, 1, "AuthNegotiateUserRequest::authenticate: attempt to perform authentication without a connection!");
        return;
    }

    if (waiting) {
        debugs(29, 1, "AuthNegotiateUserRequest::authenticate: waiting for helper reply!");
        return;
    }

    if (server_blob) {
        debugs(29, 2, "AuthNegotiateUserRequest::authenticate: need to challenge client '" << server_blob << "'!");
        return;
    }

    /* get header */
    proxy_auth = aRequest->header.getStr(type);

    /* locate second word */
    blob = proxy_auth;

    if (blob) {
        while (xisspace(*blob) && *blob)
            blob++;

        while (!xisspace(*blob) && *blob)
            blob++;

        while (xisspace(*blob) && *blob)
            blob++;
    }

    switch (auth_state) {

    case AUTHENTICATE_STATE_NONE:
        /* we've received a negotiate request. pass to a helper */
        debugs(29, 9, "AuthNegotiateUserRequest::authenticate: auth state negotiate none. Received blob: '" << proxy_auth << "'");
        auth_state = AUTHENTICATE_STATE_INITIAL;
        safe_free(client_blob);
        client_blob=xstrdup(blob);
        conn->auth_type = AUTH_NEGOTIATE;
        assert(conn->auth_user_request == NULL);
        conn->auth_user_request = this;
        AUTHUSERREQUESTLOCK(conn->auth_user_request, "conn");
        request = aRequest;
        HTTPMSGLOCK(request);
        return;

        break;

    case AUTHENTICATE_STATE_INITIAL:
        debugs(29, 1, "AuthNegotiateUserRequest::authenticate: need to ask helper");

        return;

        break;


    case AUTHENTICATE_STATE_IN_PROGRESS:
        /* we should have received a blob from the client. Hand it off to
         * some helper */
        safe_free(client_blob);

        client_blob = xstrdup (blob);

        if (request)
            HTTPMSGUNLOCK(request);
        request = aRequest;
        HTTPMSGLOCK(request);
        return;

        break;

    case AUTHENTICATE_STATE_DONE:
        fatal("AuthNegotiateUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");

        break;

    case AUTHENTICATE_STATE_FAILED:
        /* we've failed somewhere in authentication */
        debugs(29, 9, "AuthNegotiateUserRequest::authenticate: auth state negotiate failed. " << proxy_auth);

        return;

        break;
    }

    return;
}

AuthNegotiateUserRequest::AuthNegotiateUserRequest() :
        /*conn(NULL),*/ auth_state(AUTHENTICATE_STATE_NONE),
        _theUser(NULL)
{
    waiting=0;
    client_blob=0;
    server_blob=0;
    authserver=NULL;
    request=NULL;
}

AuthNegotiateUserRequest::~AuthNegotiateUserRequest()
{
    safe_free(server_blob);
    safe_free(client_blob);

    if (authserver != NULL) {
        debugs(29, 9, "AuthNegotiateUserRequest::~AuthNegotiateUserRequest: releasing server '" << authserver << "'");
        helperStatefulReleaseServer(authserver);
        authserver = NULL;
    }
    if (request) {
        HTTPMSGUNLOCK(request);
        request = NULL;
    }
}

void
NegotiateUser::deleteSelf() const
{
    delete this;
}

NegotiateUser::NegotiateUser (AuthConfig *aConfig) : AuthUser (aConfig)
{
    proxy_auth_list.head = proxy_auth_list.tail = NULL;
}

AuthConfig *
negotiateScheme::createConfig()
{
    return &negotiateConfig;
}

const char *
AuthNegotiateUserRequest::connLastHeader()
{
    return NULL;
}

