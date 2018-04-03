}

void
ntlm_request_t::authenticate(HttpRequest * request, ConnStateData::Pointer conn, http_hdr_type type)
{
    fatal ("unusable");
}

static void
authenticateNTLMAuthenticateUser(auth_user_request_t * auth_user_request, HttpRequest * request, ConnStateData::Pointer conn, http_hdr_type type)
{
    const char *proxy_auth;

    struct ProxyAuthCachePointer *proxy_auth_hash = NULL;
    auth_user_hash_pointer *usernamehash;
    auth_user_t *auth_user;
    ntlm_request_t *ntlm_request;
    ntlm_user_t *ntlm_user;
    LOCAL_ARRAY(char, ntlmhash, NTLM_CHALLENGE_SZ * 2);
    /* get header */
    proxy_auth = httpHeaderGetStr(&request->header, type);

    auth_user = auth_user_request->auth_user;
    assert(auth_user);
    assert(auth_user->auth_type == AUTH_NTLM);
    assert(auth_user->scheme_data != NULL);
    ntlm_user = static_cast<ntlm_user_t *>(auth_user->scheme_data);
    ntlm_request = dynamic_cast< ntlm_request_t *>(auth_user_request->state());
    assert (ntlm_request);
    /* Check that we are in the client side, where we can generate
     * auth challenges */
