         url = entry->url();
     else
         url = request->urlpath.termedBuf();
-    mb->Printf("%s %s HTTP/%d.%d\r\n",
+    mb->Printf("%s %s %s/%d.%d\r\n",
                RequestMethodStr(request->method),
                url && *url ? url : "/",
+               AnyP::ProtocolType_str[httpver.protocol],
                httpver.major,httpver.minor);
     /* build and pack headers */
     {
