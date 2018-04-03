    HttpRequest *r = err->request;
    MemBuf str;
    const char *p = NULL;	/* takes priority over mb if set */
    memBufReset(&str);
    /* email subject line */
    memBufPrintf(&str, "CacheErrorInfo - %s", errorPageName(err->type));
    memBufPrintf(mb, "?subject=%s", rfc1738_escape_part(str.buf));
    memBufReset(&str);
    /* email body */
    memBufPrintf(&str, "CacheHost: %s\r\n", getMyHostname());
    /* - Err Msgs */
    memBufPrintf(&str, "ErrPage: %s\r\n", errorPageName(err->type));

    if (err->xerrno) {
        memBufPrintf(&str, "Err: (%d) %s\r\n", err->xerrno, strerror(err->xerrno));
    } else {
        memBufPrintf(&str, "Err: [none]\r\n");
    }

    if (err->auth_user_request->denyMessage())
        memBufPrintf(&str, "Auth ErrMsg: %s\r\n", err->auth_user_request->denyMessage());

    if (err->dnsserver_msg) {
        memBufPrintf(&str, "DNS Server ErrMsg: %s\r\n", err->dnsserver_msg);
    }

    /* - TimeStamp */
    memBufPrintf(&str, "TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));

    /* - IP stuff */
    memBufPrintf(&str, "ClientIP: %s\r\n", inet_ntoa(err->src_addr));

    if (err->host) {
        memBufPrintf(&str, "ServerIP: %s\r\n", err->host);
    }

    memBufPrintf(&str, "\r\n");
    /* - HTTP stuff */
    memBufPrintf(&str, "HTTP Request:\r\n");

    if (NULL != r) {
        Packer p;
        memBufPrintf(&str, "%s %s HTTP/%d.%d\n",
                     RequestMethodStr[r->method],
                     r->urlpath.size() ? r->urlpath.buf() : "/",
                     r->http_ver.major, r->http_ver.minor);
        packerToMemInit(&p, &str);
        httpHeaderPackInto(&r->header, &p);
        packerClean(&p);
