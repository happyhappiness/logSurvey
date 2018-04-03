 
     icpIncomingConn = new Comm::Connection;
     icpIncomingConn->local = Config.Addrs.udp_incoming;
-    icpIncomingConn->local.SetPort(port);
+    icpIncomingConn->local.port(port);
 
-    if (!Ip::EnableIpv6 && !icpIncomingConn->local.SetIPv4()) {
+    if (!Ip::EnableIpv6 && !icpIncomingConn->local.setIPv4()) {
         debugs(12, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << icpIncomingConn->local << " is not an IPv4 address.");
         fatal("ICP port cannot be opened.");
     }
     /* split-stack for now requires default IPv4-only ICP */
-    if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && icpIncomingConn->local.IsAnyAddr()) {
-        icpIncomingConn->local.SetIPv4();
+    if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && icpIncomingConn->local.isAnyAddr()) {
+        icpIncomingConn->local.setIPv4();
     }
 
     AsyncCall::Pointer call = asyncCall(12, 2,
