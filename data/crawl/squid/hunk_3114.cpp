     if ( !addr.IsNoAddr() ) {
         enter_suid();
         addr.SetPort(port);
+
+        if (!Ip::EnableIpv6 && !addr.SetIPv4()) {
+            debugs(49, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << addr << " is not an IPv4 address.");
+            fatal("ICP port cannot be opened.");
+        }
+
         theOutIcpConnection = comm_open_listener(SOCK_DGRAM,
                               IPPROTO_UDP,
                               addr,
