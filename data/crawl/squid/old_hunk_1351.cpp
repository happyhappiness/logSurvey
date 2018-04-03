 * otherwise wait for more data.
 */
bool
ConnStateData::proxyProtocolError(bool fatalError)
{
    if (fatalError) {
        // terminate the connection. invalid input.
        stopReceiving("PROXY protocol error");
        stopSending("PROXY protocol error");
    }
    return false;
}

/**
 * Parse the connection read buffer for PROXY protocol header.
 * Only version 1 header currently supported.
 */
bool
ConnStateData::parseProxyProtocolMagic()
{
    // http://www.haproxy.org/download/1.5/doc/proxy-protocol.txt

    // magic octet prefix for PROXY protocol version 1
    static const SBuf proxy1magic("PROXY ");

    // magic octet prefix for PROXY protocol version 2
    static const SBuf proxy2magic("\x0D\x0A\x0D\x0A\x00\x0D\x0A\x51\x55\x49\x54\x0A", 12);

    // detect and parse PROXY protocol version 1 header
    if (in.buf.length() > proxy1magic.length() && in.buf.startsWith(proxy1magic)) {
        ::Parser::Tokenizer tok(in.buf);
        tok.skip(proxy1magic);

        SBuf tcpVersion;
        if (!tok.prefix(tcpVersion, CharacterSet::ALPHA+CharacterSet::DIGIT))
            return proxyProtocolError(tok.atEnd());

        if (!tcpVersion.cmp("UNKNOWN")) {
            // skip to first LF (assumes it is part of CRLF)
            const SBuf::size_type pos = in.buf.findFirstOf(CharacterSet::LF);
            if (pos != SBuf::npos) {
                if (in.buf[pos-1] != '\r')
                    return proxyProtocolError(false); // invalid terminator
                // found valid but unusable header
                in.buf.consume(pos);
                needProxyProtocolHeader_ = false;
                return true;
            }
            // else, no LF found

            // protocol error only if there are more than 107 bytes prefix header
            return proxyProtocolError(in.buf.length() > 107);

        } else if (!tcpVersion.cmp("TCP",3)) {

            // skip SP after protocol version
            if (!tok.skip(' '))
                return proxyProtocolError(tok.atEnd());

            SBuf ipa, ipb;
            int64_t porta, portb;
            const CharacterSet ipChars =  CharacterSet("IP Address",".:") + CharacterSet::HEXDIG;

            // parse  src-IP SP dst-IP SP src-port SP dst-port CRLF
            if (!tok.prefix(ipa, ipChars) || !tok.skip(' ') ||
               !tok.prefix(ipb, ipChars) || !tok.skip(' ') ||
               !tok.int64(porta) || !tok.skip(' ') ||
               !tok.int64(portb) || !tok.skip('\r') || !tok.skip('\n'))
                return proxyProtocolError(!tok.atEnd());

            // XXX parse IP and port strings
            Ip::Address originalClient, originalDest;

            if (!originalClient.GetHostByName(ipa.c_str()))
                return proxyProtocolError(true);

            if (!originalDest.GetHostByName(ipb.c_str()))
                return false;

            if (porta > 0 && porta <= 0xFFFF) // max uint16_t
                originalClient.port(static_cast<uint16_t>(porta));
            else
                return proxyProtocolError(true);

            if (portb > 0 && portb <= 0xFFFF) // max uint16_t
                originalDest.port(static_cast<uint16_t>(portb));
            else
                return proxyProtocolError(true);

            in.buf = tok.remaining(); // sync buffers
            needProxyProtocolHeader_ = false; // found successfully

            // we have original client and destination details now
            // replace the client connection values
            debugs(33, 5, "PROXY protocol on connection " << clientConnection);
            clientConnection->local = originalDest;
            clientConnection->remote = originalClient;
            debugs(33, 5, "PROXY upgrade: " << clientConnection);

            // repeat fetch ensuring the new client FQDN can be logged
            if (Config.onoff.log_fqdn)
                fqdncache_gethostbyaddr(clientConnection->remote, FQDN_LOOKUP_IF_MISS);

            return true;
        }

        // detect and parse PROXY protocol version 2 header
    } else if (in.buf.length() > proxy2magic.length() && in.buf.startsWith(proxy2magic)) {

        if ((in.buf[0] & 0xF0) != 0x20) // version == 2 is mandatory
            proxyProtocolError(true);

        const char command = (in.buf[0] & 0x0F);
        if ((command & 0xFE) != 0x00) // values other than 0x0-0x1 are invalid
            proxyProtocolError(true);

        const char family = (in.buf[1] & 0xF0) >>4;
        if (family > 0x3) // values other than 0x0-0x3 are invalid
            proxyProtocolError(true);

        const char proto = (in.buf[1] & 0x0F);
        if (proto > 0x2) // values other than 0x0-0x2 are invalid
            proxyProtocolError(true);

        const char *clen = in.buf.rawContent() + proxy2magic.length() + 2;
        const uint16_t len = ntohs(*(reinterpret_cast<const uint16_t *>(clen)));

        if (in.buf.length() < proxy2magic.length() + 4 + len)
            return false; // need more bytes

        in.buf.consume(proxy2magic.length() + 4); // 4 being the extra bytes
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
        debugs(33, 5, "PROXY protocol on connection " << clientConnection);
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
        debugs(33, 5, "PROXY upgrade: " << clientConnection);

        // repeat fetch ensuring the new client FQDN can be logged
        if (Config.onoff.log_fqdn)
            fqdncache_gethostbyaddr(clientConnection->remote, FQDN_LOOKUP_IF_MISS);

        return true;

        // detect and terminate other protocols
    } else if (in.buf.length() >= proxy2magic.length()) {

        // input other than the PROXY header is a protocol error
        return proxyProtocolError(true);
    }

    // not enough bytes to parse yet.
    return false;
}

/**
