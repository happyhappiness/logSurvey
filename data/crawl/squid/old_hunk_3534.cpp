
    /* New request, no user details */
    if (auth_user_request == NULL) {
        debugs(29, 9, "AuthNTLMConfig::fixHeader: Sending type:" << type << " header: 'NTLM'");
        httpHeaderPutStrf(&rep->header, type, "NTLM");

        if (!keep_alive) {
            /* drop the connection */
