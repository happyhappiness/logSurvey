    /* build uri in mb */
    static MemBuf mb;

    memBufReset(&mb);

    memBufPrintf(&mb, "http://%s", lc_host);

    /* append port if not default */
    if (port && port != urlDefaultPort(PROTO_HTTP))
        memBufPrintf(&mb, ":%d", port);

    if (dir)
        memBufPrintf(&mb, "%s", dir);

    memBufPrintf(&mb, "%s", name);

    /* return a pointer to a local static buffer */
    return mb.buf;
