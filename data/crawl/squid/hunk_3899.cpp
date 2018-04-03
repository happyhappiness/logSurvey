 
     if (NULL != request) {
         Packer p;
-        str.Printf("%s %s HTTP/%d.%d\n",
+        String urlpath_or_slash;
+
+        if (request->urlpath.size() != 0)
+            urlpath_or_slash = request->urlpath;
+        else
+            urlpath_or_slash = "/";
+
+        str.Printf("%s " SQUIDSTRINGPH " HTTP/%d.%d\n",
                    RequestMethodStr(request->method),
-                   request->urlpath.size() ? request->urlpath.unsafeBuf() : "/",
+                   SQUIDSTRINGPRINT(urlpath_or_slash),
                    request->http_ver.major, request->http_ver.minor);
         packerToMemInit(&p, &str);
         request->header.packInto(&p);
