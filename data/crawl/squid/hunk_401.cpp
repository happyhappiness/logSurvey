     AsyncJob::callException(e);
 }
 
+void
+Ftp::Server::originDataCompletionCheckpoint()
+{
+    if (!master->userDataDone) {
+        debugs(33, 5, "Transfering from/to client not finished yet");
+        return;
+    }
+
+    completeDataExchange();
+}
+
+void Ftp::Server::userDataCompletionCheckpoint(int finalStatusCode)
+{
+    Must(!master->userDataDone);
+    master->userDataDone = finalStatusCode;
+
+    if (bodyParser)
+        finishDechunkingRequest(false);
+
+    // The origin control connection is gone, nothing to wait for
+    if (!Comm::IsConnOpen(pinning.serverConnection))
+        master->waitForOriginData = false;
+
+    if (master->waitForOriginData) {
+        // The completeDataExchange() is not called here unconditionally
+        // because we want to signal the FTP user that we are not fully
+        // done processing its data stream, even though all data bytes
+        // have been sent or received already.
+        debugs(33, 5, "Transfering from/to FTP server is not complete");
+        return;
+    }
+
+    completeDataExchange();
+}
+
+void Ftp::Server::completeDataExchange()
+{
+    writeCustomReply(master->userDataDone, master->userDataDone == 226 ? "Transfer complete" : "Server error; transfer aborted");
+    closeDataConnection();
+}
+
 /// Whether Squid FTP Relay supports a named feature (e.g., a command).
 static bool
 Ftp::SupportedCommand(const SBuf &name)
