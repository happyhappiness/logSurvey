        debugs(29, 2, "Username for the nonce does not equal the username for the request");
        nonce = NULL;
    }

    if (!nonce) {
        /* we couldn't find a matching nonce! */
        debugs(29, 2, "Unexpected or invalid nonce received from " << username);
