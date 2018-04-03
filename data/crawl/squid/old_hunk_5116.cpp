
    if (strchr(name, ':')) {
        /* Redirection */
        char *quoted_url = rfc1738_escape_part(errorConvert('u', err));
        httpReplySetHeaders(rep, version, HTTP_MOVED_TEMPORARILY, NULL, "text/html", 0, 0, squid_curtime);
        httpHeaderPutStrf(&rep->header, HDR_LOCATION, name, quoted_url);
        httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%d %s\n", err->httpStatus, "Access Denied");
    } else {
        MemBuf content = errorBuildContent(err);