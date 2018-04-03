             Packer p;
             mb.Printf("%s %s HTTP/%d.%d\n",
                       RequestMethodStr(request->method),
-                      request->urlpath.size() ? request->urlpath.buf() : "/",
+                      request->urlpath.size() ? request->urlpath.unsafeBuf() : "/",
                       request->http_ver.major, request->http_ver.minor);
             packerToMemInit(&p, &mb);
             request->header.packInto(&p);
