
    if (NULL != request) {
        Packer p;
        String urlpath_or_slash;

        if (request->urlpath.size() != 0)
            urlpath_or_slash = request->urlpath;
        else
            urlpath_or_slash = "/";

        str.Printf("%s " SQUIDSTRINGPH " HTTP/%d.%d\n",
                   RequestMethodStr(request->method),
                   SQUIDSTRINGPRINT(urlpath_or_slash),
                   request->http_ver.major, request->http_ver.minor);
        packerToMemInit(&p, &str);
        request->header.packInto(&p);
