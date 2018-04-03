
    /* additional info */
    if (mime_enc)
        httpHeaderPutStr(&reply->header, HDR_CONTENT_ENCODING, mime_enc);

#if ICAP_CLIENT

