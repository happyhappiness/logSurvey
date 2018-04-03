    assert(req);

    if (req->body_connection.getRaw() != NULL)
        clientAbortBody(req);

    if (req->auth_user_request)
        authenticateAuthUserRequestUnlock(req->auth_user_request);
