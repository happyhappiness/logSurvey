 Ftp::Relay::sendCommand()
 {
     if (!fwd->request->header.has(Http::HdrType::FTP_COMMAND)) {
-        abortTransaction("Internal error: FTP relay request with no command");
+        abortAll("Internal error: FTP relay request with no command");
         return;
     }
 
