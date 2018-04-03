
/* put terminating boundary for multiparts */
static void
clientPackTermBound(string boundary, MemBuf * mb)
{
    mb->Printf("\r\n--%s--\r\n", boundary.c_str());
    debugs(33, 6, "clientPackTermBound: buf offset: " << mb->size);
}

/* appends a "part" HTTP header (as in a multi-part/range reply) to the buffer */
static void
clientPackRangeHdr(const HttpReply * rep, const HttpHdrRangeSpec * spec, string boundary, MemBuf * mb)
{
    HttpHeader hdr(hoReply);
    Packer p;
    assert(rep);
    assert(spec);

    /* put boundary */
    debugs(33, 5, "clientPackRangeHdr: appending boundary: " << boundary);
    /* rfc2046 requires to _prepend_ boundary with <crlf>! */
    mb->Printf("\r\n--%s\r\n", boundary.c_str());

    /* stuff the header with required entries and pack it */

