    ::Parser::Tokenizer tok(in.buf);
    tok.skip(Proxy1p0magic);

    static const SBuf unknown("UNKNOWN"), tcpName("TCP");
    if (tok.skip(tcpName)) {

        // skip TCP/IP version number
        static const CharacterSet tcpVersions("TCP-version","46");
        if(!tok.skip(tcpVersions))
            return proxyProtocolError(tok.atEnd() ? "PROXY/1.0 error: missing TCP version" : NULL);

        // skip SP after protocol version
        if (!tok.skip(' '))
            return proxyProtocolError(tok.atEnd() ? "PROXY/1.0 error: missing SP" : NULL);

        SBuf ipa, ipb;
        int64_t porta, portb;
        static const CharacterSet ipChars = CharacterSet("IP Address",".:") + CharacterSet::HEXDIG;

        // parse:  src-IP SP dst-IP SP src-port SP dst-port CR
        // leave the LF until later.
        const bool correct = tok.prefix(ipa, ipChars) && tok.skip(' ') &&
                             tok.prefix(ipb, ipChars) && tok.skip(' ') &&
                             tok.int64(porta) && tok.skip(' ') &&
                             tok.int64(portb) &&
                             tok.skip('\r');
        if (!correct)
            return proxyProtocolError(!tok.atEnd() ? "PROXY/1.0 error: invalid syntax" : NULL);

        if (!tok.skip('\n')) // line terminator.
            return proxyProtocolError("PROXY/1.0 error: missing LF");

        in.buf = tok.remaining(); // sync buffers
        needProxyProtocolHeader_ = false; // found successfully
