}

void
AuthBasicConfig::fixHeader(auth_user_request_t *auth_user_request, HttpReply *rep, http_hdr_type type, HttpRequest * request)
{
    if (authenticate) {
        debug(29, 9) ("authenticateFixErrorHeader: Sending type:%d header: 'Basic realm=\"%s\"'\n", type, basicAuthRealm);
        httpHeaderPutStrf(&rep->header, type, "Basic realm=\"%s\"", basicAuthRealm);
    }
}

/* free any allocated configuration details */
void
AuthBasicConfig::done()
{
    if (authenticate)
        wordlistDestroy(&authenticate);

    if (basicAuthRealm)
        safe_free(basicAuthRealm);
}

BasicUser::~BasicUser()
{
    if (passwd)
        xfree(passwd);

    safe_free (cleartext);
}

static void
authenticateBasicHandleReply(void *data, char *reply)
{
    AuthenticateStateData *r = static_cast<AuthenticateStateData *>(data);
    BasicAuthQueueNode *tmpnode;
    char *t = NULL;
    void *cbdata;
