                 snprintf (tempbuf, sizeof(tempbuf), "%s %s %s",
                           "113", ThisCache,
                           "This cache hit is still fresh and more than 1 day old");
-                httpHeaderPutStr(hdr, HDR_WARNING, tempbuf);
+                hdr->putStr(HDR_WARNING, tempbuf);
             }
         }
 
     }
 
     /* Filter unproxyable authentication types */
     if (http->logType != LOG_TCP_DENIED &&
-            (httpHeaderHas(hdr, HDR_WWW_AUTHENTICATE) || httpHeaderHas(hdr, HDR_PROXY_AUTHENTICATE))) {
+            (hdr->has(HDR_WWW_AUTHENTICATE) || hdr->has(HDR_PROXY_AUTHENTICATE))) {
         HttpHeaderPos pos = HttpHeaderInitPos;
         HttpHeaderEntry *e;
 
-        while ((e = httpHeaderGetEntry(hdr, &pos))) {
+        while ((e = hdr->getEntry(&pos))) {
             if (e->id == HDR_WWW_AUTHENTICATE || e->id == HDR_PROXY_AUTHENTICATE) {
                 const char *value = e->value.buf();
 
