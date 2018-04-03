        return true;

    } else if (tok.skip(unknown)) {
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
        return proxyProtocolError(in.buf.length() > 107? "PROXY/1.0 error: missing CRLF":NULL);

    } else
        return proxyProtocolError(tok.atEnd() ? "PROXY/1.0 error: invalid protocol family" : NULL);

    return false;
}