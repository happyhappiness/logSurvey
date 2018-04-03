    ntlm_user_t *ntlm_user;
    ntlm_request_t *ntlm_request;
    debug(29, 9) ("authenticateNTLMHandleReply: Helper: '%p' {%s}\n", lastserver, reply ? reply : "<NULL>");

    if (!cbdataReferenceValid(r->data)) {
        debug(29, 1) ("AuthenticateNTLMHandleReply: invalid callback data. Releasing helper '%p'.\n", lastserver);
        cbdataReferenceDone(r->data);
        authenticateStateFree(r);
        debug(29, 9) ("NTLM HandleReply, telling stateful helper : %d\n", S_HELPER_RELEASE);
        return S_HELPER_RELEASE;
    }

    if (!reply) {
        /*
         * TODO: this occurs when a helper crashes. We should clean
         * up that helpers resources and queued requests.
         */
        fatal("authenticateNTLMHandleReply: called with no result string\n");
    }

    /* seperate out the useful data */
    if (strncasecmp(reply, "TT ", 3) == 0) {
        reply += 3;
        /* we have been given a Challenge */
        /* we should check we weren't given an empty challenge */
        /* copy the challenge to the state data */
        helperstate = static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(static_cast<helper_stateful_server *>(lastserver)));

        if (helperstate == NULL)
            fatal("lost NTLM helper state! quitting\n");

        helperstate->challenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);

        helperstate->challengeuses = 0;

        helperstate->renewed = squid_curtime;

        /* and we satisfy the request that happended on the refresh boundary */
        /* note this code is now in two places FIXME */
        assert(r->auth_user_request != NULL);

        assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);

        auth_user_request = r->auth_user_request;

        ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);

        assert(ntlm_request != NULL);

        result = S_HELPER_DEFER;

        /* reserve the server for future authentication */
        ntlm_request->authserver_deferred = 1;

        debug(29, 9) ("authenticateNTLMHandleReply: helper '%p'\n", lastserver);

        assert(ntlm_request->auth_state == AUTHENTICATE_STATE_NEGOTIATE);

        ntlm_request->authserver = static_cast<helper_stateful_server *>(lastserver);

        ntlm_request->authchallenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);
    } else if (strncasecmp(reply, "AF ", 3) == 0) {
        /* we're finished, release the helper */
        reply += 3;
        assert(r->auth_user_request != NULL);
        assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
        auth_user_request = r->auth_user_request;
        assert(auth_user_request->scheme_data != NULL);
        ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);
        auth_user = auth_user_request->auth_user;
        ntlm_user = static_cast<ntlm_user_t *>(auth_user_request->auth_user->scheme_data);
        assert(ntlm_user != NULL);
        result = S_HELPER_RELEASE;
        /* we only expect OK when finishing the handshake */
        assert(ntlm_request->auth_state == AUTHENTICATE_STATE_RESPONSE);
        ntlm_user->username = xstrndup(reply, MAX_LOGIN_SZ);
        ntlm_request->authserver = NULL;
#ifdef NTLM_FAIL_OPEN

    } else if (strncasecmp(reply, "LD ", 3) == 0) {
        /* This is a variant of BH, which rather than deny access
         * allows the user through. The helper is starved and then refreshed
         * via YR, all pending authentications are likely to fail also.
         * It is meant for those helpers which occasionally fail for
         * no reason at all (casus belli, NTLMSSP helper on NT domain,
         * failing about 1 auth out of 1k.
         * The code is a merge from the BH case with snippets of the AF
         * case */
        /* AF code: mark user as authenticated */
        reply += 3;
        assert(r->auth_user_request != NULL);
        assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
        auth_user_request = r->auth_user_request;
        assert(auth_user_request->scheme_data != NULL);
        ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);
        auth_user = auth_user_request->auth_user;
        ntlm_user = static_cast<ntlm_user_t *>(auth_user_request->auth_user->scheme_data);
        assert(ntlm_user != NULL);
        result = S_HELPER_RELEASE;
        /* we only expect LD when finishing the handshake */
        assert(ntlm_request->auth_state == AUTHENTICATE_STATE_RESPONSE);
        ntlm_user->username = xstrndup(reply, MAX_LOGIN_SZ);
        helperstate = helperStatefulServerGetData(ntlm_request->authserver);
        ntlm_request->authserver = NULL;
        /* BH code: mark helper as broken */
        /* mark it for starving */
        helperstate->starve = 1;
#endif

    } else if (strncasecmp(reply, "NA ", 3) == 0) {
        /* TODO: only work with auth_user here if it exists */
        assert(r->auth_user_request != NULL);
        assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
        auth_user_request = r->auth_user_request;
        auth_user = auth_user_request->auth_user;
        assert(auth_user != NULL);
        ntlm_user = static_cast<ntlm_user_t *>(auth_user->scheme_data);
        ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);
        assert((ntlm_user != NULL) && (ntlm_request != NULL));
        /* todo: action of Negotiate state on error */
        result = S_HELPER_RELEASE;	/*some error has occured. no more requests */
        ntlm_request->authserver = NULL;
        debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);
        ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;

        if ((t = strchr(reply, ' ')))	/* strip after a space */
            *t = '\0';
    } else if (strncasecmp(reply, "NA", 2) == 0) {
        /* NTLM Helper protocol violation! */
        fatal("NTLM Helper returned invalid response \"NA\" - a error message MUST be attached\n");
    } else if (strncasecmp(reply, "BH ", 3) == 0) {
        /* TODO kick off a refresh process. This can occur after a YR or after
         * a KK. If after a YR release the helper and resubmit the request via 
         * Authenticate NTLM start. 
         * If after a KK deny the user's request w/ 407 and mark the helper as 
         * Needing YR. */
        assert(r->auth_user_request != NULL);
        assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
        auth_user_request = r->auth_user_request;
        auth_user = auth_user_request->auth_user;
        assert(auth_user != NULL);
        ntlm_user = static_cast<ntlm_user_t *>(auth_user->scheme_data);
        ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);
        assert((ntlm_user != NULL) && (ntlm_request != NULL));
        result = S_HELPER_RELEASE;	/*some error has occured. no more requests for
        				                					 * this helper */
        assert(ntlm_request->authserver ? ntlm_request->authserver == lastserver : 1);
        helperstate = static_cast<ntlm_helper_state_t *>(helperStatefulServerGetData(ntlm_request->authserver));
        ntlm_request->authserver = NULL;

        if (ntlm_request->auth_state == AUTHENTICATE_STATE_NEGOTIATE) {
            /* The helper broke on YR. It automatically
             * resets */
            debug(29, 1) ("authenticateNTLMHandleReply: Error obtaining challenge from helper: %p. Error returned '%s'\n", lastserver, reply);
            /* mark it for starving */
            helperstate->starve = 1;
            /* resubmit the request. This helper is currently busy, so we will get
             * a different one. Our auth state stays the same */
            authenticateNTLMStart(auth_user_request, r->handler, r->data);
            /* don't call the callback */
            cbdataReferenceDone(r->data);
            authenticateStateFree(r);
            debug(29, 9) ("NTLM HandleReply, telling stateful helper : %d\n", result);
            return result;
        }

        /* the helper broke on a KK */
        /* first the standard KK stuff */
        debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);

        if ((t = strchr(reply, ' ')))	/* strip after a space */
            *t = '\0';

        /* now we mark the helper for resetting. */
        helperstate->starve = 1;

        ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
    } else {
        /* TODO: only work with auth_user here if it exists */
        /* TODO: take the request state into consideration */
        assert(r->auth_user_request != NULL);
        assert(r->auth_user_request->auth_user->auth_type == AUTH_NTLM);
        auth_user_request = r->auth_user_request;
        auth_user = auth_user_request->auth_user;
        assert(auth_user != NULL);
        ntlm_user = static_cast<ntlm_user_t *>(auth_user->scheme_data);
        ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);
        assert((ntlm_user != NULL) && (ntlm_request != NULL));
        debug(29, 1) ("authenticateNTLMHandleReply: *** Unsupported helper response ***, '%s'\n", reply);
        /* **** NOTE THIS CODE IS EFFECTIVELY UNTESTED **** */
        /* restart the authentication process */
        ntlm_request->auth_state = AUTHENTICATE_STATE_NONE;
        assert(ntlm_request->authserver ? ntlm_request->authserver == lastserver : 1);
        ntlm_request->authserver = NULL;
    }

    r->handler(r->data, NULL);
    cbdataReferenceDone(r->data);
    authenticateStateFree(r);
