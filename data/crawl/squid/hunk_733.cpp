 clientPackRangeHdr(const HttpReply * rep, const HttpHdrRangeSpec * spec, String boundary, MemBuf * mb)
 {
     HttpHeader hdr(hoReply);
-    Packer p;
     assert(rep);
     assert(spec);
 
     /* put boundary */
     debugs(33, 5, "clientPackRangeHdr: appending boundary: " << boundary);
     /* rfc2046 requires to _prepend_ boundary with <crlf>! */
-    mb->Printf("\r\n--" SQUIDSTRINGPH "\r\n", SQUIDSTRINGPRINT(boundary));
+    mb->appendf("\r\n--" SQUIDSTRINGPH "\r\n", SQUIDSTRINGPRINT(boundary));
 
     /* stuff the header with required entries and pack it */
 
