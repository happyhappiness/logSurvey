        url = urlCanonical(request);
    else
        url = request->urlpath.termedBuf();
    mb->appendf(SQUIDSBUFPH " %s %s/%d.%d\r\n",
                SQUIDSBUFPRINT(request->method.image()),
                url && *url ? url : "/",
                AnyP::ProtocolType_str[httpver.protocol],
                httpver.major,httpver.minor);
    /* build and pack headers */
    {
        HttpHeader hdr(hoRequest);
