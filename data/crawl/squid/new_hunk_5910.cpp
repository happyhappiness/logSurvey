aclLookupProxyAuthDone(void *data, char *result)
{
    aclCheck_t *checklist = data;
    auth_user_request_t *auth_user_request;
    checklist->state[ACL_PROXY_AUTH] = ACL_LOOKUP_DONE;
    if (result != NULL)
	fatal("AclLookupProxyAuthDone: Old code floating around somewhere.\nMake clean and if that doesn't work, report a bug to the squid developers.\n");
    /* state info check */
    assert(checklist->conn != NULL);
    auth_user_request = checklist->auth_user_request;
    if (!authenticateValidateUser(auth_user_request)) {
	/* credentials could not be checked either way
	 * restart the whole process */
	checklist->conn->auth_user_request = NULL;
	checklist->conn->auth_type = AUTH_BROKEN;
	checklist->auth_user_request = NULL;
	authenticateAuthUserRequestUnlock(auth_user_request);
	aclCheck(checklist);
	return;
    }
    aclCheck(checklist);
}
