    assert(spec);

    /* put boundary */
    debugs(33, 5, "clientPackRangeHdr: appending boundary: " <<
           boundary.unsafeBuf());
    /* rfc2046 requires to _prepend_ boundary with <crlf>! */
    mb->Printf("\r\n--%s\r\n", boundary.unsafeBuf());

    /* stuff the header with required entries and pack it */

