    ::Parser::Tokenizer tok(in.buf);
    tok.skip(Proxy1p0magic);

    static const SBuf unknown("UNKNOWN"), tcpName("TCP");
    if (tok.skip(tcpName)) {

        // skip TCP/IP version number
        static const CharacterSet tcpVersions("TCP-version","46");
        if(!tok.skipOne(tcpVersions))
            return proxyProtocolError(tok.atEnd() ? "PROXY/1.0 error: missing TCP version" : NULL);

        // skip SP after protocol version
        if (!tok.skip(' '))
            return proxyProtocolError(tok.atEnd() ? "PROXY/1.0 error: missing SP" : NULL);

        SBuf ipa, ipb;
        int64_t porta, portb;
