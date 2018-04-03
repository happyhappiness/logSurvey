 void
 Ftp::Client::ctrlClosed(const CommCloseCbParams &io)
 {
-    debugs(9, 4, HERE);
+    debugs(9, 4, status());
     ctrl.clear();
     mustStop("Ftp::Client::ctrlClosed");
 }
 
 void
 Ftp::Client::timeout(const CommTimeoutCbParams &io)
 {
-    debugs(9, 4, HERE << io.conn << ": '" << entry->url() << "'" );
+    debugs(9, 4, io.conn << ": '" << entry->url() << "'" );
 
     if (abortOnBadEntry("entry went bad while waiting for a timeout"))
         return;
