     reply->sline.set(httpVersion, httpStatus);
 
     HttpHeader &header = reply->header;
-    header.putTime(HDR_DATE, squid_curtime);
+    header.putTime(Http::HdrType::DATE, squid_curtime);
     {
         HttpHdrCc cc;
         cc.Private(String());
         header.putCc(&cc);
     }
     if (ftpStatus > 0)
-        header.putInt(HDR_FTP_STATUS, ftpStatus);
+        header.putInt(Http::HdrType::FTP_STATUS, ftpStatus);
     if (ftpReason)
-        header.putStr(HDR_FTP_REASON, ftpReason);
+        header.putStr(Http::HdrType::FTP_REASON, ftpReason);
     if (clen >= 0)
-        header.putInt64(HDR_CONTENT_LENGTH, clen);
+        header.putInt64(Http::HdrType::CONTENT_LENGTH, clen);
     reply->hdrCacheInit();
     return reply;
 }
