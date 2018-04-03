    /* check for stale nonce */
    if (!authDigestNonceIsValid(digest_request->nonce, digest_request->nc)) {
        debugs(29, 3, "user '" << auth_user->username() << "' validated OK but nonce stale");
        auth_user->credentials(Auth::Failed);
        digest_request->setDenyMessage("Stale nonce");
        return;
    }
