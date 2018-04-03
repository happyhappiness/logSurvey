static HttpReply *
clientConstructProxyAuthReply(clientHttpRequest * http)
{
    ErrorState *err = errorCon(ERR_CACHE_ACCESS_DENIED, HTTP_PROXY_AUTHENTICATION_REQUIRED);
    HttpReply *rep;
    err->request = requestLink(http->request);
    rep = errorBuildReply(err);
    errorStateFree(err);
    /* add Authenticate header */
    httpHeaderPutStrf(&rep->header, HDR_PROXY_AUTHENTICATE, proxy_auth_challenge_fmt, Config.proxyAuthRealm);
    return rep;
}

