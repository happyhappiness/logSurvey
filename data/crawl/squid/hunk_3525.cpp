 /* build request prefix and append it to a given MemBuf;
  * return the length of the prefix */
 mb_size_t
-HttpStateData::buildRequestPrefix(HttpRequest * request,
-                                  HttpRequest * orig_request,
-                                  StoreEntry * entry,
+HttpStateData::buildRequestPrefix(HttpRequest * aRequest,
+                                  HttpRequest * original_request,
+                                  StoreEntry * sentry,
                                   MemBuf * mb,
-                                  http_state_flags flags)
+                                  http_state_flags stateFlags)
 {
     const int offset = mb->size;
     HttpVersion httpver(1, 0);
     mb->Printf("%s %s HTTP/%d.%d\r\n",
-               RequestMethodStr(request->method),
-               request->urlpath.size() ? request->urlpath.termedBuf() : "/",
+               RequestMethodStr(aRequest->method),
+               aRequest->urlpath.size() ? aRequest->urlpath.termedBuf() : "/",
                httpver.major,httpver.minor);
     /* build and pack headers */
     {
         HttpHeader hdr(hoRequest);
         Packer p;
-        httpBuildRequestHeader(request, orig_request, entry, &hdr, flags);
+        httpBuildRequestHeader(aRequest, original_request, sentry, &hdr, stateFlags);
 
-        if (request->flags.pinned && request->flags.connection_auth)
-            request->flags.auth_sent = 1;
+        if (aRequest->flags.pinned && aRequest->flags.connection_auth)
+            aRequest->flags.auth_sent = 1;
         else if (hdr.has(HDR_AUTHORIZATION))
-            request->flags.auth_sent = 1;
+            aRequest->flags.auth_sent = 1;
 
         packerToMemInit(&p, mb);
         hdr.packInto(&p);
