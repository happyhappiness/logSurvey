
    if (strchr(name, ':')) {
        /* Redirection */
        httpReplySetHeaders(rep, version, HTTP_MOVED_TEMPORARILY, NULL, "text/html", 0, 0, squid_curtime);

        if (err->request) {
            char *quoted_url = rfc1738_escape_part(urlCanonical(err->request));
            httpHeaderPutStrf(&rep->header, HDR_LOCATION, name, quoted_url);
        }

        httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%d %s\n", err->httpStatus, "Access Denied");
    } else {
        MemBuf content = errorBuildContent(err);