    if (!TheConfig.reuse_connections)
        buf.Printf("Connection: close\r\n");

    // we must forward "Proxy-Authenticate" and "Proxy-Authorization"
    // as ICAP headers.
    if (virgin.header->header.has(HDR_PROXY_AUTHENTICATE)) {
