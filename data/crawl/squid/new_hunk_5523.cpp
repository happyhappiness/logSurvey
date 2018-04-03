
}

void *
AuthUser::operator new (unsigned int byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (AuthUser));
    if (!pool)
	pool = memPoolCreate("Authenticate User Data", sizeof (auth_user_t));
    return static_cast<auth_user_t *> (memPoolAlloc(pool));
}

AuthUser::AuthUser (const char *scheme) :
auth_type (AUTH_UNKNOWN), auth_module (authenticateAuthSchemeId(scheme) + 1),
usernamehash (NULL), ipcount (0), expiretime (0), references (0), scheme_data (NULL)
{
    proxy_auth_list.head = proxy_auth_list.tail = NULL;
    proxy_match_cache.head = proxy_match_cache.tail = NULL;
    ip_list.head = ip_list.tail = NULL;
    requests.head = requests.tail = NULL;
}

char const *
AuthUser::username () const
{
    if (auth_module <= 0)
	return NULL;
    return authscheme_list[auth_module - 1].authUserUsername(this);
}

auth_user_t *
authenticateAuthUserNew(const char *scheme)
{
    return new AuthUser (scheme);
}

void *
AuthUserRequest::operator new (unsigned int byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (AuthUserRequest));
    if (!pool)
	pool = memPoolCreate("Authenticate Request Data", sizeof(auth_user_request_t));
    return static_cast<auth_user_request_t *>(memPoolAlloc(pool));
}

void
AuthUserRequest::operator delete (void *address)
{
    memPoolFree(pool, address);
}

AuthUserRequest::AuthUserRequest():auth_user(NULL), scheme_data (NULL), message(NULL),
  references (0), lastReply (AUTH_ACL_CANNOT_AUTHENTICATE)
{
}
 
AuthUserRequest::~AuthUserRequest()
{
    dlink_node *link;
    debug(29, 5) ("AuthUserRequest::~AuthUserRequest: freeing request %p\n", this);
    assert(references == 0);
    if (auth_user) {
	if (scheme_data != NULL) {
	    /* we MUST know the module */
	    assert(auth_user->auth_module > 0);
	    /* and the module MUST support requestFree if it has created scheme data */
	    assert(authscheme_list[auth_user->auth_module - 1].requestFree != NULL);
	    authscheme_list[auth_user->auth_module - 1].requestFree(this);
	}
	/* unlink from the auth_user struct */
	link = auth_user->requests.head;
	while (link && (link->data != this))
	    link = link->next;
	assert(link != NULL);
	dlinkDelete(link, &auth_user->requests);
	dlinkNodeDelete(link);

	/* unlock the request structure's lock */
	authenticateAuthUserUnlock(auth_user);
	auth_user = NULL;
    } else
	assert(scheme_data == NULL);
    safe_free (message);
}

void
AuthUserRequest::setDenyMessage (char const *aString)
{
    safe_free (message);
    message = xstrdup (aString);
}

char const *
AuthUserRequest::getDenyMessage ()
{
    return message;
}

char const *
authenticateAuthUserRequestMessage(auth_user_request_t * auth_user_request)
{
    if (auth_user_request)
	return auth_user_request->getDenyMessage();
    return NULL;
}

void
authenticateSetDenyMessage (auth_user_request_t * auth_user_request, char const *message)
{
    auth_user_request->setDenyMessage (message);
}

static void
authenticateAuthUserRequestSetIp(auth_user_request_t * auth_user_request, struct in_addr ipaddr)
{
