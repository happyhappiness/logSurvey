             }
         }
 
-        iaddr.GetAddrInfo(AI);
+        iaddr.getAddrInfo(AI);
         if ((conn = socket(AI->ai_family, AI->ai_socktype, 0)) < 0) {
             perror("client: socket");
-            iaddr.FreeAddrInfo(AI);
+            Ip::Address::FreeAddrInfo(AI);
             exit(1);
         }
-        iaddr.FreeAddrInfo(AI);
+        Ip::Address::FreeAddrInfo(AI);
 
         if (localhost && client_comm_bind(conn, iaddr) < 0) {
             perror("client: bind");
             exit(1);
         }
 
-        iaddr.SetEmpty();
+        iaddr.setEmpty();
         if ( !iaddr.GetHostByName(hostname) ) {
             fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", hostname);
             exit(1);
         }
 
-        iaddr.SetPort(port);
+        iaddr.port(port);
 
         if (opt_verbose) {
             char ipbuf[MAX_IPSTRLEN];
-            fprintf(stderr, "Connecting... %s(%s)\n", hostname, iaddr.NtoA(ipbuf, MAX_IPSTRLEN));
+            fprintf(stderr, "Connecting... %s(%s)\n", hostname, iaddr.toStr(ipbuf, MAX_IPSTRLEN));
         }
 
         if (client_comm_connect(conn, iaddr, ping ? &tv1 : NULL) < 0) {
             char hostnameBuf[MAX_IPSTRLEN];
-            iaddr.ToURL(hostnameBuf, MAX_IPSTRLEN);
+            iaddr.toUrl(hostnameBuf, MAX_IPSTRLEN);
             if (errno == 0) {
                 fprintf(stderr, "client: ERROR: Cannot connect to %s: Host unknown.\n", hostnameBuf);
             } else {
