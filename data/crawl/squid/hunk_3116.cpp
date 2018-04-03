         if (!Config.Addrs.snmp_outgoing.IsNoAddr()) {
             Config.Addrs.snmp_outgoing.SetPort(Config.Port.snmp);
 
+            if (!Ip::EnableIpv6 && !Config.Addrs.snmp_outgoing.SetIPv4()) {
+                debugs(49, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << Config.Addrs.snmp_outgoing << " is not an IPv4 address.");
+                fatal("SNMP port cannot be opened.");
+            }
             AsyncCall::Pointer call = asyncCall(49, 2,
                                                 "snmpOutgoingConnectionOpened",
                                                 SnmpListeningStartedDialer(&snmpOutgoingConnectionOpened));