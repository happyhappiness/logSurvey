         }
     }
 
+    char buf[256];
     int insertedCount = 0;
     if (!hasEPRT) {
-        filteredHeader.putStr(HDR_FTP_PRE, "\" EPRT\"");
+        snprintf(buf, sizeof(buf), "\"%*s\"", prependSpaces + 4, "EPRT");
+        filteredHeader.putStr(HDR_FTP_PRE, buf);
         ++insertedCount;
     }
     if (!hasEPSV) {
-        filteredHeader.putStr(HDR_FTP_PRE, "\" EPSV\"");
+        snprintf(buf, sizeof(buf), "\"%*s\"", prependSpaces + 4, "EPSV");
+        filteredHeader.putStr(HDR_FTP_PRE, buf);
         ++insertedCount;
     }
 