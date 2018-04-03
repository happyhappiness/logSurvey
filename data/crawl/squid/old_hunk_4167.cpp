    /* Filter unproxyable authentication types */

    if (http->logType != LOG_TCP_DENIED &&
	    (hdr->has(HDR_WWW_AUTHENTICATE) || hdr->has(HDR_PROXY_AUTHENTICATE))) {
        HttpHeaderPos pos = HttpHeaderInitPos;
        HttpHeaderEntry *e;

        int headers_deleted = 0;
        while ((e = hdr->getEntry(&pos))) {
            if (e->id == HDR_WWW_AUTHENTICATE || e->id == HDR_PROXY_AUTHENTICATE) {
                const char *value = e->value.buf();

                if ((strncasecmp(value, "NTLM", 4) == 0 &&
                        (value[4] == '\0' || value[4] == ' '))
                        ||
                        (strncasecmp(value, "Negotiate", 9) == 0 &&
                         (value[9] == '\0' || value[9] == ' ')))
                            hdr->delAt(pos, headers_deleted);
            }
        }
        if (headers_deleted)
            hdr->refreshMask();
    }

