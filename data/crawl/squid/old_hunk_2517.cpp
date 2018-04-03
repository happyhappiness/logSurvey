            else
                urlpath_or_slash = "/";

            mb.Printf("%s " SQUIDSTRINGPH " HTTP/%d.%d\n",
                      RequestMethodStr(request->method),
                      SQUIDSTRINGPRINT(urlpath_or_slash),
                      request->http_ver.major, request->http_ver.minor);
            packerToMemInit(&pck, &mb);
            request->header.packInto(&pck);
