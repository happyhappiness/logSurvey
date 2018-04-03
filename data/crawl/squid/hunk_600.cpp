             /* generate boundary string */
             http->range_iter.boundary = http->rangeBoundaryStr();
             /* delete old Content-Type, add ours */
-            hdr->delById(HDR_CONTENT_TYPE);
-            httpHeaderPutStrf(hdr, HDR_CONTENT_TYPE,
+            hdr->delById(Http::HdrType::CONTENT_TYPE);
+            httpHeaderPutStrf(hdr, Http::HdrType::CONTENT_TYPE,
                               "multipart/byteranges; boundary=\"" SQUIDSTRINGPH "\"",
                               SQUIDSTRINGPRINT(http->range_iter.boundary));
             /* Content-Length is not required in multipart responses
