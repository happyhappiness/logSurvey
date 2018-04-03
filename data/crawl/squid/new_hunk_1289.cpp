    }

    debugs(29, 9, "Sending type:" << hdrType <<
           " header: 'Digest realm=\"" << realm << "\", nonce=\"" <<
           authenticateDigestNonceNonceb64(nonce) << "\", qop=\"" << QOP_AUTH <<
           "\", stale=" << (stale ? "true" : "false"));

    /* in the future, for WWW auth we may want to support the domain entry */
    httpHeaderPutStrf(&rep->header, hdrType, "Digest realm=\"" SQUIDSBUFPH "\", nonce=\"%s\", qop=\"%s\", stale=%s",
                      SQUIDSBUFPRINT(realm), authenticateDigestNonceNonceb64(nonce), QOP_AUTH, stale ? "true" : "false");
}

/* Initialize helpers and the like for this auth scheme. Called AFTER parsing the
