}
#endif

int
aclAuthenticated(aclCheck_t * checklist)
{
    request_t *r = checklist->request;
    http_hdr_type headertype;
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
	debug(28, 1) ("aclAuthenticated: authentication not applicable on accelerated requests.\n");
	return -1;
#endif
    }
    /* get authed here */
    /* Note: this fills in checklist->auth_user_request when applicable */
    switch (authenticateAuthenticate(&checklist->auth_user_request, headertype, checklist->request, checklist->conn, checklist->src_addr)) {
    case AUTH_ACL_CANNOT_AUTHENTICATE:
	debug(28, 4) ("aclMatchAcl: returning  0 user authenticated but not authorised.\n");
	return 0;
    case AUTH_AUTHENTICATED:
	return 1;
	break;
    case AUTH_ACL_HELPER:
	debug(28, 4) ("aclMatchAcl: returning 0 sending credentials to helper.\n");
	checklist->state[ACL_PROXY_AUTH] = ACL_LOOKUP_NEEDED;
	return 0;
    case AUTH_ACL_CHALLENGE:
	debug(28, 4) ("aclMatchAcl: returning 0 sending authentication challenge.\n");
	checklist->state[ACL_PROXY_AUTH] = ACL_PROXY_AUTH_NEEDED;
	return 0;
    default:
	fatal("unexpected authenticateAuthenticate reply\n");
	return -1;
    }
}

static int
aclMatchAcl(acl * ae, aclCheck_t * checklist)
{
