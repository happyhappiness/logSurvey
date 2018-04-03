	    auth_user->ipaddr = checklist->src_addr;
	    /* copy username to request for logging on client-side */
	    xstrncpy(checklist->request->user_ident, user, USER_IDENT_SZ);
	    return aclMatchUser(data, user);
	} else {
	    /* user has switched to another IP addr */
	    debug(28, 1) ("aclMatchProxyAuth: user '%s' has changed IP address\n", user);
