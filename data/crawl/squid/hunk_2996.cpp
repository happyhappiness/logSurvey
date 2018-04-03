 htcpInit(void)
 {
     if (Config.Port.htcp <= 0) {
-        debugs(31, 1, "HTCP Disabled.");
+        debugs(31, DBG_IMPORTANT, "HTCP Disabled.");
         return;
     }
 
-    Ip::Address incomingAddr = Config.Addrs.udp_incoming;
-    incomingAddr.SetPort(Config.Port.htcp);
+    htcpIncomingConn = new Comm::Connection;
+    htcpIncomingConn->local = Config.Addrs.udp_incoming;
+    htcpIncomingConn->local.SetPort(Config.Port.htcp);
 
-    if (!Ip::EnableIpv6 && !incomingAddr.SetIPv4()) {
-        debugs(31, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << incomingAddr << " is not an IPv4 address.");
+    if (!Ip::EnableIpv6 && !htcpIncomingConn->local.SetIPv4()) {
+        debugs(31, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << htcpIncomingConn->local << " is not an IPv4 address.");
         fatal("HTCP port cannot be opened.");
     }
     /* split-stack for now requires default IPv4-only HTCP */
-    if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && incomingAddr.IsAnyAddr()) {
-        incomingAddr.SetIPv4();
+    if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && htcpIncomingConn->local.IsAnyAddr()) {
+        htcpIncomingConn->local.SetIPv4();
     }
 
     AsyncCall::Pointer call = asyncCall(31, 2,
