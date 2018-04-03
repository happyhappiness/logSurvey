    hash_join(proxy_auth_cache, (hash_link *) proxy_auth_hash);
}


static int
authNTLMAuthenticated(auth_user_request_t * auth_user_request)
{
    ntlm_request_t *ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);

    if (ntlm_request->auth_state == AUTHENTICATE_STATE_DONE)
        return 1;

    debug(29, 9) ("User not fully authenticated.\n");

    return 0;
}

static void
authenticateNTLMAuthenticateUser(auth_user_request_t * auth_user_request, request_t * request, ConnStateData * conn, http_hdr_type type)
{
