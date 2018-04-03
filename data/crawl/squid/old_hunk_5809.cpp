	    return -1;
#endif
	}
	/* Check the credentials */
	switch (aclMatchProxyAuth(ae->data, headertype,
		checklist->auth_user_request, checklist, ae->type)) {
	case 0:
	    debug(28, 4) ("aclMatchAcl: returning  0 user authenticated but not authorised.\n");
	    /* Authenticated but not Authorised for this ACL */
