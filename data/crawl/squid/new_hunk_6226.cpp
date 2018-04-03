static HttpReply *
clientConstructProxyAuthReply(clientHttpRequest * http)
{
    ErrorState *err;
    HttpReply *rep;
    if (!http->flags.accel) {
	/* Proxy authorisation needed */
	err = errorCon(ERR_CACHE_ACCESS_DENIED,
	    HTTP_PROXY_AUTHENTICATION_REQUIRED);
    } else {
	/* WWW authorisation needed */
	err = errorCon(ERR_CACHE_ACCESS_DENIED, HTTP_UNAUTHORIZED);
    }
    err->request = requestLink(http->request);
    rep = errorBuildReply(err);
    errorStateFree(err);
    /* add Authenticate header */
    if (!http->flags.accel) {
	/* Proxy authorisation needed */
	httpHeaderPutStrf(&rep->header, HDR_PROXY_AUTHENTICATE,
	    proxy_auth_challenge_fmt, Config.proxyAuthRealm);
    } else {
	/* WWW Authorisation needed */
	httpHeaderPutStrf(&rep->header, HDR_WWW_AUTHENTICATE,
	    proxy_auth_challenge_fmt, Config.proxyAuthRealm);
    }
    return rep;
}

