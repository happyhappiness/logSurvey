     *     username
     */

    assert(headertype != 0);
    proxy_auth = httpHeaderGetStr(&checklist->request->header, headertype);

    if (checklist->conn == NULL) {
	debug(28, 1) ("aclMatchProxyAuth: no connection data, cannot process authentication\n");
	/*
	 * deny access: clientreadrequest requires conn data, and it is always
	 * compiled in so we should have it too.
	 */
	return 0;
    }
    /*
     * a note on proxy_auth logix here:
     * proxy_auth==NULL -> unauthenticated request || already authenticated connection
     * so we test for an authenticated connection when we recieve no authentication
     * header.
     */
    if (((proxy_auth == NULL) && (!authenticateUserAuthenticated(auth_user_request ? auth_user_request : checklist->conn->auth_user_request)))
	|| (checklist->conn->auth_type == AUTH_BROKEN)) {
	/* no header or authentication failed/got corrupted - restart */
	checklist->conn->auth_type = AUTH_UNKNOWN;
	debug(28, 4) ("aclMatchProxyAuth: broken auth or no proxy_auth header. Requesting auth header.\n");
	/* something wrong with the AUTH credentials. Force a new attempt */
	checklist->auth_user_request = NULL;
	checklist->conn->auth_user_request = NULL;
	if (auth_user_request) {
	    /* unlock the ACL lock */
	    authenticateAuthUserRequestUnlock(auth_user_request);
	}
	return -2;
    }
    /* we have a proxy auth header and as far as we know this connection has
     * not had bungled connection oriented authentication happen on it. */
    debug(28, 9) ("aclMatchProxyAuth: header %s.\n", proxy_auth);
    if (auth_user_request == NULL) {
	debug(28, 9) ("aclMatchProxyAuth: This is a new request on FD:%d\n",
	    checklist->conn->fd);
	if ((!checklist->request->auth_user_request)
	    && (checklist->conn->auth_type == AUTH_UNKNOWN)) {
	    /* beginning of a new request check */
	    debug(28, 4) ("aclMatchProxyAuth: no connection authentication type\n");
	    if (!authenticateValidateUser(auth_user_request =
		    authenticateGetAuthUser(proxy_auth))) {
		/* the decode might have left a username for logging, or a message to
		 * the user */
		if (authenticateUserRequestUsername(auth_user_request)) {
		    /* lock the user for the request structure link */
		    authenticateAuthUserRequestLock(auth_user_request);
		    checklist->request->auth_user_request = auth_user_request;
		    /* unlock the ACL reference. */
		    authenticateAuthUserRequestUnlock(auth_user_request);
		}
		return -2;
	    }
	    /* the user_request comes prelocked for the caller to GetAuthUser (us) */
	} else if (checklist->request->auth_user_request) {
	    auth_user_request = checklist->request->auth_user_request;
	    /* lock the user request for this ACL processing */
	    authenticateAuthUserRequestLock(auth_user_request);
	} else {
	    if (checklist->conn->auth_user_request != NULL) {
		auth_user_request = checklist->conn->auth_user_request;
		/* lock the user request for this ACL processing */
		authenticateAuthUserRequestLock(auth_user_request);
	    } else {
		/* failed connection based authentication */
		debug(28, 4) ("aclMatchProxyAuth: Auth user request %d conn-auth user request %d conn type %d authentication failed.\n",
		    auth_user_request, checklist->conn->auth_user_request,
		    checklist->conn->auth_type);
		return -2;
	    }
	}
    }
    /* Clear the reference in the checklist */
    checklist->auth_user_request = NULL;
    if (!authenticateUserAuthenticated(auth_user_request)) {
	/* User not logged in. Log them in */
	authenticateAuthUserRequestSetIp(auth_user_request,
	    checklist->src_addr);
	authenticateAuthenticateUser(auth_user_request, checklist->request,
	    checklist->conn, headertype);
	switch (authenticateDirection(auth_user_request)) {
	case 1:
	    /* this ACL check is finished. Unlock. */
	    authenticateAuthUserRequestUnlock(auth_user_request);
	    return -2;
	case -1:
	    /* we are partway through authentication within squid
	     * store the auth_user for the callback to here */
	    checklist->auth_user_request = auth_user_request;
	    /* we will be called back here. Do not Unlock */
	    return -1;
	case -2:
	    /* this ACL check is finished. Unlock. */
	    authenticateAuthUserRequestUnlock(auth_user_request);
	    return -2;
	}			/* on 0 the authentication is finished - fallthrough */
	/* See of user authentication failed for some reason */
	if (!authenticateUserAuthenticated(auth_user_request)) {
	    if ((!checklist->rfc931[0]) &&
		(authenticateUserRequestUsername(auth_user_request))) {
		if (!checklist->request->auth_user_request) {
		    /* lock the user for the request structure link */
		    authenticateAuthUserRequestLock(auth_user_request);
		    checklist->request->auth_user_request = auth_user_request;
		}
	    }
	    /* this ACL check is finished. Unlock. */
	    authenticateAuthUserRequestUnlock(auth_user_request);
	    return -2;

	}
    }
    /* User authenticated ok */
    assert(authenticateUserAuthenticated(auth_user_request));

    /* copy username to request for logging on client-side */
    /* the credentials are correct at this point */
    if (!checklist->request->auth_user_request) {
	/* lock the user for the request structure link */
	authenticateAuthUserRequestLock(auth_user_request);
	checklist->request->auth_user_request = auth_user_request;
    }
    if (authenticateCheckAuthUserIP(checklist->src_addr, auth_user_request)) {
	/* Once the match is completed we have finished with the
	 * auth_user structure */
	/* this ACL check completed */
	authenticateAuthUserRequestUnlock(auth_user_request);
	/* check to see if we have matched the user-acl before */
	return aclCacheMatchAcl(&auth_user_request->auth_user->
	    proxy_match_cache, acltype, data,
	    authenticateUserRequestUsername(auth_user_request));
    } else {
	debug(28, 1) ("XXX authenticateCheckAuthUserIP returned 0, somebody "
	    "make sure the username gets logged to access.log.\n");
	debug(28, 1) ("XXX if it works, tell developers to remove this "
	    "message\n");
    }
    /* this acl check completed */
    authenticateAuthUserRequestUnlock(auth_user_request);
    return 0;
}

static void
