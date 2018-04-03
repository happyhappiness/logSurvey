     httpHeaderClean(&hdr);
 
     /* append <crlf> (we packed a header, not a reply) */
-    memBufPrintf(mb, "\r\n");
+    mb->Printf("\r\n");
 }
 
 /*
