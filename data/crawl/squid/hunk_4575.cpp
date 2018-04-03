         Packer p;
         str.Printf("%s %s HTTP/%d.%d\n",
                    RequestMethodStr[r->method],
-                   r->urlpath.size() ? r->urlpath.c_str() : "/",
+                   r->urlpath.size() ? r->urlpath.buf() : "/",
                    r->http_ver.major, r->http_ver.minor);
         packerToMemInit(&p, &str);
         r->header.packInto(&p);
