     if (Config.Port.snmp > 0) {
         Config.Addrs.snmp_incoming.SetPort(Config.Port.snmp);
         enter_suid();
-        theInSnmpConnection = comm_open(SOCK_DGRAM,
+        theInSnmpConnection = comm_open_listener(SOCK_DGRAM,
                                         IPPROTO_UDP,
                                         Config.Addrs.snmp_incoming,
                                         COMM_NONBLOCKING,
                                         "SNMP Port");
         leave_suid();
 
         if (theInSnmpConnection < 0)
-            fatal("Cannot open snmp Port");
+            fatal("Cannot open SNMP Port");
 
         commSetSelect(theInSnmpConnection, COMM_SELECT_READ, snmpHandleUdp, NULL, 0);
 
