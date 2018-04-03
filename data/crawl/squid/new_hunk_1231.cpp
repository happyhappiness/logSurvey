        return true;

    } else if (tok.skip(unknown)) {
        // found valid but unusable header
        return true;

    } else
        return proxyProtocolError("PROXY/1.0 error: invalid protocol family");

    return false;
}