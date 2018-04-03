      * but X-Request-URI is likely to be the very last header to ease use from a
      * debugger [hdr->entries.count-1].
      */
-    httpHeaderPutStr(hdr, HDR_X_REQUEST_URI,
-                     http->memOjbect()->url ? http->memObject()->url : http->uri);
+    hdr->putStr(HDR_X_REQUEST_URI,
+                http->memOjbect()->url ? http->memObject()->url : http->uri);
 
 #endif
 
