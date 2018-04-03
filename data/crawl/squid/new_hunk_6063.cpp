	    auth_user->ipaddr = checklist->src_addr;
	    /* copy username to request for logging on client-side */
	    xstrncpy(checklist->request->user_ident, user, USER_IDENT_SZ);
	    switch(acltype) {
	    case ACL_PROXY_AUTH:
		return aclMatchUser(data, user);
	    case ACL_PROXY_AUTH_REGEX:
		return aclMatchRegex(data, user);
	    default:
		fatal("aclMatchProxyAuth: unknown ACL type");
		return 0; /* NOTREACHED */
	    }
	} else {
	    /* user has switched to another IP addr */
	    debug(28, 1) ("aclMatchProxyAuth: user '%s' has changed IP address\n", user);
