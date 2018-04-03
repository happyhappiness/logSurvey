}

void
ntlm_request_t::authenticate(request_t * request, ConnStateData::Pointer conn, http_hdr_type type)
{
    fatal ("unusable");
}

static void
authenticateNTLMAuthenticateUser(auth_user_request_t * auth_user_request, request_t * request, ConnStateData::Pointer conn, http_hdr_type type)
{
    const char *proxy_auth;

