            MemBuf redirect_location;
            redirect_location.init();
            DenyInfoLocation(name, request, redirect_location);
            httpHeaderPutStrf(&rep->header, Http::HdrType::LOCATION, "%s", redirect_location.content() );
        }

        httpHeaderPutStrf(&rep->header, Http::HdrType::X_SQUID_ERROR, "%d %s", httpStatus, "Access Denied");
    } else {
        MemBuf *content = BuildContent();
        rep->setHeaders(httpStatus, NULL, "text/html;charset=utf-8", content->contentSize(), 0, -1);
