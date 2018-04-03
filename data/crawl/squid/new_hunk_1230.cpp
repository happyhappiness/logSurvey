                             tok.int64(portb) &&
                             tok.skip('\r');
        if (!correct)
            return proxyProtocolError("PROXY/1.0 error: invalid syntax");

        // parse IP and port strings
        Ip::Address originalClient, originalDest;
