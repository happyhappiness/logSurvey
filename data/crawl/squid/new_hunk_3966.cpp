
    // we must forward "Proxy-Authenticate" and "Proxy-Authorization"
    // as ICAP headers.
    if (virgin.header->header.has(HDR_PROXY_AUTHENTICATE)) {
        String vh=virgin.header->header.getByName("Proxy-Authenticate");
        buf.Printf("Proxy-Authenticate: %.*s\r\n",
                   vh.size(), vh.rawBuf());
    }

    if (virgin.header->header.has(HDR_PROXY_AUTHORIZATION)) {
        String vh=virgin.header->header.getByName("Proxy-Authorization");
        buf.Printf("Proxy-Authorization: %.*s\r\n",
                   vh.size(), vh.rawBuf());
    }

    buf.Printf("Encapsulated: ");

