     /* put boundary */
     debugs(33, 5, "clientPackRangeHdr: appending boundary: " << boundary);
     /* rfc2046 requires to _prepend_ boundary with <crlf>! */
-    mb->Printf("\r\n--%.*s\r\n", boundary.size(), boundary.rawBuf());
+    mb->Printf("\r\n--" SQUIDSTRINGPH "\r\n", SQUIDSTRINGPRINT(boundary));
 
     /* stuff the header with required entries and pack it */
 
