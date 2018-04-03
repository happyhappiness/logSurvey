    return req;
}

void
requestDestroy(HttpRequest * req)
{
    assert(req);

    if (req->body_connection.getRaw() != NULL)
        fatal ("request being destroyed with body connection intact\n");

    if (req->auth_user_request)
        req->auth_user_request->unlock();

    safe_free(req->canonical);

    safe_free(req->vary_headers);

    req->urlpath.clean();

    httpHeaderClean(&req->header);

    if (req->cache_control)
        httpHdrCcDestroy(req->cache_control);

    if (req->range)
        delete req->range;

    req->tag.clean();

    req->extacl_user.clean();

    req->extacl_passwd.clean();

    req->extacl_log.clean();

    delete req;
}

HttpRequest *
