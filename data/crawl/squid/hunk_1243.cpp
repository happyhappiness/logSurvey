 #if USE_OPENSSL
     clientHttpsConnectionsOpen();
 #endif
+    Ftp::StartListening();
 
     if (NHttpSockets < 1)
-        fatal("No HTTP or HTTPS ports configured");
+        fatal("No HTTP, HTTPS, or FTP ports configured");
 }
 
 void
-clientHttpConnectionsClose(void)
+clientConnectionsClose()
 {
     for (AnyP::PortCfgPointer s = HttpPortList; s != NULL; s = s->next) {
         if (s->listenConn != NULL) {
