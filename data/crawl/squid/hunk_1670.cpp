     return true;
 }
 
+bool
+FtpHandleEprtRequest(ClientSocketContext *context, String &cmd, String &params)
+{
+    debugs(11, 3, "Process an EPRT " << params);
+
+    const ConnStateData *connState = context->getConn();
+    if (connState->ftp.gotEpsvAll) {
+        FtpSetReply(context, 500, "Rejecting EPRT after EPSV ALL");
+        return false;
+    }
+
+    if (!params.size()) {
+        FtpSetReply(context, 501, "Missing parameter");
+        return false;
+    }
+
+    Ip::Address cltAddr;
+    if (!Ftp::ParseProtoIpPort(params.termedBuf(), cltAddr)) {
+        FtpSetReply(context, 501, "Invalid parameter");
+        return false;
+    }
+
+    if (!FtpCreateDataConnection(context, cltAddr))
+        return false;
+
+    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_EPRT, "FtpHandleEprtRequest");
+    FtpSetDataCommand(context);
+    return true; // forward our fake PASV request
+}
+
+bool
+FtpHandleEpsvRequest(ClientSocketContext *context, String &cmd, String &params)
+{
+    debugs(11, 3, "Process an EPSV command with params: " << params);
+    if (params.size() <= 0) {
+        // treat parameterless EPSV as "use the protocol of the ctrl conn"
+    } else if (params.caseCmp("ALL") == 0) {
+        ConnStateData *connState = context->getConn();
+        FtpSetReply(context, 200, "EPSV ALL ok");
+        connState->ftp.gotEpsvAll = true;
+        return false;
+    } else if (params.cmp("2") == 0) {
+        if (!Ip::EnableIpv6) {
+            FtpSetReply(context, 522, "Network protocol not supported, use (1)");
+            return false;
+        }
+    } else if (params.cmp("1") != 0) {
+        FtpSetReply(context, 501, "Unsupported EPSV parameter");
+        return false;
+    }
+
+    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_EPSV, "FtpHandleEpsvRequest");
+    FtpSetDataCommand(context);
+    return true; // forward our fake PASV request
+}
+
+
+// Convert client PORT, EPRT, PASV, or EPSV data command to Squid PASV command.
+// Squid server-side decides what data command to use on that side.
+void
+FtpSetDataCommand(ClientSocketContext *context)
+{
+    ClientHttpRequest *const http = context->http;
+    assert(http != NULL);
+    HttpRequest *const request = http->request;
+    assert(request != NULL);
+    HttpHeader &header = request->header;
+    header.delById(HDR_FTP_COMMAND);
+    header.putStr(HDR_FTP_COMMAND, "PASV");
+    header.delById(HDR_FTP_ARGUMENTS);
+    header.putStr(HDR_FTP_ARGUMENTS, "");
+    debugs(11, 5, "client data command converted to fake PASV");
+}
+
 /// check that client data connection is ready for future I/O or at least
 /// has a chance of becoming ready soon.
 bool
