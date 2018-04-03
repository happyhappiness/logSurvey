                  ThisCache);
         strListAdd(&strVia, bbuf, ',');
         hdr->delById(HDR_VIA);
-        hdr->putStr(HDR_VIA, strVia.unsafeBuf());
+        hdr->putStr(HDR_VIA, strVia.termedBuf());
     }
     /* Signal keep-alive if needed */
     hdr->putStr(http->flags.accel ? HDR_CONNECTION : HDR_PROXY_CONNECTION,
