{
    enum http_hdr_type type;
    digest_request_h *digest_request;

    if (!auth_user_request)
        return;

    digest_request = static_cast < digest_request_h * >(auth_user_request->scheme_data);

    /* don't add to authentication error pages */
    if ((!accel && rep->sline.status == HTTP_PROXY_AUTHENTICATION_REQUIRED)
            || (accel && rep->sline.status == HTTP_UNAUTHORIZED))
        return;

    type = accel ? HDR_AUTHENTICATION_INFO : HDR_PROXY_AUTHENTICATION_INFO;

#if WAITING_FOR_TE
    /* test for http/1.1 transfer chunked encoding */
    if (chunkedtest)
        return;

#endif

    if ((digestConfig->authenticate) && authDigestNonceLastRequest(digest_request->nonce)) {
        digest_request->flags.authinfo_sent = 1;
        debug(29, 9) ("authDigestAddHead: Sending type:%d header: 'nextnonce=\"%s\"", type, authenticateDigestNonceNonceb64(digest_request->nonce));
        httpHeaderPutStrf(&rep->header, type, "nextnonce=\"%s\"", authenticateDigestNonceNonceb64(digest_request->nonce));
    }
}

