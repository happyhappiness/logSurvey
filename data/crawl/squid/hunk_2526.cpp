     if (request->lastmod > -1)
         hdr_out->putTime(HDR_IF_MODIFIED_SINCE, request->lastmod);
 
-    bool we_do_ranges = decideIfWeDoRanges (orig_request);
+    bool we_do_ranges = decideIfWeDoRanges (request);
 
     String strConnection (hdr_in->getList(HDR_CONNECTION));
 
     while ((e = hdr_in->getEntry(&pos)))
-        copyOneHeaderFromClientsideRequestToUpstreamRequest(e, strConnection, request, orig_request, hdr_out, we_do_ranges, flags);
+        copyOneHeaderFromClientsideRequestToUpstreamRequest(e, strConnection, request, hdr_out, we_do_ranges, flags);
 
     /* Abstraction break: We should interpret multipart/byterange responses
      * into offset-length data, and this works around our inability to do so.
      */
-    if (!we_do_ranges && orig_request->multipartRangeRequest()) {
+    if (!we_do_ranges && request->multipartRangeRequest()) {
         /* don't cache the result */
-        orig_request->flags.cachable = 0;
+        request->flags.cachable = 0;
         /* pretend it's not a range request */
-        delete orig_request->range;
-        orig_request->range = NULL;
-        orig_request->flags.range = 0;
+        delete request->range;
+        request->range = NULL;
+        request->flags.range = 0;
     }
 
     /* append Via */
     if (Config.onoff.via) {
         String strVia;
         strVia = hdr_in->getList(HDR_VIA);
         snprintf(bbuf, BBUF_SZ, "%d.%d %s",
-                 orig_request->http_ver.major,
-                 orig_request->http_ver.minor, ThisCache);
+                 request->http_ver.major,
+                 request->http_ver.minor, ThisCache);
         strListAdd(&strVia, bbuf, ',');
         hdr_out->putStr(HDR_VIA, strVia.termedBuf());
         strVia.clean();
     }
 
-    if (orig_request->flags.accelerated) {
+    if (request->flags.accelerated) {
         /* Append Surrogate-Capabilities */
         String strSurrogate(hdr_in->getList(HDR_SURROGATE_CAPABILITY));
 #if USE_SQUID_ESI
