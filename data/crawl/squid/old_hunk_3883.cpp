    /* put boundary */
    debugs(33, 5, "clientPackRangeHdr: appending boundary: " << boundary);
    /* rfc2046 requires to _prepend_ boundary with <crlf>! */
    mb->Printf("\r\n--%.*s\r\n", boundary.psize(), boundary.rawBuf());

    /* stuff the header with required entries and pack it */

