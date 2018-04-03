     if (Config.Port.snmp > 0) {
         Config.Addrs.snmp_incoming.SetPort(Config.Port.snmp);
 
+        if (!Ip::EnableIpv6 && !Config.Addrs.snmp_incoming.SetIPv4()) {
+            debugs(49, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << Config.Addrs.snmp_incoming << " is not an IPv4 address.");
+            fatal("SNMP port cannot be opened.");
+        }
         AsyncCall::Pointer call = asyncCall(49, 2,
                                             "snmpIncomingConnectionOpened",
                                             SnmpListeningStartedDialer(&snmpIncomingConnectionOpened));
