
    /* put boundary */
    debugs(33, 5, "clientPackRangeHdr: appending boundary: " <<
           boundary.buf());
    /* rfc2046 requires to _prepend_ boundary with <crlf>! */
    mb->Printf("\r\n--%s\r\n", boundary.buf());

    /* stuff the header with required entries and pack it */

