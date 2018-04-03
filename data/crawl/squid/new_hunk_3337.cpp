}

/* Negotiate Scheme */

void
AuthNegotiateConfig::fixHeader(AuthUserRequest::Pointer auth_user_request, HttpReply *rep, http_hdr_type reqType, HttpRequest * request)
{
    AuthNegotiateUserRequest *negotiate_request;

