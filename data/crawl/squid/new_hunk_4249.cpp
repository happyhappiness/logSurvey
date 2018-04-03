        break;

    case 'p':
        if (request) {
            mb.Printf("%d", (int) request->port);
        } else {
            p = "[unknown port]";
        }

        break;

    case 'P':
        p = request ? ProtocolStr[request->protocol] : "[unknown protocol]";
        break;

    case 'R':

        if (NULL != request) {
            Packer p;
            mb.Printf("%s %s HTTP/%d.%d\n",
                      RequestMethodStr(request->method),
                      request->urlpath.size() ? request->urlpath.buf() : "/",
                      request->http_ver.major, request->http_ver.minor);
            packerToMemInit(&p, &mb);
            request->header.packInto(&p);
            packerClean(&p);
        } else if (request_hdrs) {
            p = request_hdrs;
        } else {
            p = "[no request]";
        }
