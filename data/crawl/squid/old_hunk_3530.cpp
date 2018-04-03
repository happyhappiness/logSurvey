
    /* New request, no user details */
    if (auth_user_request == NULL) {
        debugs(29, 9, "AuthNegotiateConfig::fixHeader: Sending type:" << type << " header: 'Negotiate'");
        httpHeaderPutStrf(&rep->header, type, "Negotiate");

        if (!keep_alive) {
            /* drop the connection */
