 
         if (NULL != request) {
             Packer p;
-            mb.Printf("%s %s HTTP/%d.%d\n",
+            String urlpath_or_slash;
+
+            if (request->urlpath.size() != 0)
+                urlpath_or_slash = request->urlpath;
+            else
+                urlpath_or_slash = "/";
+
+            mb.Printf("%s " SQUIDSTRINGPH " HTTP/%d.%d\n",
                       RequestMethodStr(request->method),
-                      request->urlpath.size() ? request->urlpath.unsafeBuf() : "/",
+                      SQUIDSTRINGPRINT(urlpath_or_slash),
                       request->http_ver.major, request->http_ver.minor);
             packerToMemInit(&p, &mb);
             request->header.packInto(&p);
