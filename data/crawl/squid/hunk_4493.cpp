     hdr = &header;
     hdr->putStr(HDR_SERVER, full_appname_string);
     hdr->putTime(HDR_DATE, squid_curtime);
-    hdr->putInt(HDR_CONTENT_LENGTH, 0);
+    hdr->putInt64(HDR_CONTENT_LENGTH, 0);
     hdr->putStr(HDR_LOCATION, loc);
     date = squid_curtime;
     content_length = 0;
