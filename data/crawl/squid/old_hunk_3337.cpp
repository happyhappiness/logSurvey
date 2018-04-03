}

/* Negotiate Scheme */
/* See AuthUserRequest.cc::authenticateDirection for return values */
int
AuthNegotiateUserRequest::module_direction()
{
    /* null auth_user is checked for by authenticateDirection */

    if (waiting || client_blob)
        return -1; /* need helper response to continue */

    switch (auth_state) {

        /* no progress at all. */

    case AUTHENTICATE_STATE_NONE:
        debugs(29, 1, "AuthNegotiateUserRequest::direction: called before Negotiate Authenticate for request " << this << "!. Report a bug to squid-dev.");
        return -2; /* error */

    case AUTHENTICATE_STATE_FAILED:
        return -2; /* error */


    case AUTHENTICATE_STATE_IN_PROGRESS:
        assert(server_blob);
        return 1; /* send to client */

    case AUTHENTICATE_STATE_DONE:
        return 0; /* do nothing */

    case AUTHENTICATE_STATE_INITIAL:
        debugs(29, 1, "AuthNegotiateUserRequest::direction: Unexpected AUTHENTICATE_STATE_INITIAL");
        return -2;
    }

    return -2;
}

/* add the [proxy]authorisation header */
void
AuthNegotiateUserRequest::addHeader(HttpReply * rep, int accel)
{
    http_hdr_type type;

    if (!server_blob)
        return;

    /* don't add to authentication error pages */

    if ((!accel && rep->sline.status == HTTP_PROXY_AUTHENTICATION_REQUIRED)
            || (accel && rep->sline.status == HTTP_UNAUTHORIZED))
        return;

    type = accel ? HDR_AUTHENTICATION_INFO : HDR_PROXY_AUTHENTICATION_INFO;

    httpHeaderPutStrf(&rep->header, type, "Negotiate %s", server_blob);

    safe_free(server_blob);
}

void
AuthNegotiateConfig::fixHeader(AuthUserRequest *auth_user_request, HttpReply *rep, http_hdr_type reqType, HttpRequest * request)
{
    AuthNegotiateUserRequest *negotiate_request;

