     *     username
     */

    /* for completeness */
    authenticateAuthUserRequestLock(auth_user_request);

    /* consistent parameters ? */
    assert(authenticateUserAuthenticated(auth_user_request));
    /* this ACL check completed */
    authenticateAuthUserRequestUnlock(auth_user_request);
    /* check to see if we have matched the user-acl before */
    return aclCacheMatchAcl(&auth_user_request->auth_user->
	proxy_match_cache, acltype, data,
	authenticateUserRequestUsername(auth_user_request));
}

CBDATA_TYPE(acl_user_ip_data);

void
aclParseUserMaxIP(void *data)
{
    acl_user_ip_data **acldata = data;
    char *t = NULL;
    CBDATA_INIT_TYPE(acl_user_ip_data);
    if (*acldata) {
	debug(28, 1) ("Attempting to alter already set User max IP acl\n");
	return;
    }
    *acldata = cbdataAlloc(acl_user_ip_data);
    if ((t = strtokFile())) {
	debug(28, 5) ("aclParseUserMaxIP: First token is %s\n", t);
	if (strcmp("-s", t) == 0) {
	    debug(28, 5) ("aclParseUserMaxIP: Going strict\n");
	    (*acldata)->flags.strict = 1;
	} else {
	    (*acldata)->max = atoi(t);
	    debug(28, 5) ("aclParseUserMaxIP: Max IP address's %d\n", (*acldata)->max);
	}
    } else
	fatal("aclParseUserMaxIP: Malformed ACL %d\n");
}

void
aclDestroyUserMaxIP(void *data)
{
    acl_user_ip_data **acldata = data;
    if (*acldata)
	cbdataFree(*acldata);
    *acldata = NULL;
}

wordlist *
aclDumpUserMaxIP(void *data)
{
    acl_user_ip_data *acldata = data;
    wordlist *W = NULL;
    char buf[128];
    if (acldata->flags.strict)
	wordlistAdd(&W, "-s");
    snprintf(buf, sizeof(buf), "%d", acldata->max);
    wordlistAdd(&W, buf);
    return W;
}

/* aclMatchUserMaxIP - check for users logging in from multiple IP's 
 * 0 : No match
 * 1 : Match 
 */
int
aclMatchUserMaxIP(void *data, auth_user_request_t * auth_user_request,
    struct in_addr src_addr)
{
/*
 * > the logic for flush the ip list when the limit is hit vs keep it sorted in most recent access order and just drop the oldest one off is currently undecided
 */
    acl_user_ip_data *acldata = data;

    if (authenticateAuthUserRequestIPCount(auth_user_request) <= acldata->max)
	return 0;

    /* this is a match */
    if (acldata->flags.strict) {
	/* simply deny access - the user name is already associated with
	 * the request 
	 */
	/* remove _this_ ip, as it is the culprit for going over the limit */
	authenticateAuthUserRequestRemoveIp(auth_user_request, src_addr);
	debug(28, 4) ("aclMatchUserMaxIP: Denying access in strict mode\n");
    } else {
	/* non-strict - remove some/all of the cached entries 
	 * ie to allow the user to move machines easily
	 */
	authenticateAuthUserRequestClearIp(auth_user_request);
	debug(28, 4) ("aclMatchUserMaxIP: Denying access in non-strict mode - flushing the user ip cache\n");
    }
    /* We had reports about the username being lost when denying due to 
     * IP limits. That should be fixed in the new lazy-proxy code, but
     * This note note is a reminder!
     */
    debug(28, 1) ("XXX aclMatchUserMaxIP returned 0, somebody "
	"make sure the username gets logged to access.log.\n");
    debug(28, 1) ("XXX if it works, tell developers to remove this "
	"message\n");

    return 1;
}

static void
