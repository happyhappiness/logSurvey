
    debug(29, 9) ("authenticateBasicDecodeAuth: cleartext = '%s'\n", cleartext);

    local_basic.username = xstrndup(cleartext, USER_IDENT_SZ);

    xfree(cleartext);

    if ((cleartext = strchr(local_basic.username, ':')) != NULL)
        *(cleartext)++ = '\0';

    local_basic.passwd = cleartext;

    if (cleartext == NULL) {
        debug(29, 4) ("authenticateBasicDecodeAuth: no password in proxy authorization header '%s'\n",
                      proxy_auth);
        local_basic.passwd = NULL;
        authenticateSetDenyMessage (auth_user_request, "no password was present in the HTTP [proxy-]authorization header. This is most likely a browser bug");
    } else if (*cleartext == '\0') {
        debug(29, 4) ("authenticateBasicDecodeAuth: Disallowing empty password,"
                      "user is '%s'\n", local_basic.username);
        local_basic.passwd = NULL;
        authenticateSetDenyMessage (auth_user_request, "Request denied because you provided an empty password. Users MUST have a password.");
    }

    /* special case: we have to free the strings for user and password
     * if we are not returning a filled out structure 
     */
    if (local_basic.passwd == NULL) {
        if (local_basic.username) {
            /* log the username */
            debug(29, 9) ("authBasicDecodeAuth: Creating new user for logging '%s'\n", local_basic.username);
            /* new auth_user */
            auth_user = authenticateAuthUserNew("basic");
            /* new scheme data */
            basic_auth = authBasicDataNew();
            /* save the credentials */
            basic_auth->username = local_basic.username;
            /* link the scheme data in */
            auth_user->scheme_data = basic_auth;
            /* set the auth_user type */
            auth_user->auth_type = AUTH_BROKEN;
            /* link the request to the user */
            auth_user_request->auth_user = auth_user;
            /* lock for the auth_user_request link */
            authenticateAuthUserLock(auth_user);
            node = dlinkNodeNew();
            dlinkAdd(auth_user_request, node, &auth_user->requests);
        }

        return;
    } else {
        local_basic.passwd = xstrndup(cleartext, USER_IDENT_SZ);
    }

    /* now lookup and see if we have a matching auth_user structure in memory. */

    if ((auth_user = authBasicAuthUserFindUsername(local_basic.username)) == NULL) {
        /* the user doesn't exist in the username cache yet */
        debug(29, 9) ("authBasicDecodeAuth: Creating new user '%s'\n", local_basic.username);
        /* new auth_user */
        auth_user = authenticateAuthUserNew("basic");
        /* new scheme data */
        basic_auth = authBasicDataNew();
        /* save the credentials */
        basic_auth->username = local_basic.username;
        basic_auth->passwd = local_basic.passwd;
        /* link the scheme data in */
        auth_user->scheme_data = basic_auth;
        /* set the auth_user type */
        auth_user->auth_type = AUTH_BASIC;
        /* current time for timeouts */
        auth_user->expiretime = current_time.tv_sec;

        /* this auth_user struct is the 'lucky one' to get added to the username cache */
        /* the requests after this link to the auth_user */
        /* store user in hash */
        authenticateUserNameCacheAdd(auth_user);
    } else {
        debug(29, 9) ("authBasicDecodeAuth: Found user '%s' in the user cache as '%p'\n", local_basic.username, auth_user);
        xfree(local_basic.username);
        basic_auth =  static_cast<basic_data *>(auth_user->scheme_data);

        if (strcmp(local_basic.passwd, basic_auth->passwd)) {
            debug(29, 4) ("authBasicDecodeAuth: new password found. Updating in user master record and resetting auth state to unchecked\n");
            basic_auth->flags.credentials_ok = 0;
            xfree(basic_auth->passwd);
            basic_auth->passwd = local_basic.passwd;
        } else
            xfree(local_basic.passwd);

        if (basic_auth->flags.credentials_ok == 3) {
            debug(29, 4) ("authBasicDecodeAuth: last attempt to authenticate this user failed, resetting auth state to unchecked\n");
            basic_auth->flags.credentials_ok = 0;
        }
    }

    /* link the request to the user */
    auth_user_request->auth_user = auth_user;

    /* lock for the auth_user_request link */
    authenticateAuthUserLock(auth_user);

    node = dlinkNodeNew();

    dlinkAdd(auth_user_request, node, &auth_user->requests);

    return;
}

/* Initialize helpers and the like for this auth scheme. Called AFTER parsing the
 * config file */
static void
authBasicInit(authScheme * scheme)
{
    static int init = 0;

    if (basicConfig->authenticate) {
        if (!basic_data_pool)
            basic_data_pool = memPoolCreate("Basic Scheme User Data", sizeof(basic_data));

        authbasic_initialised = 1;

        if (basicauthenticators == NULL)
            basicauthenticators = helperCreate("basicauthenticator");

        basicauthenticators->cmdline = basicConfig->authenticate;

        basicauthenticators->n_to_start = basicConfig->authenticateChildren;

        basicauthenticators->concurrency = basicConfig->authenticateConcurrency;

        basicauthenticators->ipc_type = IPC_STREAM;

