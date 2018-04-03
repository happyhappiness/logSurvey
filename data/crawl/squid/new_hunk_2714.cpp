{
    AuthUserRequest::Pointer auth_user_request = dynamic_cast<AuthUserRequest*>(new AuthBasicUserRequest);
    /* decode the username */

    // retrieve the cleartext (in a dynamically allocated char*)
    char *cleartext = decodeCleartext(proxy_auth);

    // empty header? no auth details produced...
    if (!cleartext)
        return auth_user_request;

    AuthUser::Pointer lb;
    /* permitted because local_basic is purely local function scope. */
    BasicUser *local_basic = NULL;

    char *seperator = strchr(cleartext, ':');

    lb = local_basic = new BasicUser(this);
    if (seperator == NULL) {
        local_basic->username(cleartext);
    } else {
        /* terminate the username */
        *seperator = '\0';
        local_basic->username(cleartext);
        local_basic->passwd = xstrdup(seperator+1);
    }

    if (!casesensitive)
        Tolower((char *)local_basic->username());

    if (local_basic->passwd == NULL) {
        debugs(29, 4, HERE << "no password in proxy authorization header '" << proxy_auth << "'");
        auth_user_request->setDenyMessage("no password was present in the HTTP [proxy-]authorization header. This is most likely a browser bug");
    } else {
        if (local_basic->passwd[0] == '\0') {
            debugs(29, 4, HERE << "Disallowing empty password. User is '" << local_basic->username() << "'");
            safe_free(local_basic->passwd);
            auth_user_request->setDenyMessage("Request denied because you provided an empty password. Users MUST have a password.");
        }
    }

    xfree(cleartext);

    if (!local_basic->valid()) {
        lb->auth_type = AUTH_BROKEN;
        auth_user_request->user(lb);
        return auth_user_request;
    }

    /* now lookup and see if we have a matching auth_user structure in memory. */
    AuthUser::Pointer auth_user;

    if ((auth_user = authBasicAuthUserFindUsername(lb->username())) == NULL) {
        /* the user doesn't exist in the username cache yet */
        /* save the credentials */
        debugs(29, 9, HERE << "Creating new user '" << lb->username() << "'");
        /* set the auth_user type */
        lb->auth_type = AUTH_BASIC;
        /* current time for timeouts */
        lb->expiretime = current_time.tv_sec;

        /* this basic_user struct is the 'lucky one' to get added to the username cache */
        /* the requests after this link to the basic_user */
        /* store user in hash */
        lb->addToNameCache();

        auth_user = lb;
        assert(auth_user != NULL);
    } else {
        /* replace the current cached password with the new one */
