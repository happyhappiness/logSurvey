     addr = Config.Addrs.udp_incoming;
     addr.SetPort(port);
 
+    if (!Ip::EnableIpv6 && !addr.SetIPv4()) {
+        debugs(12, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << addr << " is not an IPv4 address.");
+        fatal("ICP port cannot be opened.");
+    }
+
     AsyncCall::Pointer call = asyncCall(12, 2,
                                         "icpIncomingConnectionOpened",
                                         IcpListeningStartedDialer(&icpIncomingConnectionOpened, addr));
