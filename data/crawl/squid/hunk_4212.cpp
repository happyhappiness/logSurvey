         ftpReadMkdir		/* SENT_MKDIR */
     };
 
-/// close handler called by Comm when FTP control channel is closed prematurely
+/// handler called by Comm when FTP control channel is closed unexpectedly
 void 
 FtpStateData::ctrlClosed(const CommCloseCbParams &io)
 {
     ctrl.clear();
     deleteThis("FtpStateData::ctrlClosed");
 }
 
-/// close handler called by Comm when FTP data channel is closed prematurely
+/// handler called by Comm when FTP data channel is closed unexpectedly
 void 
 FtpStateData::dataClosed(const CommCloseCbParams &io)
 {
     data.clear();
-    deleteThis("FtpStateData::dataClosed");
+    failed(ERR_FTP_FAILURE, 0); // or is it better to call abortTransaction()?
+    /* failed closes ctrl.fd and frees ftpState */
 }
 
 FtpStateData::FtpStateData(FwdState *theFwdState) : AsyncJob("FtpStateData"), ServerStateData(theFwdState)
