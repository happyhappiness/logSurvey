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
