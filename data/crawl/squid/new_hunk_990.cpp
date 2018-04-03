    static MemBuf mb;

    mb.reset();
    mb.appendf("http://%s", lc_host);

    /* append port if not default */
    if (port && port != urlDefaultPort(AnyP::PROTO_HTTP))
        mb.appendf(":%u", port);

    if (dir)
        mb.append(dir, strlen(dir));

    mb.append(name, strlen(name));

    /* return a pointer to a local static buffer */
    return mb.buf;
