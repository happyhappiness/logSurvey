    ::Parser::Tokenizer tok(in.buf);
    tok.skip(Proxy1p0magic);

    // skip to first LF (assumes it is part of CRLF)
    static const CharacterSet lineContent = CharacterSet::LF.complement("non-LF");
    SBuf line;
    if (tok.prefix(line, lineContent, 107-Proxy1p0magic.length())) {
        if (tok.skip('\n')) {
            // found valid header
            in.buf = tok.remaining();
            needProxyProtocolHeader_ = false;
            // reset the tokenizer to work on found line only.
            tok.reset(line);
        } else
            return false; // no LF yet

    } else // protocol error only if there are more than 107 bytes prefix header
        return proxyProtocolError(in.buf.length() > 107? "PROXY/1.0 error: missing CRLF" : NULL);

    static const SBuf unknown("UNKNOWN"), tcpName("TCP");
    if (tok.skip(tcpName)) {

        // skip TCP/IP version number
        static const CharacterSet tcpVersions("TCP-version","46");
        if(!tok.skipOne(tcpVersions))
            return proxyProtocolError("PROXY/1.0 error: missing TCP version");

        // skip SP after protocol version
        if (!tok.skip(' '))
            return proxyProtocolError("PROXY/1.0 error: missing SP");

        SBuf ipa, ipb;
        int64_t porta, portb;
