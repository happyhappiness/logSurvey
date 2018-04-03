            break;
        }
        if (NULL != request) {
            String urlpath_or_slash;

            if (request->urlpath.size() != 0)
                urlpath_or_slash = request->urlpath;
            else
                urlpath_or_slash = "/";

            mb.appendf(SQUIDSBUFPH " " SQUIDSTRINGPH " %s/%d.%d\n",
                       SQUIDSBUFPRINT(request->method.image()),
                       SQUIDSTRINGPRINT(urlpath_or_slash),
                       AnyP::ProtocolType_str[request->http_ver.protocol],
                       request->http_ver.major, request->http_ver.minor);
            request->header.packInto(&mb, true); //hide authorization data
        } else if (request_hdrs) {
            p = request_hdrs;
        } else {
