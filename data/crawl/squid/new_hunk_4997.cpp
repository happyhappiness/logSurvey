    memset(&flags, '\0', sizeof(flags));
    flags.proxying = sslState->request->flags.proxying;
    MemBuf mb;
    mb.init();
    mb.Printf("CONNECT %s HTTP/1.0\r\n", sslState->url);
    httpBuildRequestHeader(sslState->request,
                           sslState->request,
                           NULL,			/* StoreEntry */
