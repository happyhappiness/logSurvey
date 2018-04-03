
    // we must forward "Proxy-Authenticate" and "Proxy-Authorization"
    // as ICAP headers.
    if (virgin.header->header.has(HDR_PROXY_AUTHENTICATE))
        buf.Printf("Proxy-Authenticate: %s\r\n",
                   virgin.header->header.getByName("Proxy-Authenticate").unsafeBuf());

    if (virgin.header->header.has(HDR_PROXY_AUTHORIZATION))
        buf.Printf("Proxy-Authorization: %s\r\n",
                   virgin.header->header.getByName("Proxy-Authorization").unsafeBuf());

    buf.Printf("Encapsulated: ");

