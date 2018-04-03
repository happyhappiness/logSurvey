{
    const int offset = mb->size;
    HttpVersion httpver(1, 0);
    memBufPrintf(mb, "%s %s HTTP/%d.%d\r\n",
                 RequestMethodStr[request->method],
                 request->urlpath.size() ? request->urlpath.buf() : "/",
                 httpver.major,httpver.minor);
    /* build and pack headers */
    {
        HttpHeader hdr(hoRequest);
