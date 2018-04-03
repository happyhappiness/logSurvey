        fatal ("request being destroyed with body connection intact\n");

    if (req->auth_user_request)
        authenticateAuthUserRequestUnlock(req->auth_user_request);

    safe_free(req->canonical);

