     /* put boundary */
     debug(33, 5) ("clientPackRangeHdr: appending boundary: %s\n", boundary.buf());
     /* rfc2046 requires to _prepend_ boundary with <crlf>! */
-    memBufPrintf(mb, "\r\n--%s\r\n", boundary.buf());
+    mb->Printf("\r\n--%s\r\n", boundary.buf());
 
     /* stuff the header with required entries and pack it */
 
