     char buf[256];
     if (!hasEPRT) {
         snprintf(buf, sizeof(buf), "\"%*s\"", prependSpaces + 4, "EPRT");
-        featReply->header.putStr(HDR_FTP_PRE, buf);
+        featReply->header.putStr(Http::HdrType::FTP_PRE, buf);
     }
     if (!hasEPSV) {
         snprintf(buf, sizeof(buf), "\"%*s\"", prependSpaces + 4, "EPSV");
-        featReply->header.putStr(HDR_FTP_PRE, buf);
+        featReply->header.putStr(Http::HdrType::FTP_PRE, buf);
     }
 
     featReply->header.refreshMask();
