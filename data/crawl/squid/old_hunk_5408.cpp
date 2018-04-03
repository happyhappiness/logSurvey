
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
    char const *MatchParam)
{
    int matchrv;
    acl_proxy_auth_match_cache *auth_match;
    dlink_node *link;
    link = cache->head;
    while (link) {
	auth_match = (acl_proxy_auth_match_cache *)link->data;
	if (auth_match->acl_data == data) {
	    debug(28, 4) ("aclCacheMatchAcl: cache hit on acl '%p'\n", data);
	    return auth_match->matchrv;
	}
	link = link->next;
    }
    auth_match = NULL;
    /* match the user in the acl. They are not cached. */
    switch (acltype) {
    case ACL_PROXY_AUTH:
	matchrv = ((ACLUserData *)data)->match(MatchParam);
	break;
    case ACL_PROXY_AUTH_REGEX:
	matchrv = aclMatchRegex((relist *)data, MatchParam);
	break;
    default:
	/* This is a fatal to ensure that aclCacheMatchAcl calls are _only_
	 * made for supported acl types */
	fatal("aclCacheMatchAcl: unknown or unexpected ACL type");
	return 0;		/* NOTREACHED */
    }
    auth_match = (acl_proxy_auth_match_cache *)memAllocate(MEM_ACL_PROXY_AUTH_MATCH);
    auth_match->matchrv = matchrv;
    auth_match->acl_data = data;
    dlinkAddTail(auth_match, &auth_match->link, cache);
    return matchrv;
}

void
