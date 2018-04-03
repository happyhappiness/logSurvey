            httpHeaderPutStrf(&rep->header, HDR_LOCATION, name, quoted_url);
        }

        httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%d %s", err->httpStatus, "Access Denied");
    } else {
        MemBuf *content = errorBuildContent(err);
        rep->setHeaders(version, err->httpStatus, NULL, "text/html", content->contentSize(), 0, squid_curtime);