 
             if (!FtpSupportedCommand(cmd))
                 filteredHeader.delAt(pos, deletedCount);
+
+            if (cmd == "EPRT")
+                hasEPRT = true;
+            else if (cmd == "EPSV")
+                hasEPSV = true;
         }
     }
 
-    if (deletedCount) {
+    int insertedCount = 0;
+    if (!hasEPRT) {
+        filteredHeader.putStr(HDR_FTP_PRE, "\" EPRT\"");
+        ++insertedCount;
+    }
+    if (!hasEPSV) {
+        filteredHeader.putStr(HDR_FTP_PRE, "\" EPSV\"");
+        ++insertedCount;
+    }
+
+    if (deletedCount || insertedCount) {
         filteredHeader.refreshMask();
-        debugs(33, 5, "deleted " << deletedCount);
+        debugs(33, 5, "deleted " << deletedCount << " inserted " << insertedCount);
     }
 
     FtpWriteForwardedReply(context, filteredReply);