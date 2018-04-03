    cbdataFree(err);
}

int
ErrorState::Dump(MemBuf * mb)
{
    MemBuf str;
    const char *p = NULL;	/* takes priority over mb if set */
    char ntoabuf[MAX_IPSTRLEN];

    str.reset();
    /* email subject line */
    str.Printf("CacheErrorInfo - %s", errorPageName(type));
    mb->Printf("?subject=%s", rfc1738_escape_part(str.buf));
    str.reset();
    /* email body */
    str.Printf("CacheHost: %s\r\n", getMyHostname());
    /* - Err Msgs */
    str.Printf("ErrPage: %s\r\n", errorPageName(type));

    if (xerrno) {
        str.Printf("Err: (%d) %s\r\n", xerrno, strerror(xerrno));
    } else {
        str.Printf("Err: [none]\r\n");
    }

    if (auth_user_request->denyMessage())
        str.Printf("Auth ErrMsg: %s\r\n", auth_user_request->denyMessage());

    if (dnsserver_msg) {
        str.Printf("DNS Server ErrMsg: %s\r\n", dnsserver_msg);
    }

    /* - TimeStamp */
    str.Printf("TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));

    /* - IP stuff */
    str.Printf("ClientIP: %s\r\n", src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));

    if (request && request->hier.host) {
        str.Printf("ServerIP: %s\r\n", request->hier.host);
    }

    str.Printf("\r\n");
    /* - HTTP stuff */
    str.Printf("HTTP Request:\r\n");

    if (NULL != request) {
        Packer p;
        str.Printf("%s %s HTTP/%d.%d\n",
                   RequestMethodStr(request->method),
                   request->urlpath.size() ? request->urlpath.buf() : "/",
                   request->http_ver.major, request->http_ver.minor);
        packerToMemInit(&p, &str);
        request->header.packInto(&p);
        packerClean(&p);
    } else if (request_hdrs) {
        p = request_hdrs;
    } else {
        p = "[none]";
    }

    str.Printf("\r\n");
    /* - FTP stuff */

    if (ftp.request) {
        str.Printf("FTP Request: %s\r\n", ftp.request);
        str.Printf("FTP Reply: %s\r\n", ftp.reply);
        str.Printf("FTP Msg: ");
        wordlistCat(ftp.server_msg, &str);
        str.Printf("\r\n");
    }

