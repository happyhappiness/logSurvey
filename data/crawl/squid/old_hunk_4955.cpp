    helperStatefulStats(sentry, ntlmauthenticators);
}

/* is a particular challenge still valid ? */
static int
authenticateNTLMValidChallenge(ntlm_helper_state_t * helperstate)
{
    debug(29, 9) ("authenticateNTLMValidChallenge: Challenge is %s\n", helperstate->challenge ? "Valid" : "Invalid");

    if (helperstate->challenge == NULL)
        return 0;

    return 1;
}

/* does our policy call for changing the challenge now? */
static int
authenticateNTLMChangeChallenge_p(ntlm_helper_state_t * helperstate)
{
    /* don't check for invalid challenges just for expiry choices */
    /* this is needed because we have to starve the helper until all old
     * requests have been satisfied */

    if (!helperstate->renewed) {
        /* first use, no challenge has been set. Without this check, it will
         * loop forever */
        debug(29, 5) ("authenticateNTLMChangeChallenge_p: first use\n");
        return 0;
    }

    if (helperstate->challengeuses > ntlmConfig.challengeuses) {
        debug(29, 4) ("authenticateNTLMChangeChallenge_p: Challenge uses (%d) exceeded max uses (%d)\n", helperstate->challengeuses, ntlmConfig.challengeuses);
        return 1;
    }

    if (helperstate->renewed + ntlmConfig.challengelifetime < squid_curtime) {
        debug(29, 4) ("authenticateNTLMChangeChallenge_p: Challenge exceeded max lifetime by %d seconds\n", (int) (squid_curtime - (helperstate->renewed + ntlmConfig.challengelifetime)));
        return 1;
    }

    debug(29, 9) ("Challenge is to be reused\n");
    return 0;
}

/* send the initial data to a stateful ntlm authenticator module */
void
AuthNTLMUserRequest::module_start(RH * handler, void *data)
{
    authenticateStateData *r = NULL;
    helper_stateful_server *server;
    ntlm_helper_state_t *helperstate;
    char buf[8192];
    char *sent_string = NULL;
    ntlm_user_t *ntlm_user;
    auth_user_t *auth_user;

    auth_user = this->user();
    ntlm_user = dynamic_cast<ntlm_user_t *>(auth_user);
    assert(ntlm_user);
    assert(data);
    assert(auth_user->auth_type == AUTH_NTLM);
    debug(29, 9) ("authenticateNTLMStart: auth state '%d'\n", auth_state);

    switch (auth_state) {

    case AUTHENTICATE_STATE_NEGOTIATE:
        sent_string = ntlmnegotiate;
        break;

    case AUTHENTICATE_STATE_RESPONSE:
        sent_string = ntlmauthenticate;
        assert(authserver);
        debug(29, 9) ("authenticateNTLMStart: Asking NTLMauthenticator '%p'.\n", authserver);
        break;

    default:
        fatal("Invalid authenticate state for NTLMStart");
    }

    while (xisgraph(*sent_string))	/*trim NTLM */
        sent_string++;

    while (xisspace(*sent_string))	/*trim leading spaces */
        sent_string++;

    debug(29, 9) ("authenticateNTLMStart: state '%d'\n", auth_state);

    debug(29, 9) ("authenticateNTLMStart: '%s'\n", sent_string);

    if (ntlmConfig.authenticate == NULL) {
        debug(29, 0) ("authenticateNTLMStart: no NTLM program specified:'%s'\n", sent_string);
        handler(data, NULL);
        return;
    }

    /* this is ugly TODO: move the challenge generation routines to their own function and
     * tidy the logic up to make use of the efficiency we now have */
    switch (auth_state) {

    case AUTHENTICATE_STATE_NEGOTIATE:
        /*
         * 1: get a helper server
         * 2: does it have a challenge?
         * 3: tell it to get a challenge, or give ntlmauthdone the challenge
         */
        server = helperStatefulDefer(ntlmauthenticators);
        helperstate = server ? static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(server)) : NULL;

        while ((server != NULL) && authenticateNTLMChangeChallenge_p(helperstate)) {
            /* flag this helper for challenge changing */
            helperstate->starve = 1;
            /* and release the deferred request */
            helperStatefulReleaseServer(server);
            /* Get another deferrable server */
            server = helperStatefulDefer(ntlmauthenticators);
            helperstate = server ? static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(server)) : NULL;
        }

        if (server == NULL)
            debug(29, 9) ("unable to get a deferred ntlm helper... all helpers are refreshing challenges. Queuing as a placeholder request.\n");

        authserver = server;

        /* tell the log what helper we have been given */
        debug(29, 9) ("authenticateNTLMStart: helper '%p' assigned\n", server);

        /* server and valid challenge? */
        if ((server == NULL) || !authenticateNTLMValidChallenge(helperstate)) {
            /* No server, or server with invalid challenge */
            r = cbdataAlloc(authenticateStateData);
            r->handler = handler;
            r->data = cbdataReference(data);
            r->auth_user_request = this;

            lock()

                ; /* locking myself */

            if (server == NULL) {
                helperStatefulSubmit(ntlmauthenticators, NULL, authenticateNTLMHandleplaceholder, r, NULL);
            } else {
                /* Server with invalid challenge */
                snprintf(buf, 8192, "YR\n");
                helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, authserver);
            }
        } else {
            /* (server != NULL and we have a valid challenge) */
            /* TODO: turn the below into a function and call from here and handlereply */
            /* increment the challenge uses */
            helperstate->challengeuses++;
            /* assign the challenge */
            authchallenge = xstrdup(helperstate->challenge);
            /* we're not actually submitting a request, so we need to release the helper
             * should the connection close unexpectedly
             */
            authserver_deferred = 1;
            handler(data, NULL);
        }

        break;

    case AUTHENTICATE_STATE_RESPONSE:
        r = cbdataAlloc(authenticateStateData);
        r->handler = handler;
        r->data = cbdataReference(data);
        r->auth_user_request = this;

        lock()

            ;
        snprintf(buf, 8192, "KK %s\n", sent_string);

        /* getting rid of deferred request status */
        authserver_deferred = 0;

        helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, authserver);

        debug(29, 9) ("authenticateNTLMstart: finished\n");

        break;

    default:
        fatal("Invalid authenticate state for NTLMStart");
    }
}

/* callback used by stateful helper routines */
static int
authenticateNTLMHelperServerAvailable(void *data)
{
    ntlm_helper_state_t *statedata = static_cast<ntlm_helper_state_t *>(data);

    if (statedata != NULL) {
        if (statedata->starve) {
            debug(29, 4) ("authenticateNTLMHelperServerAvailable: starving - returning 0\n");
            return 0;
        } else {
            debug(29, 4) ("authenticateNTLMHelperServerAvailable: not starving - returning 1\n");
            return 1;
        }
    }

    debug(29, 4) ("authenticateNTLMHelperServerAvailable: no state data - returning 0\n");
    return 0;
}

static void
authenticateNTLMHelperServerOnEmpty(void *data)
{
    ntlm_helper_state_t *statedata = static_cast<ntlm_helper_state_t *>(data);

    if (statedata == NULL)
        return;

    if (statedata->starve) {
        /* we have been starving the helper */
        debug(29, 9) ("authenticateNTLMHelperServerOnEmpty: resetting challenge details\n");
        statedata->starve = 0;
        statedata->challengeuses = 0;
        statedata->renewed = 0;
        xfree(statedata->challenge);
        statedata->challenge = NULL;
    }
}


/* clear the NTLM helper of being reserved for future requests */
static void
authenticateNTLMReleaseServer(auth_user_request_t * auth_user_request)
{
    AuthNTLMUserRequest *ntlm_request;
    assert(auth_user_request->user()->auth_type == AUTH_NTLM);
    ntlm_request = dynamic_cast< AuthNTLMUserRequest *>(auth_user_request);
    assert (ntlm_request);
    debug(29, 9) ("authenticateNTLMReleaseServer: releasing server '%p'\n", ntlm_request->authserver);
    helperStatefulReleaseServer(ntlm_request->authserver);
    ntlm_request->authserver = NULL;
}

/* clear any connection related authentication details */
void
AuthNTLMUserRequest::onConnectionClose(ConnStateData *conn)
{
    assert(conn != NULL);

    if (conn->auth_user_request != NULL) {
        assert (conn->auth_user_request == this);
        assert(this->conn == conn);

        if (authserver != NULL && authserver_deferred)
            authenticateNTLMReleaseServer(this);

        /* unlock the connection based lock */
        debug(29, 9) ("authenticateNTLMOnCloseConnection: Unlocking auth_user from the connection.\n");

        /* This still breaks the abstraction, but is at least read only now.
        * If needed, this could be ignored, as the conn deletion will also unlock
        * the auth user request.
        */
        this->unlock();

        conn->auth_user_request = NULL;
    }
}

/* NTLMLastHeader: return a pointer to the last header used in authenticating
 * the request/conneciton
 */
const char *
AuthNTLMUserRequest::connLastHeader()
{
    return ntlmauthenticate;
}

/*
 * Decode an NTLM [Proxy-]Auth string, placing the results in the passed
 * Auth_user structure.
 */
AuthUserRequest *
