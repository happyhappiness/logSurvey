            Packer p;
            mb.Printf("%s %s HTTP/%d.%d\n",
                      RequestMethodStr[r->method],
                      r->urlpath.size() ? r->urlpath.buf() : "/",
                      r->http_ver.major, r->http_ver.minor);
            packerToMemInit(&p, &mb);
            r->header.packInto(&p);
