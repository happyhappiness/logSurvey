    HttpRequest *r = err->request;
    MemBuf str;
    const char *p = NULL;	/* takes priority over mb if set */
    str.reset();
    /* email subject line */
    str.Printf("CacheErrorInfo - %s", errorPageName(err->type));
    mb->Printf("?subject=%s", rfc1738_escape_part(str.buf));
    str.reset();
    /* email body */
    str.Printf("CacheHost: %s\r\n", getMyHostname());
    /* - Err Msgs */
    str.Printf("ErrPage: %s\r\n", errorPageName(err->type));

    if (err->xerrno) {
        str.Printf("Err: (%d) %s\r\n", err->xerrno, strerror(err->xerrno));
    } else {
        str.Printf("Err: [none]\r\n");
    }

    if (err->auth_user_request->denyMessage())
        str.Printf("Auth ErrMsg: %s\r\n", err->auth_user_request->denyMessage());

    if (err->dnsserver_msg) {
        str.Printf("DNS Server ErrMsg: %s\r\n", err->dnsserver_msg);
    }

    /* - TimeStamp */
    str.Printf("TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));

    /* - IP stuff */
    str.Printf("ClientIP: %s\r\n", inet_ntoa(err->src_addr));

    if (err->host) {
        str.Printf("ServerIP: %s\r\n", err->host);
    }

    str.Printf("\r\n");
    /* - HTTP stuff */
    str.Printf("HTTP Request:\r\n");

    if (NULL != r) {
        Packer p;
        str.Printf("%s %s HTTP/%d.%d\n",
                   RequestMethodStr[r->method],
                   r->urlpath.size() ? r->urlpath.buf() : "/",
                   r->http_ver.major, r->http_ver.minor);
        packerToMemInit(&p, &str);
        httpHeaderPackInto(&r->header, &p);
        packerClean(&p);
