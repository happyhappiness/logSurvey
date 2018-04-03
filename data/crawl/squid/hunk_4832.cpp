             /* generate boundary string */
             http->range_iter.boundary = http->rangeBoundaryStr();
             /* delete old Content-Type, add ours */
-            httpHeaderDelById(hdr, HDR_CONTENT_TYPE);
+            hdr->delById(HDR_CONTENT_TYPE);
             httpHeaderPutStrf(hdr, HDR_CONTENT_TYPE,
                               "multipart/byteranges; boundary=\"%s\"",
                               http->range_iter.boundary.buf());
