    rep = errorBuildReply(err);
    errorStateFree(err);
    /* add Authenticate header */
    httpHeaderPutStr(&rep->header, HDR_PROXY_AUTHENTICATE, proxy_auth_challenge);
    return rep;
}

