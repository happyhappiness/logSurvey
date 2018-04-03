     ftpReadQuit,		/* SENT_QUIT */
     ftpReadTransferDone,	/* READING_DATA (RETR,LIST,NLST) */
     ftpWriteTransferDone,	/* WRITING_DATA (STOR) */
-    ftpReadMkdir		/* SENT_MKDIR */
+    ftpReadMkdir,		/* SENT_MKDIR */
+    NULL,			/* SENT_FEAT */
+    NULL,			/* SENT_PWD */
+    NULL,			/* SENT_CDUP*/
+    NULL,			/* SENT_DATA_REQUEST */
+    NULL			/* SENT_COMMAND */
 };
 
-/// handler called by Comm when FTP control channel is closed unexpectedly
-void
-FtpStateData::ctrlClosed(const CommCloseCbParams &io)
-{
-    debugs(9, 4, HERE);
-    ctrl.clear();
-    mustStop("FtpStateData::ctrlClosed");
-}
-
 /// handler called by Comm when FTP data channel is closed unexpectedly
 void
-FtpStateData::dataClosed(const CommCloseCbParams &io)
+Ftp::Gateway::dataClosed(const CommCloseCbParams &io)
 {
-    debugs(9, 4, HERE);
-    if (data.listenConn != NULL) {
-        data.listenConn->close();
-        data.listenConn = NULL;
-        // NP clear() does the: data.fd = -1;
-    }
-    data.clear();
+    Ftp::Client::dataClosed(io);
     failed(ERR_FTP_FAILURE, 0);
     /* failed closes ctrl.conn and frees ftpState */
 
