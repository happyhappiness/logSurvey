 
     debugs(80, 1, "Accepting WCCPv1 messages on " << Config.Wccp.address << ", FD " << theWccpConnection << ".");
 
-    Config.Wccp.router.GetAddrInfo(router,AF_INET);
 
-    if (connect(theWccpConnection, router->ai_addr, router->ai_addrlen))
-        fatal("Unable to connect WCCP out socket");
-
-    Config.Wccp.router.FreeAddrInfo(router);
+    // Sadly WCCP only does IPv4
 
-    Config.Wccp.address.InitAddrInfo(local);
+    struct sockaddr_in router;
+    Config.Wccp.router.GetSockAddr(router);
+    if (connect(theWccpConnection, &router, sizeof(router)))
+        fatal("Unable to connect WCCP out socket");
 
-    if (getsockname(theWccpConnection, local->ai_addr, &local->ai_addrlen))
+    struct sockaddr_in local;
+    memset(&local, '\0', sizeof(local));
+    socklen_t slen = sizeof(local);
+    if (getsockname(theWccpConnection, &local, &slen))
         fatal("Unable to getsockname on WCCP out socket");
 
-    local_ip = *local;
-
-    Config.Wccp.address.FreeAddrInfo(local);
+    local_ip = local;
 }
 
 