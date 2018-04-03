 
     Ipc::StartListening(SOCK_DGRAM,
                         IPPROTO_UDP,
-                        incomingAddr,
-                        COMM_NONBLOCKING,
+                        htcpIncomingConn,
                         Ipc::fdnInHtcpSocket, call);
 
     if (!Config.Addrs.udp_outgoing.IsNoAddr()) {
-        Ip::Address outgoingAddr = Config.Addrs.udp_outgoing;
-        outgoingAddr.SetPort(Config.Port.htcp);
+        htcpOutgoingConn = new Comm::Connection;
+        htcpOutgoingConn->local = Config.Addrs.udp_outgoing;
+        htcpOutgoingConn->local.SetPort(Config.Port.htcp);
 
-        if (!Ip::EnableIpv6 && !outgoingAddr.SetIPv4()) {
-            debugs(31, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << outgoingAddr << " is not an IPv4 address.");
+        if (!Ip::EnableIpv6 && !htcpOutgoingConn->local.SetIPv4()) {
+            debugs(31, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << htcpOutgoingConn->local << " is not an IPv4 address.");
             fatal("HTCP port cannot be opened.");
         }
         /* split-stack for now requires default IPv4-only HTCP */
-        if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && outgoingAddr.IsAnyAddr()) {
-            outgoingAddr.SetIPv4();
+        if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && htcpOutgoingConn->local.IsAnyAddr()) {
+            htcpOutgoingConn->local.SetIPv4();
         }
 
         enter_suid();
-        htcpOutSocket = comm_open_listener(SOCK_DGRAM,
-                                           IPPROTO_UDP,
-                                           outgoingAddr,
-                                           COMM_NONBLOCKING,
-                                           "Outgoing HTCP Socket");
+        comm_open_listener(SOCK_DGRAM, IPPROTO_UDP, htcpOutgoingConn, "Outgoing HTCP Socket");
         leave_suid();
 
-        if (htcpOutSocket < 0)
+        if (!Comm::IsConnOpen(htcpOutgoingConn))
             fatal("Cannot open Outgoing HTCP Socket");
 
-        Comm::SetSelect(htcpOutSocket, COMM_SELECT_READ, htcpRecv, NULL, 0);
+        Comm::SetSelect(htcpOutgoingConn->fd, COMM_SELECT_READ, htcpRecv, NULL, 0);
 
-        debugs(31, 1, "Outgoing HTCP messages on port " << Config.Port.htcp << ", FD " << htcpOutSocket << ".");
-
-        fd_note(htcpInSocket, "Incoming HTCP socket");
+        debugs(31, DBG_IMPORTANT, "Sending HTCP messages from " << htcpOutgoingConn->local);
     }
 
     if (!htcpDetailPool) {
