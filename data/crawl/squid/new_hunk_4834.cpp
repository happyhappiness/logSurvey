    /* Append VIA */
    {
        LOCAL_ARRAY(char, bbuf, MAX_URL + 32);
        String strVia = hdr->getList(HDR_VIA);
        snprintf(bbuf, sizeof(bbuf), "%d.%d %s",
                 reply->sline.version.major,
                 reply->sline.version.minor,
                 ThisCache);
        strListAdd(&strVia, bbuf, ',');
        hdr->delById(HDR_VIA);
        hdr->putStr(HDR_VIA, strVia.buf());
        strVia.clean();
    }
    /* Signal keep-alive if needed */
    hdr->putStr(http->flags.accel ? HDR_CONNECTION : HDR_PROXY_CONNECTION,
                request->flags.proxy_keepalive ? "keep-alive" : "close");

#if ADD_X_REQUEST_URI
    /*