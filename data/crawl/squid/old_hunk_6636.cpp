	}
    }
    storeBuffer(e);
#if 0				/* old code */
    storeAppendPrintf(e, "HTTP/1.0 200 Gatewaying\r\n");
    reply->code = 200;
    reply->version = 1.0;
    storeAppendPrintf(e, "Date: %s\r\n", mkrfc1123(squid_curtime));
    reply->date = squid_curtime;
    storeAppendPrintf(e, "MIME-Version: 1.0\r\n");
    storeAppendPrintf(e, "Server: Squid %s\r\n", version_string);
    if (ftpState->size > 0) {
	storeAppendPrintf(e, "Content-Length: %d\r\n", ftpState->size);
	reply->content_length = ftpState->size;
    }
    if (mime_type) {
	storeAppendPrintf(e, "Content-Type: %s\r\n", mime_type);
	xstrncpy(reply->content_type, mime_type, HTTP_REPLY_FIELD_SZ);
    }
    if (mime_enc)
	storeAppendPrintf(e, "Content-Encoding: %s\r\n", mime_enc);
    if (ftpState->mdtm > 0) {
	storeAppendPrintf(e, "Last-Modified: %s\r\n", mkrfc1123(ftpState->mdtm));
	reply->last_modified = ftpState->mdtm;
    }
    storeAppendPrintf(e, "\r\n");
#else
    httpReplyReset(reply);
    /* set standard stuff */
    httpReplySetHeaders(reply, 1.0, HTTP_OK, "Gatewaying",
