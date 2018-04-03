        url = entry->url();
    else
        url = request->urlpath.termedBuf();
    mb->Printf("%s %s HTTP/%d.%d\r\n",
               RequestMethodStr(request->method),
               url && *url ? url : "/",
               httpver.major,httpver.minor);
    /* build and pack headers */
    {
