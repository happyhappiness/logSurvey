/* build request prefix and append it to a given MemBuf;
 * return the length of the prefix */
mb_size_t
HttpStateData::buildRequestPrefix(HttpRequest * aRequest,
                                  HttpRequest * original_request,
                                  StoreEntry * sentry,
                                  MemBuf * mb,
                                  http_state_flags stateFlags)
{
    const int offset = mb->size;
    HttpVersion httpver(1, 0);
    mb->Printf("%s %s HTTP/%d.%d\r\n",
               RequestMethodStr(aRequest->method),
               aRequest->urlpath.size() ? aRequest->urlpath.termedBuf() : "/",
               httpver.major,httpver.minor);
    /* build and pack headers */
    {
        HttpHeader hdr(hoRequest);
        Packer p;
        httpBuildRequestHeader(aRequest, original_request, sentry, &hdr, stateFlags);

        if (aRequest->flags.pinned && aRequest->flags.connection_auth)
            aRequest->flags.auth_sent = 1;
        else if (hdr.has(HDR_AUTHORIZATION))
            aRequest->flags.auth_sent = 1;

        packerToMemInit(&p, mb);
        hdr.packInto(&p);
