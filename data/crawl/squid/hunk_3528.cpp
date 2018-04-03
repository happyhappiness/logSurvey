         iaddr.SetPort(port);
 
         if (client_comm_connect(conn, iaddr, ping ? &tv1 : NULL) < 0) {
-            char buf[MAX_IPSTRLEN];
-            iaddr.ToURL(buf, MAX_IPSTRLEN);
+            char hostnameBuf[MAX_IPSTRLEN];
+            iaddr.ToURL(hostnameBuf, MAX_IPSTRLEN);
             if (errno == 0) {
-                fprintf(stderr, "client: ERROR: Cannot connect to %s: Host unknown.\n", buf);
+                fprintf(stderr, "client: ERROR: Cannot connect to %s: Host unknown.\n", hostnameBuf);
             } else {
                 char tbuf[BUFSIZ];
-                snprintf(tbuf, BUFSIZ, "client: ERROR: Cannot connect to %s", buf);
+                snprintf(tbuf, BUFSIZ, "client: ERROR: Cannot connect to %s", hostnameBuf);
                 perror(tbuf);
             }
             exit(1);