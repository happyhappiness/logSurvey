                   NULL,
                   0);
 
-    debugs(80, 1, "Accepting WCCPv1 messages on port " << port << ", FD " << theWccpConnection << ".");
-
-
-    router_len = sizeof(router);
-
-    memset(&router, '\0', router_len);
+    debugs(80, 1, "Accepting WCCPv1 messages on " << Config.Wccp.address << ", FD " << theWccpConnection << ".");
 
-    router.sin_family = AF_INET;
+    Config.Wccp.router.GetAddrInfo(router,AF_INET);
 
-    router.sin_port = htons(port);
-
-    router.sin_addr = Config.Wccp.router;
-
-    if (connect(theWccpConnection, (struct sockaddr *) &router, router_len))
+    if (connect(theWccpConnection, router->ai_addr, router->ai_addrlen))
         fatal("Unable to connect WCCP out socket");
 
-    local_len = sizeof(local);
+    Config.Wccp.router.FreeAddrInfo(router);
 
-    memset(&local, '\0', local_len);
+    Config.Wccp.address.InitAddrInfo(local);
 
-    if (getsockname(theWccpConnection, (struct sockaddr *) &local, &local_len))
+    if (getsockname(theWccpConnection, local->ai_addr, &local->ai_addrlen))
         fatal("Unable to getsockname on WCCP out socket");
 
-    local_ip.s_addr = local.sin_addr.s_addr;
+    local_ip = *local;
+
+    Config.Wccp.address.FreeAddrInfo(local);
 }
 
 
