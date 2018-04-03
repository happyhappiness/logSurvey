    MemBuf mb;
    const char *Method = RequestMethodStr[waisState->method];
    debug(24, 5) ("waisSendRequest: FD %d\n", fd);
    memBufDefInit(&mb);
    memBufPrintf(&mb, "%s %s HTTP/1.0\r\n", Method, waisState->url);

    if (waisState->request_hdr) {
        Packer p;
