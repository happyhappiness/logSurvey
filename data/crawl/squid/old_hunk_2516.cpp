        else
            urlpath_or_slash = "/";

        str.Printf("%s " SQUIDSTRINGPH " HTTP/%d.%d\n",
                   RequestMethodStr(request->method),
                   SQUIDSTRINGPRINT(urlpath_or_slash),
                   request->http_ver.major, request->http_ver.minor);
        packerToMemInit(&pck, &str);
        request->header.packInto(&pck);
