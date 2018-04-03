
    debug(29, 9) ("authenticateBasicDecodeAuth: cleartext = '%s'\n", cleartext);

    username(xstrndup(cleartext, USER_IDENT_SZ));
    xfree(cleartext);
    /* terminate the username string */

    if ((cleartext = strchr(username(), ':')) != NULL)
        *(cleartext)++ = '\0';
}

void
BasicUser::extractPassword()
{
    passwd = cleartext;

    if (cleartext == NULL) {
        debug(29, 4) ("authenticateBasicDecodeAuth: no password in proxy authorization header '%s'\n",
                      httpAuthHeader);
        passwd = NULL;
        currentRequest->setDenyMessage ("no password was present in the HTTP [proxy-]authorization header. This is most likely a browser bug");
    } else if (*cleartext == '\0') {
        debug(29, 4) ("authenticateBasicDecodeAuth: Disallowing empty password,"
                      "user is '%s'\n", username());
        passwd = NULL;
        currentRequest->setDenyMessage ("Request denied because you provided an empty password. Users MUST have a password.");
    }

    if (passwd)
        passwd = xstrndup(cleartext, USER_IDENT_SZ);

    cleartext = NULL;
}

void
BasicUser::decode(char const *proxy_auth, AuthUserRequest *auth_user_request)
{
    currentRequest = auth_user_request;
    httpAuthHeader = proxy_auth;
    decodeCleartext ();
    extractUsername();
    extractPassword();
    currentRequest = NULL;
    httpAuthHeader = NULL;
}

bool
BasicUser::valid() const
{
    return passwd != NULL;
}

void
BasicUser::makeLoggingInstance(AuthBasicUserRequest *auth_user_request)
{
    if (username()) {
        /* log the username */
        debug(29, 9) ("authBasicDecodeAuth: Creating new user for logging '%s'\n", username());
        /* new scheme data */
        BasicUser *basic_auth = new BasicUser(& basicConfig);
        auth_user_request->user(basic_auth);
        /* save the credentials */
        basic_auth->username(username());
        username(NULL);
        /* set the auth_user type */
        basic_auth->auth_type = AUTH_BROKEN;
        /* link the request to the user */
        basic_auth->addRequest(auth_user_request);
    }
}

AuthUser *
BasicUser::makeCachedFrom()
{
    /* the user doesn't exist in the username cache yet */
    debug(29, 9) ("authBasicDecodeAuth: Creating new user '%s'\n", username());
    BasicUser *basic_user = new BasicUser(&basicConfig);
    /* save the credentials */
    basic_user->username(username());
    username(NULL);
    basic_user->passwd = passwd;
    passwd = NULL;
    /* set the auth_user type */
    basic_user->auth_type = AUTH_BASIC;
    /* current time for timeouts */
    basic_user->expiretime = current_time.tv_sec;

    /* this basic_user struct is the 'lucky one' to get added to the username cache */
    /* the requests after this link to the basic_user */
    /* store user in hash */
    basic_user->addToNameCache();
    return basic_user;
}

void
BasicUser::updateCached(BasicUser *from)
{
    debug(29, 9) ("authBasicDecodeAuth: Found user '%s' in the user cache as '%p'\n", from->username(), this);

    if (strcmp(from->passwd, passwd)) {
        debug(29, 4) ("authBasicDecodeAuth: new password found. Updating in user master record and resetting auth state to unchecked\n");
        flags.credentials_ok = 0;
        xfree(passwd);
        passwd = from->passwd;
        from->passwd = NULL;
    }

    if (flags.credentials_ok == 3) {
        debug(29, 4) ("authBasicDecodeAuth: last attempt to authenticate this user failed, resetting auth state to unchecked\n");
        flags.credentials_ok = 0;
    }
}

/*
 * Decode a Basic [Proxy-]Auth string, linking the passed
 * auth_user_request structure to any existing user structure or creating one
 * if needed. Note that just returning will be treated as 
 * "cannot decode credentials". Use the message field to return a 
 * descriptive message to the user.
 */
AuthUserRequest *
AuthBasicConfig::decode(char const *proxy_auth)
{
    AuthBasicUserRequest *auth_user_request = new AuthBasicUserRequest();
    /* decode the username */
    /* trim BASIC from string */

    while (!xisspace(*proxy_auth))
        proxy_auth++;

    BasicUser *basic_auth, local_basic(&basicConfig);

    /* Trim leading whitespace before decoding */
    while (xisspace(*proxy_auth))
        proxy_auth++;

    local_basic.decode(proxy_auth, auth_user_request);

    if (!local_basic.valid()) {
        local_basic.makeLoggingInstance(auth_user_request);
        return auth_user_request;
    }

    /* now lookup and see if we have a matching auth_user structure in
     * memory. */

    auth_user_t *auth_user;

    if ((auth_user = authBasicAuthUserFindUsername(local_basic.username())) == NULL) {
        auth_user = local_basic.makeCachedFrom();
        basic_auth = dynamic_cast<BasicUser *>(auth_user);
        assert (basic_auth);
    } else {
        basic_auth = dynamic_cast<BasicUser *>(auth_user);
        assert (basic_auth);
        basic_auth->updateCached (&local_basic);
    }

    /* link the request to the in-cache user */
    auth_user_request->user(basic_auth);

    basic_auth->addRequest(auth_user_request);

    return auth_user_request;
}

/* Initialize helpers and the like for this auth scheme. Called AFTER parsing the
 * config file */
void
AuthBasicConfig::init(AuthConfig * scheme)
{
    static int init = 0;

    if (authenticate) {
        authbasic_initialised = 1;

        if (basicauthenticators == NULL)
            basicauthenticators = helperCreate("basicauthenticator");

        basicauthenticators->cmdline = authenticate;

        basicauthenticators->n_to_start = authenticateChildren;

        basicauthenticators->concurrency = authenticateConcurrency;

        basicauthenticators->ipc_type = IPC_STREAM;

