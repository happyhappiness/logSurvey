 {
     Must(currentContentType == ContentType::ctAlert);
     const Alert alert(tkMessages);
-    debugs(83, 3, "level " << alert.level << " description " << alert.description);
+    debugs(83, (alert.fatal() ? 2:3),
+           "level " << static_cast<int>(alert.level) <<
+           " description " << static_cast<int>(alert.description));
     // we are currently ignoring Alert Protocol messages
 }
 
