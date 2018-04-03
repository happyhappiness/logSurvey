    checklist->state[ACL_PROXY_AUTH] = ACL_LOOKUP_DONE;
    if (result != NULL)
	fatal("AclLookupProxyAuthDone: Old code floating around somewhere.\nMake clean and if that doesn't work, report a bug to the squid developers.\n");
    auth_user_request = checklist->auth_user_request;
    if (!authenticateValidateUser(auth_user_request) || checklist->conn == NULL) {
	/* credentials could not be checked either way
	 * restart the whole process */
	/* OR the connection was closed, there's no way to continue */
	checklist->conn->auth_user_request = NULL;
	checklist->conn->auth_type = AUTH_BROKEN;
	checklist->auth_user_request = NULL;
