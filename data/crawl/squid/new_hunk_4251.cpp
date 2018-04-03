}

HttpReply *
ErrorState::BuildHttpReply()
{
    HttpReply *rep = new HttpReply;
    const char *name = errorPageName(page_id);
    /* no LMT for error pages; error pages expire immediately */
    HttpVersion version(1, 0);

    if (strchr(name, ':')) {
        /* Redirection */
        rep->setHeaders(version, HTTP_MOVED_TEMPORARILY, NULL, "text/html", 0, 0, squid_curtime);

        if (request) {
            char *quoted_url = rfc1738_escape_part(urlCanonical(request));
            httpHeaderPutStrf(&rep->header, HDR_LOCATION, name, quoted_url);
        }

        httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%d %s", httpStatus, "Access Denied");
    } else {
        MemBuf *content = BuildContent();
        rep->setHeaders(version, httpStatus, NULL, "text/html", content->contentSize(), 0, squid_curtime);
        /*
         * include some information for downstream caches. Implicit
         * replaceable content. This isn't quite sufficient. xerrno is not
