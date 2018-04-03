                                  http_state_flags stateFlags)
{
    const int offset = mb->size;
    HttpVersion httpver(1,1);
    mb->Printf("%s %s HTTP/%d.%d\r\n",
               RequestMethodStr(aRequest->method),
               aRequest->urlpath.size() ? aRequest->urlpath.termedBuf() : "/",
