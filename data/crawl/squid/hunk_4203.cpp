         ftpReadMkdir		/* SENT_MKDIR */
     };
 
+/// handler called by Comm when FTP control channel is closed unexpectedly
+void 
+FtpStateData::ctrlClosed(const CommCloseCbParams &io)
+{
+    ctrl.clear();
+    deleteThis("FtpStateData::ctrlClosed");
+}
+
+/// handler called by Comm when FTP data channel is closed unexpectedly
 void 
-FtpStateData::ftpSocketClosed(const CommCloseCbParams &io)
+FtpStateData::dataClosed(const CommCloseCbParams &io)
 {
-    ctrl.fd = -1;
-    deleteThis("FtpStateData::ftpSocketClosed");
+    data.clear();
+    failed(ERR_FTP_FAILURE, 0); // or is it better to call abortTransaction()?
+    /* failed closes ctrl.fd and frees ftpState */
 }
 
 FtpStateData::FtpStateData(FwdState *theFwdState) : AsyncJob("FtpStateData"), ServerStateData(theFwdState)