             /* delete old Content-Type, add ours */
             hdr->delById(HDR_CONTENT_TYPE);
             httpHeaderPutStrf(hdr, HDR_CONTENT_TYPE,
-                              "multipart/byteranges; boundary=\"%.*s\"",
-                              http->range_iter.boundary.psize(),
-                              http->range_iter.boundary.rawBuf());
+                              "multipart/byteranges; boundary=\"" SQUIDSTRINGPH "\"",
+                              SQUIDSTRINGPRINT(http->range_iter.boundary));
             /* Content-Length is not required in multipart responses
              * but it is always nice to have one */
             actual_clen = http->mRangeCLen();
