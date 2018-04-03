authenticateNTLMFixErrorHeader(auth_user_request_t * auth_user_request, HttpReply * rep, http_hdr_type type, request_t * request)
{
    ntlm_request_t *ntlm_request;
    if (ntlmConfig->authenticate) {
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
	    ntlm_request = static_cast< ntlm_request_t *>(auth_user_request->scheme_data);
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
		break;
	    default:
		debug(29, 0) ("authenticateNTLMFixErrorHeader: state %d.\n", ntlm_request->auth_state);
		fatal("unexpected state in AuthenticateNTLMFixErrorHeader.\n");
	    }
	}
    }
}

static void
authNTLMRequestFree(ntlm_request_t * ntlm_request)
{
    if (!ntlm_request)
	return;
    if (ntlm_request->ntlmnegotiate)
	xfree(ntlm_request->ntlmnegotiate);
    if (ntlm_request->authchallenge)
	xfree(ntlm_request->authchallenge);
    if (ntlm_request->ntlmauthenticate)
	xfree(ntlm_request->ntlmauthenticate);
    if (ntlm_request->authserver != NULL && ntlm_request->authserver_deferred) {
	debug(29, 9) ("authenticateNTLMRequestFree: releasing server '%p'\n", ntlm_request->authserver);
	helperStatefulReleaseServer(ntlm_request->authserver);
	ntlm_request->authserver = NULL;
    }
    memPoolFree(ntlm_request_pool, ntlm_request);
}

static void
authNTLMAURequestFree(auth_user_request_t * auth_user_request)
{
    if (auth_user_request->scheme_data)
	authNTLMRequestFree(static_cast< ntlm_request_t *>(auth_user_request->scheme_data));
    auth_user_request->scheme_data = NULL;
}

