    if (!request->flags.proxy_keepalive)
        return;

    if (authenticate) {
        /* New request, no user details */

        if (auth_user_request == NULL) {
            debug(29, 9) ("authenticateNTLMFixErrorHeader: Sending type:%d header: 'NTLM'\n", type);
            httpHeaderPutStrf(&rep->header, type, "NTLM");
            /* drop the connection */
            httpHeaderDelByName(&rep->header, "keep-alive");
            /* NTLM has problems if the initial connection is not dropped
             * I haven't checked the RFC compliance of this hack - RBCollins */
            request->flags.proxy_keepalive = 0;
        } else {
            ntlm_request = dynamic_cast< AuthNTLMUserRequest *>(auth_user_request);
            assert (ntlm_request);

            switch (ntlm_request->auth_state) {

            case AUTHENTICATE_STATE_NONE:

            case AUTHENTICATE_STATE_FAILED:
                debug(29, 9) ("authenticateNTLMFixErrorHeader: Sending type:%d header: 'NTLM'\n", type);
                httpHeaderPutStrf(&rep->header, type, "NTLM");
                /* drop the connection */
                httpHeaderDelByName(&rep->header, "keep-alive");
                /* NTLM has problems if the initial connection is not dropped
                 * I haven't checked the RFC compliance of this hack - RBCollins */
                request->flags.proxy_keepalive = 0;
                break;

            case AUTHENTICATE_STATE_CHALLENGE:
                /* we are 'waiting' for a response */
                /* pass the challenge to the client */
                debug(29, 9) ("authenticateNTLMFixErrorHeader: Sending type:%d header: 'NTLM %s'\n", type, ntlm_request->authchallenge);
                httpHeaderPutStrf(&rep->header, type, "NTLM %s", ntlm_request->authchallenge);
                request->flags.must_keepalive = 1;
                break;

            default:
                debug(29, 0) ("authenticateNTLMFixErrorHeader: state %d.\n", ntlm_request->auth_state);
                fatal("unexpected state in AuthenticateNTLMFixErrorHeader.\n");
            }
        }
    }
}

NTLMUser::~NTLMUser()
{
    dlink_node *link, *tmplink;
    ProxyAuthCachePointer *proxy_auth_hash;
    debug(29, 5) ("NTLMUser::~NTLMUser: Clearing NTLM scheme data\n");

    /* were they linked in by one or more proxy-authenticate headers */
    link = proxy_auth_list.head;

    while (link) {
        debug(29, 9) ("authenticateFreeProxyAuthUser: removing proxy_auth hash entry '%p'\n", link->data);
        proxy_auth_hash = static_cast<ProxyAuthCachePointer *>(link->data);
        tmplink = link;
        link = link->next;
        dlinkDelete(tmplink, &proxy_auth_list);
        hash_remove_link(proxy_auth_cache, (hash_link *) proxy_auth_hash);
        /* free the key (usually the proxy_auth header) */
        xfree(proxy_auth_hash->key);
        ntlm_user_hash_pool->free(proxy_auth_hash);
    }

}

static stateful_helper_callback_t
authenticateNTLMHandleplaceholder(void *data, void *lastserver, char *reply)
{
    authenticateStateData *r = static_cast<authenticateStateData *>(data);
    stateful_helper_callback_t result = S_HELPER_UNKNOWN;
    /* we should only be called for placeholder requests - which have no reply string */
    assert(reply == NULL);
    assert(r->auth_user_request);
    /* standard callback stuff */

    if (!cbdataReferenceValid(r->data)) {
        debug(29, 1) ("AuthenticateNTLMHandlePlacheholder: invalid callback data.\n");
        return result;
    }

    /* call authenticateNTLMStart to retry this request */
    debug(29, 9) ("authenticateNTLMHandleplaceholder: calling authenticateNTLMStart\n");

    r->auth_user_request->start(r->handler, r->data);

    cbdataReferenceDone(r->data);

    authenticateStateFree(r);

    return result;
}

static stateful_helper_callback_t
authenticateNTLMHandleReply(void *data, void *lastserver, char *reply)
{
    authenticateStateData *r = static_cast<authenticateStateData *>(data);
    ntlm_helper_state_t *helperstate;
    stateful_helper_callback_t result = S_HELPER_UNKNOWN;
    auth_user_request_t *auth_user_request;
    auth_user_t *auth_user;
    ntlm_user_t *ntlm_user;
    AuthNTLMUserRequest *ntlm_request;
    debug(29, 9) ("authenticateNTLMHandleReply: Helper: '%p' {%s}\n", lastserver, reply ? reply : "<NULL>");

    if (!cbdataReferenceValid(r->data)) {
        debug(29, 1) ("AuthenticateNTLMHandleReply: invalid callback data. Releasing helper '%p'.\n", lastserver);
        cbdataReferenceDone(r->data);
        authenticateStateFree(r);
        debug(29, 9) ("NTLM HandleReply, telling stateful helper : %d\n", S_HELPER_RELEASE);
        return S_HELPER_RELEASE;
    }

