    hash_join(proxy_auth_cache, (hash_link *) proxy_auth_hash);
}

int
ntlm_request_t::authenticated() const
{
    if (auth_state == AUTHENTICATE_STATE_DONE)
        return 1;

    debug(29, 9) ("User not fully authenticated.\n");

    return 0;
}

void
ntlm_request_t::authenticate(request_t * request, ConnStateData * conn, http_hdr_type type)
{
    fatal ("unusable");
}

static void
authenticateNTLMAuthenticateUser(auth_user_request_t * auth_user_request, request_t * request, ConnStateData * conn, http_hdr_type type)
{
