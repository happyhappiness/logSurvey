    if (!request->flags.proxy_keepalive)
        return;

    if (!authenticate)
        return;

    /* New request, no user details */
    if (auth_user_request == NULL) {
        debug(29, 9) ("AuthNTLMConfig::fixHeader: Sending type:%d header: 'NTLM'\n", type);
        httpHeaderPutStrf(&rep->header, type, "NTLM");

        if (!keep_alive) {
            /* drop the connection */
            httpHeaderDelByName(&rep->header, "keep-alive");
            request->flags.proxy_keepalive = 0;
        }
    } else {
        ntlm_request = dynamic_cast<AuthNTLMUserRequest *>(auth_user_request);

        switch (ntlm_request->auth_state) {

        case AUTHENTICATE_STATE_FAILED:
            /* here it makes sense to drop the connection, as auth is
             * tied to it, even if MAYBE the client could handle it - Kinkie */
            httpHeaderDelByName(&rep->header, "keep-alive");
            request->flags.proxy_keepalive = 0;
            /* fall through */

        case AUTHENTICATE_STATE_FINISHED:
            /* Special case: authentication finished OK but disallowed by ACL.
             * Need to start over to give the client another chance.
             */
            /* fall through */

        case AUTHENTICATE_STATE_NONE:
            /* semantic change: do not drop the connection.
             * 2.5 implementation used to keep it open - Kinkie */
            debug(29, 9) ("AuthNTLMConfig::fixHeader: Sending type:%d header: 'NTLM'\n", type);
            httpHeaderPutStrf(&rep->header, type, "NTLM");
            break;

        case AUTHENTICATE_STATE_IN_PROGRESS:
            /* we're waiting for a response from the client. Pass it the blob */
            debug(29, 9) ("AuthNTLMConfig::fixHeader: Sending type:%d header: 'NTLM %s'\n", type, ntlm_request->server_blob);
            httpHeaderPutStrf(&rep->header, type, "NTLM %s", ntlm_request->server_blob);
            request->flags.must_keepalive = 1;
            safe_free(ntlm_request->server_blob);
            break;


        default:
            debug(29, 0) ("AuthNTLMConfig::fixHeader: state %d.\n", ntlm_request->auth_state);
            fatal("unexpected state in AuthenticateNTLMFixErrorHeader.\n");
        }
    }
}

NTLMUser::~NTLMUser()
{
    debug(29, 5) ("NTLMUser::~NTLMUser: doing nothing to clearNTLM scheme data for '%p'\n",this);
}

static stateful_helper_callback_t
authenticateNTLMHandleReply(void *data, void *lastserver, char *reply)
{
    authenticateStateData *r = static_cast<authenticateStateData *>(data);

    int valid;
    stateful_helper_callback_t result = S_HELPER_UNKNOWN;
    char *blob;

    auth_user_request_t *auth_user_request;
    AuthUser *auth_user;
    NTLMUser *ntlm_user;
    AuthNTLMUserRequest *ntlm_request;

    debug(29, 8) ("authenticateNTLMHandleReply: helper: '%p' sent us '%s'\n", lastserver, reply ? reply : "<NULL>");
    valid = cbdataReferenceValid(data);

    if (!valid) {
        debug(29, 1) ("authenticateNTLMHandleReply: invalid callback data. Releasing helper '%p'.\n", lastserver);
        cbdataReferenceDone(r->data);
        authenticateStateFree(r);
        debug(29, 9) ("authenticateNTLMHandleReply: telling stateful helper : %d\n", S_HELPER_RELEASE);
        return S_HELPER_RELEASE;
    }

