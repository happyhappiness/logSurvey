
}

auth_user_t *
authenticateAuthUserNew(const char *scheme)
{
    auth_user_t *temp_auth;
    temp_auth = memAllocate(MEM_AUTH_USER_T);
    assert(temp_auth != NULL);
    memset(temp_auth, '\0', sizeof(auth_user_t));
    temp_auth->auth_type = AUTH_UNKNOWN;
    temp_auth->references = 0;
    temp_auth->auth_module = authenticateAuthSchemeId(scheme) + 1;
    temp_auth->usernamehash = NULL;
    return temp_auth;
}

static auth_user_request_t *
authenticateAuthUserRequestNew(void)
{
    auth_user_request_t *temp_request;
    if (!auth_user_request_pool)
	auth_user_request_pool = memPoolCreate("Authenticate Request Data", sizeof(auth_user_request_t));
    temp_request = memPoolAlloc(auth_user_request_pool);
    assert(temp_request != NULL);
    memset(temp_request, '\0', sizeof(auth_user_request_t));
    return temp_request;
}

static void
authenticateAuthUserRequestFree(auth_user_request_t * auth_user_request)
{
    dlink_node *link;
    debug(29, 5) ("authenticateAuthUserRequestFree: freeing request %p\n", auth_user_request);
    if (!auth_user_request)
	return;
    assert(auth_user_request->references == 0);
    if (auth_user_request->auth_user) {
	if (auth_user_request->scheme_data != NULL) {
	    /* we MUST know the module */
	    assert((auth_user_request->auth_user->auth_module > 0));
	    /* and the module MUST support requestFree if it has created scheme data */
	    assert(authscheme_list[auth_user_request->auth_user->auth_module - 1].requestFree != NULL);
	    authscheme_list[auth_user_request->auth_user->auth_module - 1].requestFree(auth_user_request);
	}
	/* unlink from the auth_user struct */
	link = auth_user_request->auth_user->requests.head;
	while (link && (link->data != auth_user_request))
	    link = link->next;
	assert(link != NULL);
	dlinkDelete(link, &auth_user_request->auth_user->requests);
	dlinkNodeDelete(link);

	/* unlock the request structure's lock */
	authenticateAuthUserUnlock(auth_user_request->auth_user);
	auth_user_request->auth_user = NULL;
    } else
	assert(auth_user_request->scheme_data == NULL);
    if (auth_user_request->message)
	xfree(auth_user_request->message);
    memPoolFree(auth_user_request_pool, auth_user_request);
}

char *
authenticateAuthUserRequestMessage(auth_user_request_t * auth_user_request)
{
    if (auth_user_request)
	return auth_user_request->message;
    return NULL;
}

static void
authenticateAuthUserRequestSetIp(auth_user_request_t * auth_user_request, struct in_addr ipaddr)
{
