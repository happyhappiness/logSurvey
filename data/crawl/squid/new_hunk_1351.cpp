 * otherwise wait for more data.
 */
bool
ConnStateData::proxyProtocolError(const char *msg)
{
    if (msg)
        mustStop(msg);
    return false;
}

/// magic octet prefix for PROXY protocol version 1
static const SBuf Proxy10magic("PROXY ", 6);

/// magic octet prefix for PROXY protocol version 2
static const SBuf Proxy20magic("\x0D\x0A\x0D\x0A\x00\x0D\x0A\x51\x55\x49\x54\x0A", 12);

/**
 * Test the connection read buffer for PROXY protocol header.
 * Version 1 and 2 header currently supported.
 */
bool
ConnStateData::findProxyProtocolMagic()
{
    // http://www.haproxy.org/download/1.5/doc/proxy-protocol.txt

    // detect and parse PROXY protocol version 1 header
    if (in.buf.length() > Proxy10magic.length() && in.buf.startsWith(Proxy10magic)) {
         return parseProxy10();

        // detect and parse PROXY protocol version 2 header
    } else if (in.buf.length() > Proxy20magic.length() && in.buf.startsWith(Proxy20magic)) {
        return parseProxy20();

        // detect and terminate other protocols
    } else if (in.buf.length() >= Proxy20magic.length()) {
        // input other than the PROXY header is a protocol error
        return proxyProtocolError("PROXY protocol error: invalid header");
    }

    // not enough bytes to parse yet.
    return false;
}

/// parse the PROXY/1.0 protocol header from the connection read buffer
bool
ConnStateData::parseProxy10()
{
    ::Parser::Tokenizer tok(in.buf);
    tok.skip(Proxy10magic);

    SBuf tcpVersion;
    if (!tok.prefix(tcpVersion, CharacterSet::ALPHA+CharacterSet::DIGIT))
        return proxyProtocolError(tok.atEnd()?"PROXY/1.0 error: invalid protocol family":NULL);

    if (!tcpVersion.cmp("UNKNOWN")) {
        // skip to first LF (assumes it is part of CRLF)
        const SBuf::size_type pos = in.buf.findFirstOf(CharacterSet::LF);
        if (pos != SBuf::npos) {
            if (in.buf[pos-1] != '\r')
                return proxyProtocolError("PROXY/1.0 error: missing CR");
            // found valid but unusable header
            in.buf.consume(pos);
            needProxyProtocolHeader_ = false;
            return true;
        }
        // else, no LF found

        // protocol error only if there are more than 107 bytes prefix header
        return proxyProtocolError(in.buf.length() > 107? "PROXY error: missing CRLF":NULL);

    } else if (!tcpVersion.cmp("TCP",3)) {

        // skip SP after protocol version
        if (!tok.skip(' '))
            return proxyProtocolError(tok.atEnd()?"PROXY/1.0 error: missing SP":NULL);

        SBuf ipa, ipb;
        int64_t porta, portb;
        const CharacterSet ipChars =  CharacterSet("IP Address",".:") + CharacterSet::HEXDIG;

        // parse  src-IP SP dst-IP SP src-port SP dst-port CRLF
        if (!tok.prefix(ipa, ipChars) || !tok.skip(' ') ||
           !tok.prefix(ipb, ipChars) || !tok.skip(' ') ||
           !tok.int64(porta) || !tok.skip(' ') ||
           !tok.int64(portb) || !tok.skip('\r') || !tok.skip('\n'))
            return proxyProtocolError(!tok.atEnd()?"PROXY/1.0 error: invalid syntax":NULL);

        in.buf = tok.remaining(); // sync buffers
        needProxyProtocolHeader_ = false; // found successfully

        // parse IP and port strings
        Ip::Address originalClient, originalDest;

        if (!originalClient.GetHostByName(ipa.c_str()))
            return proxyProtocolError("PROXY/1.0 error: invalid src-IP address");

        if (!originalDest.GetHostByName(ipb.c_str()))
            return proxyProtocolError("PROXY/1.0 error: invalid dst-IP address");

        if (porta > 0 && porta <= 0xFFFF) // max uint16_t
            originalClient.port(static_cast<uint16_t>(porta));
        else
            return proxyProtocolError("PROXY/1.0 error: invalid src port");

        if (portb > 0 && portb <= 0xFFFF) // max uint16_t
            originalDest.port(static_cast<uint16_t>(portb));
        else
            return proxyProtocolError("PROXY/1.0 error: invalid dst port");

        // we have original client and destination details now
        // replace the client connection values
        debugs(33, 5, "PROXY/1.0 protocol on connection " << clientConnection);
        clientConnection->local = originalDest;
        clientConnection->remote = originalClient;
        debugs(33, 5, "PROXY/1.0 upgrade: " << clientConnection);

        // repeat fetch ensuring the new client FQDN can be logged
        if (Config.onoff.log_fqdn)
            fqdncache_gethostbyaddr(clientConnection->remote, FQDN_LOOKUP_IF_MISS);

        return true;
    }

    return false;
}

/// parse the PROXY/2.0 protocol header from the connection read buffer
bool
ConnStateData::parseProxy20()
{
    if ((in.buf[0] & 0xF0) != 0x20) // version == 2 is mandatory
        return proxyProtocolError("PROXY/2.0 error: invalid version");

    const char command = (in.buf[0] & 0x0F);
    if ((command & 0xFE) != 0x00) // values other than 0x0-0x1 are invalid
        return proxyProtocolError("PROXY/2.0 error: invalid command");

    const char family = (in.buf[1] & 0xF0) >>4;
    if (family > 0x3) // values other than 0x0-0x3 are invalid
        return proxyProtocolError("PROXY/2.0 error: invalid family");

    const char proto = (in.buf[1] & 0x0F);
    if (proto > 0x2) // values other than 0x0-0x2 are invalid
        return proxyProtocolError("PROXY/2.0 error: invalid protocol type");

    const char *clen = in.buf.rawContent() + Proxy20magic.length() + 2;
    const uint16_t len = ntohs(*(reinterpret_cast<const uint16_t *>(clen)));

    if (in.buf.length() < Proxy20magic.length() + 4 + len)
        return false; // need more bytes

    in.buf.consume(Proxy20magic.length() + 4); // 4 being the extra bytes
    const SBuf extra = in.buf.consume(len);
    needProxyProtocolHeader_ = false; // found successfully

    // LOCAL connections do nothing with the extras
    if (command == 0x00/* LOCAL*/)
        return true;

    typedef union proxy_addr {
        struct {        /* for TCP/UDP over IPv4, len = 12 */
            struct in_addr src_addr;
            struct in_addr dst_addr;
            uint16_t src_port;
            uint16_t dst_port;
        } ipv4_addr;
        struct {        /* for TCP/UDP over IPv6, len = 36 */
             struct in6_addr src_addr;
             struct in6_addr dst_addr;
             uint16_t src_port;
             uint16_t dst_port;
        } ipv6_addr;
#if NOT_SUPPORTED
        struct {        /* for AF_UNIX sockets, len = 216 */
             uint8_t src_addr[108];
             uint8_t dst_addr[108];
        } unix_addr;
#endif
    } pax;

    const pax *ipu = reinterpret_cast<const pax*>(extra.rawContent());

    // replace the client connection values
    debugs(33, 5, "PROXY/2.0 protocol on connection " << clientConnection);
    switch (family)
    {
    case 0x1: // IPv4
        clientConnection->local = ipu->ipv4_addr.dst_addr;
        clientConnection->local.port(ntohs(ipu->ipv4_addr.dst_port));
        clientConnection->remote = ipu->ipv4_addr.src_addr;
        clientConnection->remote.port(ntohs(ipu->ipv4_addr.src_port));
        break;
    case 0x2: // IPv6
        clientConnection->local = ipu->ipv6_addr.dst_addr;
        clientConnection->local.port(ntohs(ipu->ipv6_addr.dst_port));
        clientConnection->remote = ipu->ipv6_addr.src_addr;
        clientConnection->remote.port(ntohs(ipu->ipv6_addr.src_port));
        break;
    default: // do nothing
        break;
    }
    debugs(33, 5, "PROXY/2.0 upgrade: " << clientConnection);

    // repeat fetch ensuring the new client FQDN can be logged
    if (Config.onoff.log_fqdn)
        fqdncache_gethostbyaddr(clientConnection->remote, FQDN_LOOKUP_IF_MISS);

    return true;
}

/**
