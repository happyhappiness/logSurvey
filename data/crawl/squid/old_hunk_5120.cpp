}

void
authenticateBasicFixErrorHeader(auth_user_request_t * auth_user_request, HttpReply * rep, http_hdr_type type, HttpRequest * request)
{
    if (basicConfig->authenticate) {
        debug(29, 9) ("authenticateFixErrorHeader: Sending type:%d header: 'Basic realm=\"%s\"'\n", type, basicConfig->basicAuthRealm);
        httpHeaderPutStrf(&rep->header, type, "Basic realm=\"%s\"", basicConfig->basicAuthRealm);
    }
}

/* free any allocated configuration details */
void
authBasicFreeConfig(authScheme * scheme)
{
    if (basicConfig == NULL)
        return;

    assert(basicConfig == scheme->scheme_data);

    if (basicConfig->authenticate)
        wordlistDestroy(&basicConfig->authenticate);

    if (basicConfig->basicAuthRealm)
        safe_free(basicConfig->basicAuthRealm);

    xfree(basicConfig);

    basicConfig = NULL;
}

void
authenticateBasicFreeUser(auth_user_t * auth_user)
{
    basic_data *basic_auth = static_cast<basic_data *>(auth_user->scheme_data);
    debug(29, 5) ("authenticateBasicFreeUser: Clearing Basic scheme data\n");

    if (basic_auth->username)
        xfree(basic_auth->username);

    if (basic_auth->passwd)
        xfree(basic_auth->passwd);

    memPoolFree(basic_data_pool, auth_user->scheme_data);

    auth_user->scheme_data = NULL;
}

static void
authenticateBasicHandleReply(void *data, char *reply)
{
    AuthenticateStateData *r = static_cast<AuthenticateStateData *>(data);
    auth_user_t *auth_user;
    basic_data *basic_auth;
    BasicAuthQueueNode *tmpnode;
    char *t = NULL;
    void *cbdata;
