     if (DnsSocketA < 0 && DnsSocketB < 0) {
         int port;
 
-        Ip::Address addr; // since we don't want to alter Config.Addrs.udp_* and dont have one of our own.
+        Ip::Address addrA; // since we don't want to alter Config.Addrs.udp_* and dont have one of our own.
 
         if (!Config.Addrs.udp_outgoing.IsNoAddr())
-            addr = Config.Addrs.udp_outgoing;
+            addrA = Config.Addrs.udp_outgoing;
         else
-            addr = Config.Addrs.udp_incoming;
+            addrA = Config.Addrs.udp_incoming;
 
-#if IPV6_SPECIAL_SPLITSTACK
-        Ip::Address addr4 = addr;
+        Ip::Address addrB = addrA;
+        addrA.SetIPv4();
 
-        if ( addr.IsAnyAddr() || addr.IsIPv6() ) {
-            debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addr);
+        if (Ip::EnableIpv6 && (addrB.IsAnyAddr() || addrB.IsIPv6())) {
+            debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addrB);
             DnsSocketB = comm_open_listener(SOCK_DGRAM,
                                             IPPROTO_UDP,
-                                            addr,
+                                            addrB,
                                             COMM_NONBLOCKING,
-                                            "DNS Socket v6");
+                                            "DNS Socket IPv6");
         }
 
-        if ( addr.IsAnyAddr() || addr.IsIPv4() ) {
-            addr4.SetIPv4();
-            debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addr4);
+        if (addrA.IsAnyAddr() || addrA.IsIPv4()) {
+            debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addrA);
             DnsSocketA = comm_open_listener(SOCK_DGRAM,
                                             IPPROTO_UDP,
-                                            addr4,
+                                            addrA,
                                             COMM_NONBLOCKING,
-                                            "DNS Socket v4");
+                                            "DNS Socket IPv4");
         }
-#else
-        debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addr);
-        DnsSocketA = comm_open_listener(SOCK_DGRAM,
-                                        IPPROTO_UDP,
-                                        addr,
-                                        COMM_NONBLOCKING,
-                                        "DNS Socket");
-#endif
 
         if (DnsSocketA < 0 && DnsSocketB < 0)
             fatal("Could not create a DNS socket");
 
         /* Ouch... we can't call functions using debug from a debug
          * statement. Doing so messes up the internal Debug::level
          */
-#if IPV6_SPECIAL_SPLITSTACK
         if (DnsSocketB >= 0) {
             port = comm_local_port(DnsSocketB);
-            debugs(78, 1, "DNS Socket created at " << addr << ", FD " << DnsSocketB);
+            debugs(78, 1, "DNS Socket created at " << addrB << ", FD " << DnsSocketB);
         }
-#endif
         if (DnsSocketA >= 0) {
             port = comm_local_port(DnsSocketA);
-#if IPV6_SPECIAL_SPLITSTACK
-            debugs(78, 1, "DNS Socket created at " << addr4 << ", FD " << DnsSocketA);
-#else
-            debugs(78, 1, "DNS Socket created at " << addr << ", FD " << DnsSocketA);
-#endif
+            debugs(78, 1, "DNS Socket created at " << addrA << ", FD " << DnsSocketA);
         }
     }
 
