        hdr->putStr(HDR_VIA, strVia.termedBuf());
    }
    /* Signal keep-alive if needed */
    hdr->putStr(http->flags.accel ? HDR_CONNECTION : HDR_PROXY_CONNECTION,
                request->flags.proxy_keepalive ? "keep-alive" : "close");

#if ADD_X_REQUEST_URI