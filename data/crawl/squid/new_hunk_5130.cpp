}

void
AuthNTLMUserRequest::authenticate(HttpRequest * request, ConnStateData::Pointer conn, http_hdr_type type)
{
    const char *proxy_auth;

    struct ProxyAuthCachePointer *proxy_auth_hash = NULL;
    auth_user_hash_pointer *usernamehash;
    /* TODO: rename this!! */
    auth_user_t *auth_user;
    AuthNTLMUserRequest *ntlm_request;
    ntlm_user_t *ntlm_user;
    LOCAL_ARRAY(char, ntlmhash, NTLM_CHALLENGE_SZ * 2);
    /* get header */
    proxy_auth = httpHeaderGetStr(&request->header, type);

    auth_user = user();
    assert(auth_user);
    assert(auth_user->auth_type == AUTH_NTLM);
    ntlm_user = dynamic_cast<ntlm_user_t *>(auth_user);
    ntlm_request = this;
    assert (ntlm_request);
    /* Check that we are in the client side, where we can generate
     * auth challenges */
