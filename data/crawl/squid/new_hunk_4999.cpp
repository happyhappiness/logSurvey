    MemBuf mb;
    const char *Method = RequestMethodStr[waisState->method];
    debug(24, 5) ("waisSendRequest: FD %d\n", fd);
    mb.init();
    mb.Printf("%s %s HTTP/1.0\r\n", Method, waisState->url);

    if (waisState->request_hdr) {
        Packer p;
