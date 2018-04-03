
#endif

    if ((digestConfig.authenticate) && authDigestNonceLastRequest(nonce)) {
        flags.authinfo_sent = 1;
        debug(29, 9) ("authDigestAddHead: Sending type:%d header: 'nextnonce=\"%s\"", type, authenticateDigestNonceNonceb64(nonce));
        httpHeaderPutStrf(&rep->header, type, "nextnonce=\"%s\"", authenticateDigestNonceNonceb64(nonce));
