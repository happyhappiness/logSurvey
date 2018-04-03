 void
 snmpConnectionOpen(void)
 {
-    struct addrinfo *xaddr = NULL;
-    int x;
-
     debugs(49, 5, "snmpConnectionOpen: Called");
 
     if (Config.Port.snmp > 0) {
         Config.Addrs.snmp_incoming.SetPort(Config.Port.snmp);
-        enter_suid();
-        theInSnmpConnection = comm_open_listener(SOCK_DGRAM,
-                              IPPROTO_UDP,
-                              Config.Addrs.snmp_incoming,
-                              COMM_NONBLOCKING,
-                              "SNMP Port");
-        leave_suid();
 
-        if (theInSnmpConnection < 0)
-            fatal("Cannot open SNMP Port");
+        AsyncCall::Pointer call = asyncCall(49, 2,
+                                            "snmpIncomingConnectionOpened",
+                                            SnmpListeningStartedDialer(&snmpIncomingConnectionOpened));
 
-        commSetSelect(theInSnmpConnection, COMM_SELECT_READ, snmpHandleUdp, NULL, 0);
-
-        debugs(1, 1, "Accepting SNMP messages on " << Config.Addrs.snmp_incoming << ", FD " << theInSnmpConnection << ".");
+        Ipc::StartListening(SOCK_DGRAM,
+                            IPPROTO_UDP,
+                            Config.Addrs.snmp_incoming,
+                            COMM_NONBLOCKING,
+                            Ipc::fdnInSnmpSocket, call);
 
         if (!Config.Addrs.snmp_outgoing.IsNoAddr()) {
             Config.Addrs.snmp_outgoing.SetPort(Config.Port.snmp);
-            enter_suid();
-            theOutSnmpConnection = comm_open_listener(SOCK_DGRAM,
-                                   IPPROTO_UDP,
-                                   Config.Addrs.snmp_outgoing,
-                                   COMM_NONBLOCKING,
-                                   "SNMP Port");
-            leave_suid();
 
-            if (theOutSnmpConnection < 0)
-                fatal("Cannot open Outgoing SNMP Port");
+            AsyncCall::Pointer call = asyncCall(49, 2,
+                                                "snmpOutgoingConnectionOpened",
+                                                SnmpListeningStartedDialer(&snmpOutgoingConnectionOpened));
+
+            Ipc::StartListening(SOCK_DGRAM,
+                                IPPROTO_UDP,
+                                Config.Addrs.snmp_outgoing,
+                                COMM_NONBLOCKING,
+                                Ipc::fdnOutSnmpSocket, call);
+        }
+    }
+}
+
+static void
+snmpIncomingConnectionOpened(int fd, int errNo)
+{
+    theInSnmpConnection = fd;
+    if (theInSnmpConnection < 0)
+        fatal("Cannot open Incoming SNMP Port");
 
-            commSetSelect(theOutSnmpConnection,
-                          COMM_SELECT_READ,
-                          snmpHandleUdp,
-                          NULL, 0);
+    commSetSelect(theInSnmpConnection, COMM_SELECT_READ, snmpHandleUdp, NULL,
+                  0);
 
-            debugs(1, 1, "Outgoing SNMP messages on " << Config.Addrs.snmp_outgoing << ", FD " << theOutSnmpConnection << ".");
+    debugs(1, 1, "Accepting SNMP messages on " << Config.Addrs.snmp_incoming <<
+           ", FD " << theInSnmpConnection << ".");
 
-            fd_note(theOutSnmpConnection, "Outgoing SNMP socket");
+    if (Config.Addrs.snmp_outgoing.IsNoAddr())
+        theOutSnmpConnection = theInSnmpConnection;
+}
+
+static void
+snmpOutgoingConnectionOpened(int fd, int errNo)
+{
+    theOutSnmpConnection = fd;
+    if (theOutSnmpConnection < 0)
+        fatal("Cannot open Outgoing SNMP Port");
+
+    commSetSelect(theOutSnmpConnection, COMM_SELECT_READ, snmpHandleUdp, NULL,
+                  0);
+
+    debugs(1, 1, "Outgoing SNMP messages on " << Config.Addrs.snmp_outgoing <<
+           ", FD " << theOutSnmpConnection << ".");
+
+    {
+        struct addrinfo *xaddr = NULL;
+        int x;
 
-            fd_note(theInSnmpConnection, "Incoming SNMP socket");
-        } else {
-            theOutSnmpConnection = theInSnmpConnection;
-        }
 
         theOutSNMPAddr.SetEmpty();
 
