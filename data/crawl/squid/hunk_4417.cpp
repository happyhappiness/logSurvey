     if (DnsSocket < 0) {
         int port;
 
-        struct IN_ADDR addr;
+        IPAddress addr;
 
-        if (Config.Addrs.udp_outgoing.s_addr != no_addr.s_addr)
+        if (!Config.Addrs.udp_outgoing.IsNoAddr())
             addr = Config.Addrs.udp_outgoing;
         else
             addr = Config.Addrs.udp_incoming;
 
         DnsSocket = comm_open(SOCK_DGRAM,
                               IPPROTO_UDP,
                               addr,
-                              0,
                               COMM_NONBLOCKING,
                               "DNS Socket");
 
+        debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addr);
+
         if (DnsSocket < 0)
             fatal("Could not create a DNS socket");
 
