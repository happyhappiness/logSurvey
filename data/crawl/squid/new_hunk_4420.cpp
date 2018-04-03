    str.Printf("TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));

    /* - IP stuff */
    str.Printf("ClientIP: %s\r\n", err->src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));

    if (r && r->hier.host) {
        str.Printf("ServerIP: %s\r\n", r->hier.host);
