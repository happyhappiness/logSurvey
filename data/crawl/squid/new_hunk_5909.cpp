    return !splayLastResult;
}

/* ACL result caching routines */

/*
 * we lookup an acl's cached results, and if we cannot find the acl being 
 * checked we check it and cache the result. This function is deliberatly 
 * generic to support caching of multiple acl types (but it needs to be more
 * generic still....
 * The Match Param and the cache MUST be tied together by the calling routine.
 * You have been warned :-]
 * Also only Matchxxx that are of the form (void *, void *) can be used.
 * probably some ugly overloading _could_ be done but I'll leave that as an
 * exercise for the reader. Note that caching of time based acl's is not
 * wise due to no expiry occuring to the cache entries until the user expires
 * or a reconfigure takes place. 
 * RBC
 */
static int
aclCacheMatchAcl(dlink_list * cache, squid_acl acltype, void *data,
    char *MatchParam)
{
    int matchrv;
    acl_proxy_auth_match_cache *auth_match;
    dlink_node *link;
    link = cache->head;
    while (link) {
	auth_match = link->data;
	if (auth_match->acl_data == data) {
	    debug(28, 4) ("aclCacheMatchAcl: cache hit on acl '%d'\n",
		data);
	    return auth_match->matchrv;
	}
	link = link->next;
    }
    auth_match = NULL;
    /* match the user in the acl. They are not cached. */
    switch (acltype) {
    case ACL_PROXY_AUTH:
	matchrv = aclMatchUser(data, MatchParam);
	break;
    case ACL_PROXY_AUTH_REGEX:
	matchrv = aclMatchRegex(data, MatchParam);
    default:
	/* This is a fatal to ensure that aclCacheMatchAcl calls are _only_
	 * made for supported acl types */
	fatal("aclCacheMatchAcl: unknown or unexpected ACL type");
	return 0;		/* NOTREACHED */
    }
    auth_match = memAllocate(MEM_ACL_PROXY_AUTH_MATCH);
    auth_match->matchrv = matchrv;
    auth_match->acl_data = data;
    dlinkAddTail(auth_match, &auth_match->link, cache);
    return matchrv;
}

void
aclCacheMatchFlush(dlink_list * cache)
{
    acl_proxy_auth_match_cache *auth_match;
    dlink_node *link, *tmplink;
    link = cache->head;
    while (link) {
	auth_match = link->data;
	tmplink = link;
	link = link->next;
	dlinkDelete(tmplink, cache);
	memFree(auth_match, MEM_ACL_PROXY_AUTH_MATCH);
    }
}

/* aclMatchProxyAuth can return four exit codes:
 * 0 : Authenticated OK, Authorisation for this ACL failed. 
 * 1 : Authenticated OK, Authorisation OK.
 * -1 : send data to an external authenticator
 * -2 : send data to the client
 */
static int
aclMatchProxyAuth(void *data, http_hdr_type headertype,
    auth_user_request_t * auth_user_request, aclCheck_t * checklist, squid_acl acltype)
{
    /* checklist is used to register user name when identified, nothing else */
    const char *proxy_auth;
    /* consistent parameters ? */
    assert(auth_user_request == checklist->auth_user_request);

    /* General program flow in proxy_auth acls
     * 1. Consistency checks: are we getting sensible data
     * 2. Call the authenticate* functions to establish a authenticated user
     * 4. look up the username in acltype (and cache the result against the 
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
    if (((proxy_auth == NULL) && (checklist->conn->auth_type == AUTH_UNKNOWN)) || (checklist->conn->auth_type == AUTH_BROKEN)) {
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
	debug(28, 9) ("aclMatchProxyAuth: This is a new request on FD:%d\n", checklist->conn->fd);
	if ((!checklist->request->auth_user_request) && (checklist->conn->auth_type == AUTH_UNKNOWN)) {
	    /* beginning of a new request check */
	    debug(28, 4) ("aclMatchProxyAuth: no connection authentication type\n");
	    if (!authenticateValidateUser(auth_user_request = authenticateGetAuthUser(proxy_auth))) {
		/* the decode might have left a username for logging, or a message to
		 * the user */
		if (auth_user_request) {
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
		debug(28, 4) ("aclMatchProxyAuth: Aauth user request %d conn-auth user request %d conn type %d authentication failed.\n", auth_user_request, checklist->conn->auth_user_request, checklist->conn->auth_type);
		return -2;
	    }
	}
    }
    /* Clear the reference in the checklist */
    checklist->auth_user_request = NULL;
    if (!authenticateUserAuthenticated(auth_user_request)) {
	/* User not logged in. Log them in */
	authenticateAuthUserRequestSetIp(auth_user_request, checklist->src_addr);
	authenticateAuthenticateUser(auth_user_request, checklist->request, checklist->conn, headertype);
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
	return aclCacheMatchAcl(&auth_user_request->auth_user->proxy_match_cache,
	    acltype, data, authenticateUserRequestUsername(auth_user_request));
    }
    /* this acl check completed */
    authenticateAuthUserRequestUnlock(auth_user_request);
    return 0;
}

static void
aclLookupProxyAuthStart(aclCheck_t * checklist)
{
    auth_user_request_t *auth_user_request;
    assert(checklist->auth_user_request != NULL);	/* this is created for us */
    auth_user_request = checklist->auth_user_request;

    assert(authenticateValidateUser(auth_user_request));
    authenticateStart(auth_user_request, aclLookupProxyAuthDone, checklist);
}

static int
