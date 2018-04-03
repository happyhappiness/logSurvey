        const char *p = NULL;
        http = static_cast<ClientHttpRequest *>(i->data);
        assert(http);
        ConnStateData::Pointer conn = http->getConn();
        storeAppendPrintf(s, "Connection: %p\n", conn.getRaw());

        if (conn != NULL) {
            fd = conn->fd;
