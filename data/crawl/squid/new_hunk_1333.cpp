        // else, no LF found

        // protocol error only if there are more than 107 bytes prefix header
        return proxyProtocolError(in.buf.length() > 107? "PROXY/1.0 error: missing CRLF":NULL);

    } else if (!tcpVersion.cmp("TCP",3)) {
