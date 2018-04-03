        fatal("authenticateNTLMHandleReply: called with no result string\n");
    }

    auth_user_request = r->auth_user_request;
    assert(auth_user_request != NULL);
    ntlm_request = dynamic_cast<AuthNTLMUserRequest *>(auth_user_request);

    assert(ntlm_request->waiting);
    ntlm_request->waiting = 0;
    safe_free(ntlm_request->client_blob);

    auth_user = ntlm_request->user();
    assert(auth_user != NULL);
    assert(auth_user->auth_type == AUTH_NTLM);
    ntlm_user = dynamic_cast<ntlm_user_t *>(auth_user_request->user());

    if (ntlm_request->authserver == NULL)
        ntlm_request->authserver = static_cast<helper_stateful_server*>(lastserver);
    else
        assert(ntlm_request->authserver == lastserver);

    /* seperate out the useful data */
    blob = strchr(reply, ' ');

    while (xisspace(*blob)) {    // trim leading spaces in blob
        blob++;
    }

    if (strncasecmp(reply, "TT ", 3) == 0 && blob != NULL) {
        /* we have been given a blob to send to the client */
        safe_free(ntlm_request->server_blob);
        ntlm_request->server_blob = xstrdup(blob);
        ntlm_request->auth_state = AUTHENTICATE_STATE_IN_PROGRESS;
        auth_user_request->denyMessage("Authenication in progress");
        debug(29, 4) ("authenticateNTLMHandleReply: Need to challenge the client with a server blob '%s'\n", blob);
        result = S_HELPER_RESERVE;
    } else if (strncasecmp(reply, "AF ", 3) == 0 && blob != NULL) {
        /* we're finished, release the helper */
        ntlm_user->username(blob);
        auth_user_request->denyMessage("Login successful");
        safe_free(ntlm_request->server_blob);
        authenticateNTLMReleaseServer(ntlm_request);
        ntlm_request->auth_state = AUTHENTICATE_STATE_FINISHED;

        result = S_HELPER_RELEASE;
        debug(29, 4) ("authenticateNTLMHandleReply: Successfully validated user via NTLM. Username '%s'\n", blob);
    } else if (strncasecmp(reply, "NA ", 3) == 0 && blob != NULL) {
        /* authentication failure (wrong password, etc.) */
        auth_user_request->denyMessage(blob);
        ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
        safe_free(ntlm_request->server_blob);
        authenticateNTLMReleaseServer(ntlm_request);
        result = S_HELPER_RELEASE;
        debug(29, 4) ("authenticateNTLMHandleReply: Failed validating user via NTLM. Error returned '%s'\n", blob);
    } else if (strncasecmp(reply, "BH ", 3) == 0) {
        /* TODO kick off a refresh process. This can occur after a YR or after
         * a KK. If after a YR release the helper and resubmit the request via
         * Authenticate NTLM start.
         * If after a KK deny the user's request w/ 407 and mark the helper as
         * Needing YR. */
        auth_user_request->denyMessage(blob);
        ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
        safe_free(ntlm_request->server_blob);
        authenticateNTLMReleaseServer(ntlm_request);
        result = S_HELPER_RELEASE;
        debug(29, 1) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);
    } else {
        /* protocol error */
        fatalf("authenticateNTLMHandleReply: *** Unsupported helper response ***, '%s'\n", reply);
    }

    r->handler(r->data, NULL);
    cbdataReferenceDone(r->data);
    authenticateStateFree(r);
    debug(29, 9) ("authenticateNTLMHandleReply: telling stateful helper : %d\n", result);
    return result;
}

