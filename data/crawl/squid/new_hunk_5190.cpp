    assert(req);

    if (req->body_connection.getRaw() != NULL)
        fatal ("request being destroyed with body connection intact\n");

    if (req->auth_user_request)
        authenticateAuthUserRequestUnlock(req->auth_user_request);