{
    AuthUserRequest::Pointer auth_user_request = dynamic_cast<AuthUserRequest*>(new AuthBasicUserRequest);
    /* decode the username */
    /* trim BASIC from string */

    while (xisgraph(*proxy_auth))
        proxy_auth++;

    /* decoder copy. maybe temporary. maybe added to hash if none already existing. */
    BasicUser *local_basic = new BasicUser(this);

    /* Trim leading whitespace before decoding */
    while (xisspace(*proxy_auth))
        proxy_auth++;

    local_basic->decode(proxy_auth, auth_user_request);

    if (!local_basic->valid()) {
        local_basic->makeLoggingInstance(auth_user_request);
        return auth_user_request;
    }

    /* now lookup and see if we have a matching auth_user structure in memory. */
    AuthUser::Pointer auth_user;

    if ((auth_user = authBasicAuthUserFindUsername(local_basic->username())) == NULL) {
        /* the user doesn't exist in the username cache yet */
        /* save the credentials */
        debugs(29, 9, HERE << "Creating new user '" << local_basic->username() << "'");
        /* set the auth_user type */
        local_basic->auth_type = AUTH_BASIC;
        /* current time for timeouts */
        local_basic->expiretime = current_time.tv_sec;

        /* this basic_user struct is the 'lucky one' to get added to the username cache */
        /* the requests after this link to the basic_user */
        /* store user in hash */
        local_basic->addToNameCache();

        auth_user = dynamic_cast<AuthUser*>(local_basic);
        assert(auth_user != NULL);
    } else {
        /* replace the current cached password with the new one */
