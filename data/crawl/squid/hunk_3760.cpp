 
     Config.Wccp2.address.SetPort(WCCP_PORT);
     theWccp2Connection = comm_open_listener(SOCK_DGRAM,
-                                   0,
-                                   Config.Wccp2.address,
-                                   COMM_NONBLOCKING,
-                                   "WCCPv2 Socket");
+                                            0,
+                                            Config.Wccp2.address,
+                                            COMM_NONBLOCKING,
+                                            "WCCPv2 Socket");
 
     if (theWccp2Connection < 0)
         fatal("Cannot open WCCP Port");
