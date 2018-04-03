     Config.Wccp.address.SetPort(WCCP_PORT);
 
     theWccpConnection = comm_open_listener(SOCK_DGRAM,
-                                  IPPROTO_UDP,
-                                  Config.Wccp.address,
-                                  COMM_NONBLOCKING,
-                                  "WCCP Socket");
+                                           IPPROTO_UDP,
+                                           Config.Wccp.address,
+                                           COMM_NONBLOCKING,
+                                           "WCCP Socket");
 
     if (theWccpConnection < 0)
         fatal("Cannot open WCCP Port");
