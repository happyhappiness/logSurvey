 icpConnectionsOpen(void)
 {
     uint16_t port;
-    Ip::Address addr;
 
     if ((port = Config.Port.icp) <= 0)
         return;
 
-    addr = Config.Addrs.udp_incoming;
-    addr.SetPort(port);
+    icpIncomingConn = new Comm::Connection;
+    icpIncomingConn->local = Config.Addrs.udp_incoming;
+    icpIncomingConn->local.SetPort(port);
 
-    if (!Ip::EnableIpv6 && !addr.SetIPv4()) {
-        debugs(12, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << addr << " is not an IPv4 address.");
+    if (!Ip::EnableIpv6 && !icpIncomingConn->local.SetIPv4()) {
+        debugs(12, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << icpIncomingConn->local << " is not an IPv4 address.");
         fatal("ICP port cannot be opened.");
     }
     /* split-stack for now requires default IPv4-only ICP */
-    if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && addr.IsAnyAddr()) {
-        addr.SetIPv4();
+    if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && icpIncomingConn->local.IsAnyAddr()) {
+        icpIncomingConn->local.SetIPv4();
     }
 
     AsyncCall::Pointer call = asyncCall(12, 2,
                                         "icpIncomingConnectionOpened",
-                                        IcpListeningStartedDialer(&icpIncomingConnectionOpened, addr));
+                                        IcpListeningStartedDialer(&icpIncomingConnectionOpened));
 
     Ipc::StartListening(SOCK_DGRAM,
                         IPPROTO_UDP,
-                        addr,
-                        COMM_NONBLOCKING,
+                        icpIncomingConn,
                         Ipc::fdnInIcpSocket, call);
 
-    addr.SetEmpty(); // clear for next use.
-    addr = Config.Addrs.udp_outgoing;
-    if ( !addr.IsNoAddr() ) {
-        enter_suid();
-        addr.SetPort(port);
+    if ( !Config.Addrs.udp_outgoing.IsNoAddr() ) {
+        icpOutgoingConn = new Comm::Connection;
+        icpOutgoingConn->local = Config.Addrs.udp_outgoing;
+        icpOutgoingConn->local.SetPort(port);
 
-        if (!Ip::EnableIpv6 && !addr.SetIPv4()) {
-            debugs(49, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << addr << " is not an IPv4 address.");
+        if (!Ip::EnableIpv6 && !icpOutgoingConn->local.SetIPv4()) {
+            debugs(49, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << icpOutgoingConn->local << " is not an IPv4 address.");
             fatal("ICP port cannot be opened.");
         }
         /* split-stack for now requires default IPv4-only ICP */
-        if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && addr.IsAnyAddr()) {
-            addr.SetIPv4();
+        if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && icpOutgoingConn->local.IsAnyAddr()) {
+            icpOutgoingConn->local.SetIPv4();
         }
 
-        theOutIcpConnection = comm_open_listener(SOCK_DGRAM,
-                              IPPROTO_UDP,
-                              addr,
-                              COMM_NONBLOCKING,
-                              "ICP Port");
+        enter_suid();
+        comm_open_listener(SOCK_DGRAM, IPPROTO_UDP, icpOutgoingConn, "Outgoing ICP Port");
         leave_suid();
 
-        if (theOutIcpConnection < 0)
+        if (!Comm::IsConnOpen(icpOutgoingConn))
             fatal("Cannot open Outgoing ICP Port");
 
-        Comm::SetSelect(theOutIcpConnection, COMM_SELECT_READ, icpHandleUdp, NULL, 0);
+        debugs(12, DBG_CRITICAL, "Sending ICP messages from " << icpOutgoingConn->local);
 
-        debugs(12, 1, "Outgoing ICP messages on port " << addr.GetPort() << ", FD " << theOutIcpConnection << ".");
-
-        fd_note(theOutIcpConnection, "Outgoing ICP socket");
+        Comm::SetSelect(icpOutgoingConn->fd, COMM_SELECT_READ, icpHandleUdp, NULL, 0);
+        fd_note(icpOutgoingConn->fd, "Outgoing ICP socket");
         icpGetOutgoingIpAddress();
     }
 }
 
+// Ensure that we have the IP address(es) to use for Host ID.
+// The outgoing address is used as 'private' host ID used only on packets we send
 static void
 icpGetOutgoingIpAddress()
 {
     struct addrinfo *xai = NULL;
-    theOutICPAddr.SetEmpty();
-    theOutICPAddr.InitAddrInfo(xai);
-
-    if (getsockname(theOutIcpConnection, xai->ai_addr, &xai->ai_addrlen) < 0)
-        debugs(50, 1, "theOutIcpConnection FD " << theOutIcpConnection << ": getsockname: " << xstrerror());
+    theIcpPrivateHostID.SetEmpty();
+    theIcpPrivateHostID.InitAddrInfo(xai);
+    if (getsockname(icpOutgoingConn->fd, xai->ai_addr, &xai->ai_addrlen) < 0)
+        debugs(50, DBG_IMPORTANT, "ERROR: Unable to identify ICP host ID to use for " << icpOutgoingConn
+               << ": getsockname: " << xstrerror());
     else
-        theOutICPAddr = *xai;
-
-    theOutICPAddr.FreeAddrInfo(xai);
+        theIcpPrivateHostID = *xai;
+    theIcpPrivateHostID.FreeAddrInfo(xai);
 }
 
 static void
-icpIncomingConnectionOpened(int fd, int errNo, Ip::Address& addr)
+icpIncomingConnectionOpened(int errNo)
 {
-    theInIcpConnection = fd;
-
-    if (theInIcpConnection < 0)
+    if (!Comm::IsConnOpen(icpIncomingConn))
         fatal("Cannot open ICP Port");
 
-    Comm::SetSelect(theInIcpConnection, COMM_SELECT_READ, icpHandleUdp, NULL, 0);
+    Comm::SetSelect(icpIncomingConn->fd, COMM_SELECT_READ, icpHandleUdp, NULL, 0);
 
     for (const wordlist *s = Config.mcast_group_list; s; s = s->next)
-        ipcache_nbgethostbyname(s->key, mcastJoinGroups, NULL);
+        ipcache_nbgethostbyname(s->key, mcastJoinGroups, NULL); // XXX: pass the icpIncomingConn for mcastJoinGroups usage.
 
-    debugs(12, 1, "Accepting ICP messages at " << addr << ", FD " << theInIcpConnection << ".");
+    debugs(12, DBG_IMPORTANT, "Accepting ICP messages on " << icpIncomingConn->local);
 
-    fd_note(theInIcpConnection, "Incoming ICP socket");
+    fd_note(icpIncomingConn->fd, "Incoming ICP port");
 
     if (Config.Addrs.udp_outgoing.IsNoAddr()) {
-        theOutIcpConnection = theInIcpConnection;
+        icpOutgoingConn = icpIncomingConn;
+        debugs(12, DBG_IMPORTANT, "Sending ICP messages from " << icpOutgoingConn->local);
         icpGetOutgoingIpAddress();
     }
+
+    // Ensure that we have the IP address(es) to use for Host ID.
+    // The listening address is used as 'public' host ID which can be used to contact us
+    struct addrinfo *xai = NULL;
+    theIcpPublicHostID.InitAddrInfo(xai); // reset xai
+    if (getsockname(icpIncomingConn->fd, xai->ai_addr, &xai->ai_addrlen) < 0)
+        debugs(50, DBG_IMPORTANT, "ERROR: Unable to identify ICP host ID to use for " << icpIncomingConn
+               << ": getsockname: " << xstrerror());
+    else
+        theIcpPublicHostID = *xai;
+    theIcpPublicHostID.FreeAddrInfo(xai);
 }
 
 /**
