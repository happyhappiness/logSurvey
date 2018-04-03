 #if USE_OPENSSL
     clientHttpsConnectionsOpen();
 #endif
-    clientFtpConnectionsOpen();
+    Ftp::StartListening();
 
     if (NHttpSockets < 1)
         fatal("No HTTP, HTTPS or FTP ports configured");
