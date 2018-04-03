    digest_request_h *digest_request;
    int stale = 0;
    digest_nonce_h *nonce = authenticateDigestNonceNew();

    if (auth_user_request && authDigestAuthenticated(auth_user_request) && auth_user_request->scheme_data) {
        digest_request = static_cast < digest_request_h * >(auth_user_request->scheme_data);
        stale = authDigestNonceIsStale(digest_request->nonce);
    }

    if (digestConfig->authenticate) {
        debug(29, 9) ("authenticateFixHeader: Sending type:%d header: 'Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s\n", type, digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
        /* in the future, for WWW auth we may want to support the domain entry */
        httpHeaderPutStrf(&rep->header, type, "Digest realm=\"%s\", nonce=\"%s\", qop=\"%s\", stale=%s", digestConfig->digestAuthRealm, authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
    }
}

