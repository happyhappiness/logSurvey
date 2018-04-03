 Ftp::Relay::sendCommand()
 {
     if (!fwd->request->header.has(HDR_FTP_COMMAND)) {
-        abortTransaction("Internal error: FTP gateway request with no command");
+        abortTransaction("Internal error: FTP relay request with no command");
         return;
     }
 
