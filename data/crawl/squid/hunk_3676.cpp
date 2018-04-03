 }
 
 bool
-HttpReply::sanityCheckStartLine(MemBuf *buf, http_status *error)
+HttpReply::sanityCheckStartLine(MemBuf *buf, const size_t hdr_len, http_status *error)
 {
     fatal ("Not implemented");
     return false;
