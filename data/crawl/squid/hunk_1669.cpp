 
     context->getConn()->ftp.dataConn = conn;
     context->getConn()->ftp.uploadAvailSize = 0;
+    return true;
+}
 
-    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_PORT, "FtpHandlePortRequest");
+#include "FtpServer.h" /* XXX: For Ftp::ParseIpPort() */
 
-    // convert client PORT command to Squid PASV command because Squid
-    // does not support active FTP transfers on the server side (yet?)
-    ClientHttpRequest *const http = context->http;
-    assert(http != NULL);
-    HttpRequest *const request = http->request;
-    assert(request != NULL);
-    HttpHeader &header = request->header;
-    header.delById(HDR_FTP_COMMAND);
-    header.putStr(HDR_FTP_COMMAND, "PASV");
-    header.delById(HDR_FTP_ARGUMENTS);
-    header.putStr(HDR_FTP_ARGUMENTS, "");
+bool
+FtpHandlePortRequest(ClientSocketContext *context, String &cmd, String &params)
+{
+    // TODO: Should PORT errors trigger FtpCloseDataConnection() cleanup?
+
+    const ConnStateData *connState = context->getConn();
+    if (connState->ftp.gotEpsvAll) {
+        FtpSetReply(context, 500, "Rejecting PORT after EPSV ALL");
+        return false;
+    }
+
+    if (!params.size()) {
+        FtpSetReply(context, 501, "Missing parameter");
+        return false;
+    }
+
+    Ip::Address cltAddr;
+    if (!Ftp::ParseIpPort(params.termedBuf(), NULL, cltAddr)) {
+        FtpSetReply(context, 501, "Invalid parameter");
+        return false;
+    }
+
+    if (!FtpCreateDataConnection(context, cltAddr))
+        return false;
+
+    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_PORT, "FtpHandlePortRequest");
+    FtpSetDataCommand(context);
     return true; // forward our fake PASV request
 }
 
