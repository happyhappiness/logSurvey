 
         iaddr.SetPort(port);
 
+        if (opt_verbose) {
+            char ipbuf[MAX_IPSTRLEN];
+            fprintf(stderr, "Connecting... %s(%s)\n", hostname, iaddr.NtoA(ipbuf, MAX_IPSTRLEN));
+        }
+
         if (client_comm_connect(conn, iaddr, ping ? &tv1 : NULL) < 0) {
             char hostnameBuf[MAX_IPSTRLEN];
             iaddr.ToURL(hostnameBuf, MAX_IPSTRLEN);
