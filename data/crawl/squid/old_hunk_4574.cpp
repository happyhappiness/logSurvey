    /* Append VIA */
    {
        LOCAL_ARRAY(char, bbuf, MAX_URL + 32);
        string strVia;
       	hdr->getList(HDR_VIA, &strVia);
        snprintf(bbuf, sizeof(bbuf), "%d.%d %s",
                 reply->sline.version.major,
                 reply->sline.version.minor,
                 ThisCache);
        strListAdd(&strVia, bbuf, ',');
        hdr->delById(HDR_VIA);
        hdr->putStr(HDR_VIA, strVia.c_str());
    }
    /* Signal keep-alive if needed */
    hdr->putStr(http->flags.accel ? HDR_CONNECTION : HDR_PROXY_CONNECTION,
