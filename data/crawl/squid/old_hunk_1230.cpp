                             tok.int64(portb) &&
                             tok.skip('\r');
        if (!correct)
            return proxyProtocolError(!tok.atEnd() ? "PROXY/1.0 error: invalid syntax" : NULL);

        if (!tok.skip('\n')) // line terminator.
            return proxyProtocolError("PROXY/1.0 error: missing LF");

        in.buf = tok.remaining(); // sync buffers
        needProxyProtocolHeader_ = false; // found successfully

        // parse IP and port strings
        Ip::Address originalClient, originalDest;
