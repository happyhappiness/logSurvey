     HttpHeader *hdr;
     sline.set(Http::ProtocolVersion(), status, NULL);
     hdr = &header;
-    hdr->putStr(HDR_SERVER, APP_FULLNAME);
-    hdr->putTime(HDR_DATE, squid_curtime);
-    hdr->putInt64(HDR_CONTENT_LENGTH, 0);
-    hdr->putStr(HDR_LOCATION, loc);
+    hdr->putStr(Http::HdrType::SERVER, APP_FULLNAME);
+    hdr->putTime(Http::HdrType::DATE, squid_curtime);
+    hdr->putInt64(Http::HdrType::CONTENT_LENGTH, 0);
+    hdr->putStr(Http::HdrType::LOCATION, loc);
     date = squid_curtime;
     content_length = 0;
 }
