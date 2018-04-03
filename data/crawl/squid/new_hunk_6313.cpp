    rep = errorBuildReply(err);
    errorStateFree(err);
    /* add Authenticate header */
    httpHeaderPutStrf(&rep->header, HDR_PROXY_AUTHENTICATE, proxy_auth_challenge_fmt, Config.proxyAuthRealm);
    return rep;
}

