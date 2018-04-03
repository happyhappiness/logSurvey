            return true;
        }

    } else if (in.buf.length() >= proxy1magic.length()) {
        // input other than the PROXY header is a protocol error
        return proxyProtocolError(true);
    }