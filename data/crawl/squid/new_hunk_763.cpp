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
        httpBuildRequestHeader(request, entry, fwd->al, &hdr, flags);

        if (request->flags.pinned && request->flags.connectionAuth)
            request->flags.authSent = true;
        else if (hdr.has(HDR_AUTHORIZATION))
            request->flags.authSent = true;

        hdr.packInto(mb);
        hdr.clean();
    }
    /* append header terminator */
    mb->append(crlf, 2);
