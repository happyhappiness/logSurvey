     theOutICPAddr.FreeAddrInfo(xai);
 }
 
+static void
+icpIncomingConnectionOpened(int fd, int errNo, IpAddress& addr)
+{
+    theInIcpConnection = fd;
+
+    if (theInIcpConnection < 0)
+        fatal("Cannot open ICP Port");
+
+    commSetSelect(theInIcpConnection,
+                  COMM_SELECT_READ,
+                  icpHandleUdp,
+                  NULL,
+                  0);
+
+    for (const wordlist *s = Config.mcast_group_list; s; s = s->next)
+        ipcache_nbgethostbyname(s->key, mcastJoinGroups, NULL);
+
+    debugs(12, 1, "Accepting ICP messages at " << addr << ", FD " << theInIcpConnection << ".");
+
+        fd_note(theInIcpConnection, "Incoming ICP socket");
+
+    if (Config.Addrs.udp_outgoing.IsNoAddr())
+        theOutIcpConnection = theInIcpConnection;
+}
+
 /**
  * icpConnectionShutdown only closes the 'in' socket if it is
  * different than the 'out' socket.
