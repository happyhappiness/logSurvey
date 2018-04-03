    ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);
    /* Check that we are in the client side, where we can generate
     * auth challenges */

    if (!conn) {
        ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
        debug(29, 1) ("authenticateNTLMAuthenticateUser: attempt to perform authentication without a connection!\n");
        return;
    }

    switch (ntlm_request->auth_state) {

    case AUTHENTICATE_STATE_NONE:
        /* we've recieved a negotiate request. pass to a helper */
        debug(29, 9) ("authenticateNTLMAuthenticateUser: auth state ntlm none. %s\n", proxy_auth);
        ntlm_request->auth_state = AUTHENTICATE_STATE_NEGOTIATE;
        ntlm_request->ntlmnegotiate = xstrndup(proxy_auth, NTLM_CHALLENGE_SZ + 5);
        conn->auth_type = AUTH_NTLM;
        conn->auth_user_request = auth_user_request;
        ntlm_request->conn = conn;
        /* and lock for the connection duration */
        debug(29, 9) ("authenticateNTLMAuthenticateUser: Locking auth_user from the connection.\n");
        authenticateAuthUserRequestLock(auth_user_request);
        return;
        break;

    case AUTHENTICATE_STATE_NEGOTIATE:
        ntlm_request->auth_state = AUTHENTICATE_STATE_CHALLENGE;
        /* We _MUST_ have the auth challenge by now */
        assert(ntlm_request->authchallenge);
        return;
        break;

    case AUTHENTICATE_STATE_CHALLENGE:
        /* we should have recieved a NTLM challenge. pass it to the same
         * helper process */
        debug(29, 9) ("authenticateNTLMAuthenticateUser: auth state challenge with header %s.\n", proxy_auth);
        /* do a cache lookup here. If it matches it's a successful ntlm
         * challenge - release the helper and use the existing auth_user 
         * details. */

        if (strncmp("NTLM ", proxy_auth, 5) == 0) {
            ntlm_request->ntlmauthenticate = xstrdup(proxy_auth);
        } else {
            fatal("Incorrect scheme in auth header\n");
            /* TODO: more fault tolerance.. reset the auth scheme here */
        }

        /* cache entries have authenticateauthheaderchallengestring */
        snprintf(ntlmhash, sizeof(ntlmhash) - 1, "%s%s",
                 ntlm_request->ntlmauthenticate,
                 ntlm_request->authchallenge);

        /* see if we already know this user's authenticate */
        debug(29, 9) ("aclMatchProxyAuth: cache lookup with key '%s'\n", ntlmhash);

        assert(proxy_auth_cache != NULL);

        proxy_auth_hash = static_cast<ProxyAuthCachePointer *>(hash_lookup(proxy_auth_cache, ntlmhash));

        if (!proxy_auth_hash) {	/* not in the hash table */
            debug(29, 4) ("authenticateNTLMAuthenticateUser: proxy-auth cache miss.\n");
            ntlm_request->auth_state = AUTHENTICATE_STATE_RESPONSE;
            /* verify with the ntlm helper */
        } else {
            debug(29, 4) ("authenticateNTLMAuthenticateUser: ntlm proxy-auth cache hit\n");
            /* throw away the temporary entry */
            ntlm_request->authserver_deferred = 0;
            authenticateNTLMReleaseServer(auth_user_request);
            authenticateAuthUserMerge(auth_user, proxy_auth_hash->auth_user);
            auth_user = proxy_auth_hash->auth_user;
            auth_user_request->auth_user = auth_user;
            ntlm_request->auth_state = AUTHENTICATE_STATE_DONE;
            /* we found one */
            debug(29, 9) ("found matching cache entry\n");
            assert(auth_user->auth_type == AUTH_NTLM);
            /* get the existing entries details */
            ntlm_user = static_cast<ntlm_user_t *>(auth_user->scheme_data);
            debug(29, 9) ("Username to be used is %s\n", ntlm_user->username);
            /* on ntlm auth we do not unlock the auth_user until the
             * connection is dropped. Thank MS for this quirk */
            auth_user->expiretime = current_time.tv_sec;
        }

        return;
        break;

    case AUTHENTICATE_STATE_RESPONSE:
        /* auth-challenge pair cache miss. We've just got the response from the helper */
        /*add to cache and let them through */
        ntlm_request->auth_state = AUTHENTICATE_STATE_DONE;
        /* this connection is authenticated */
        debug(29, 4) ("authenticated\nch    %s\nauth     %s\nauthuser %s\n",
                      ntlm_request->authchallenge,
                      ntlm_request->ntlmauthenticate,
                      ntlm_user->username);
        /* cache entries have authenticateauthheaderchallengestring */
        snprintf(ntlmhash, sizeof(ntlmhash) - 1, "%s%s",
                 ntlm_request->ntlmauthenticate,
                 ntlm_request->authchallenge);
        /* see if this is an existing user with a different proxy_auth
         * string */

        if ((usernamehash = static_cast<AuthUserHashPointer *>(hash_lookup(proxy_auth_username_cache, ntlm_user->username)))
           ) {
            while ((authUserHashPointerUser(usernamehash)->auth_type != auth_user->auth_type) && (usernamehash->next) && !authenticateNTLMcmpUsername(static_cast<ntlm_user_t *>(authUserHashPointerUser(usernamehash)->scheme_data), ntlm_user)
                  )
                usernamehash = static_cast<AuthUserHashPointer*>(usernamehash->next);
            if (authUserHashPointerUser(usernamehash)->auth_type == auth_user->auth_type) {
                /*
                 * add another link from the new proxy_auth to the
                 * auth_user structure and update the information */
                assert(proxy_auth_hash == NULL);
                authenticateProxyAuthCacheAddLink(ntlmhash, authUserHashPointerUser(usernamehash));
                /* we can't seamlessly recheck the username due to the
                 * challenge nature of the protocol. Just free the 
                 * temporary auth_user */
                authenticateAuthUserMerge(auth_user, authUserHashPointerUser(usernamehash));
                auth_user = authUserHashPointerUser(usernamehash);
                auth_user_request->auth_user = auth_user;
            }
        } else {
            /* store user in hash's */
            authenticateUserNameCacheAdd(auth_user);
            authenticateProxyAuthCacheAddLink(ntlmhash, auth_user);
        }

        /* set these to now because this is either a new login from an
         * existing user or a new user */
        auth_user->expiretime = current_time.tv_sec;
        return;
        break;

    case AUTHENTICATE_STATE_DONE:
        fatal("authenticateNTLMAuthenticateUser: unexpect auth state DONE! Report a bug to the squid developers.\n");
        break;

    case AUTHENTICATE_STATE_FAILED:
        /* we've failed somewhere in authentication */
        debug(29, 9) ("authenticateNTLMAuthenticateUser: auth state ntlm failed. %s\n", proxy_auth);
        return;
    }

    return;
}
