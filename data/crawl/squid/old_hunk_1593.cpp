
    /* now the nonce */
    nonce = authenticateDigestNonceFindNonce(digest_request->nonceb64);
    if (!nonce) {
        /* we couldn't find a matching nonce! */
        debugs(29, 2, "Unexpected or invalid nonce received");
        if (digest_request->user() != NULL)
            digest_request->user()->credentials(Auth::Failed);
        rv = authDigestLogUsername(username, digest_request, aRequestRealm);
        safe_free(username);
        return rv;
    }

    digest_request->nonce = nonce;
