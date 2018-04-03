 }
 
 static void
-htcpIncomingConnectionOpened(int fd, int errNo)
+htcpIncomingConnectionOpened(int)
 {
-    htcpInSocket = fd;
-
-    if (htcpInSocket < 0)
+    if (!Comm::IsConnOpen(htcpIncomingConn))
         fatal("Cannot open HTCP Socket");
 
-    Comm::SetSelect(htcpInSocket, COMM_SELECT_READ, htcpRecv, NULL, 0);
+    Comm::SetSelect(htcpIncomingConn->fd, COMM_SELECT_READ, htcpRecv, NULL, 0);
 
-    debugs(31, 1, "Accepting HTCP messages on port " << Config.Port.htcp << ", FD " << htcpInSocket << ".");
+    debugs(31, DBG_CRITICAL, "Accepting HTCP messages on " << htcpIncomingConn->local);
 
-    if (Config.Addrs.udp_outgoing.IsNoAddr())
-        htcpOutSocket = htcpInSocket;
+    if (Config.Addrs.udp_outgoing.IsNoAddr()) {
+        htcpOutgoingConn = htcpIncomingConn;
+        debugs(31, DBG_IMPORTANT, "Sending HTCP messages from " << htcpOutgoingConn->local);
+    }
 }
 
 int
