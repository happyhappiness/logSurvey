     IpAddress incomingAddr = Config.Addrs.udp_incoming;
     incomingAddr.SetPort(Config.Port.htcp);
 
-    enter_suid();
-    htcpInSocket = comm_open_listener(SOCK_DGRAM,
+    AsyncCall::Pointer call = asyncCall(31, 2,
+        "htcpIncomingConnectionOpened",
+        HtcpListeningStartedDialer(&htcpIncomingConnectionOpened));
+
+    Ipc::StartListening(SOCK_DGRAM,
                                       IPPROTO_UDP,
                                       incomingAddr,
                                       COMM_NONBLOCKING,
-                                      "HTCP Socket");
-    leave_suid();
-
-    if (htcpInSocket < 0)
-        fatal("Cannot open HTCP Socket");
-
-    commSetSelect(htcpInSocket, COMM_SELECT_READ, htcpRecv, NULL, 0);
-
-    debugs(31, 1, "Accepting HTCP messages on port " << Config.Port.htcp << ", FD " << htcpInSocket << ".");
+                                      Ipc::fdnInHtcpSocket, call);
 
     if (!Config.Addrs.udp_outgoing.IsNoAddr()) {
         IpAddress outgoingAddr = Config.Addrs.udp_outgoing;
