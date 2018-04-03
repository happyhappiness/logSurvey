         Ip::Address outgoingAddr = Config.Addrs.udp_outgoing;
         outgoingAddr.SetPort(Config.Port.htcp);
 
+        if (!Ip::EnableIpv6 && !outgoingAddr.SetIPv4()) {
+            debugs(31, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << outgoingAddr << " is not an IPv4 address.");
+            fatal("HTCP port cannot be opened.");
+        }
         enter_suid();
         htcpOutSocket = comm_open_listener(SOCK_DGRAM,
                                            IPPROTO_UDP,
