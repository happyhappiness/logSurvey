    HttpHeader *hdr;
    httpStatusLineSet(&sline, ver, status, reason);
    hdr = &header;
    httpHeaderPutStr(hdr, HDR_SERVER, visible_appname_string);
    httpHeaderPutStr(hdr, HDR_MIME_VERSION, "1.0");
    httpHeaderPutTime(hdr, HDR_DATE, squid_curtime);

    if (ctype) {
        httpHeaderPutStr(hdr, HDR_CONTENT_TYPE, ctype);
        content_type = ctype;
    } else
        content_type = String();

    if (clen >= 0)
        httpHeaderPutInt(hdr, HDR_CONTENT_LENGTH, clen);

    if (expires >= 0)
        httpHeaderPutTime(hdr, HDR_EXPIRES, expires);

    if (lmt > 0)		/* this used to be lmt != 0 @?@ */
        httpHeaderPutTime(hdr, HDR_LAST_MODIFIED, lmt);

    date = squid_curtime;

