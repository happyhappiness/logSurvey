	/* NOTREACHED */
    case ACL_PROXY_AUTH:
    case ACL_PROXY_AUTH_REGEX:
    case ACL_MAX_USER_IP:
	/* ALL authentication predicated ACL's live here */
	if (NULL == r) {
	    return -1;
	} else if (!r->flags.accelerated) {
	    /* Proxy authorization on proxy requests */
	    headertype = HDR_PROXY_AUTHORIZATION;
	} else if (r->flags.internal) {
	    /* WWW authorization on accelerated internal requests */
	    headertype = HDR_AUTHORIZATION;
	} else {
#if AUTH_ON_ACCELERATION
	    /* WWW authorization on accelerated requests */
	    headertype = HDR_AUTHORIZATION;
#else
	    debug(28, 1) ("aclMatchAcl: proxy_auth %s not applicable on accelerated requests.\n", ae->name);
	    return -1;
#endif
	}
	/* get authed here */
	if ((ti = authenticateAuthenticate(&checklist->auth_user_request, headertype, checklist->request, checklist->conn, checklist->src_addr)) != AUTH_AUTHENTICATED) {
	    switch (ti) {
	    case 0:
		/* Authenticated but not Authorised for this ACL */
		debug(28, 4) ("aclMatchAcl: returning  0 user authenticated but not authorised.\n");
		return 0;
	    case 1:
		fatal("AUTH_AUTHENTICATED == 1\n");
		break;
	    case -1:
		/* Send data to the helper */
		debug(28, 4) ("aclMatchAcl: returning 0 sending authentication challenge.\n");
		checklist->state[ACL_PROXY_AUTH] = ACL_LOOKUP_NEEDED;
		return 0;
	    case -2:
		/* Send a challenge to the client */
		debug(28, 4) ("aclMatchAcl: returning 0 sending credentials to helper.\n");
		checklist->state[ACL_PROXY_AUTH] = ACL_PROXY_AUTH_NEEDED;
		return 0;
	    }
	}
	/* then, switch on type again to do the correct match routine :> */
	switch (ae->type) {
	case ACL_PROXY_AUTH:
	case ACL_PROXY_AUTH_REGEX:
	    ti = aclMatchProxyAuth(ae->data, headertype,
		checklist->auth_user_request, checklist, ae->type);
	    break;
	case ACL_MAX_USER_IP:
	    ti = aclMatchUserMaxIP(ae->data, checklist->auth_user_request,
		checklist->src_addr);
	    break;
	default:
	    /* Keep GCC happy */
	    break;
	}
	checklist->auth_user_request = NULL;
	/* Check the credentials */
	switch (ti) {
	case 0:
	    debug(28, 4) ("aclMatchAcl: returning  0 user authenticated but not authorised.\n");
	    /* Authenticated but not Authorised for this ACL */
	    return 0;
	case 1:
	    debug(28, 4) ("aclMatchAcl: returning  1 user authenticated and authorised.\n");
	    /* Authenticated and Authorised for this ACL */
	    return 1;
	case -2:
	case -1:
	    fatal("Invalid response from match routine\n");
	    break;
	}
	/* NOTREACHED */
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
	return aclMatchWordList(ae->data, checklist->snmp_community);
#endif
    case ACL_SRC_ASN:
	return asnMatchIp(ae->data, checklist->src_addr);
    case ACL_DST_ASN:
	ia = ipcache_gethostbyname(r->host, IP_LOOKUP_IF_MISS);
	if (ia) {
