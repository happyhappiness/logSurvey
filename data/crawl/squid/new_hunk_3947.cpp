    HttpVersion httpver(1, 0);
    mb->Printf("%s %s HTTP/%d.%d\r\n",
               RequestMethodStr(request->method),
               request->urlpath.size() ? request->urlpath.termedBuf() : "/",
               httpver.major,httpver.minor);
    /* build and pack headers */
    {
