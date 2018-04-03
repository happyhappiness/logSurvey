         int fsize = 0;
         struct addrinfo *AI = NULL;
 
-        if (opt_verbose)
-            fprintf(stderr, "Resolving... %s\n", hostname);
+        debugVerbose(2, "Resolving... " << hostname);
 
         /* Connect to the server */
 
         if (localhost) {
             if ( !iaddr.GetHostByName(localhost) ) {
-                fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", localhost);
+                std::cerr << "ERROR: Cannot resolve " << localhost << ": Host unknown." << std::endl;
                 exit(1);
             }
         } else {
             /* Process the remote host name to locate the Protocol required
                in case we are being asked to link to another version of squid */
             if ( !iaddr.GetHostByName(hostname) ) {
-                fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", hostname);
+                std::cerr << "ERROR: Cannot resolve " << hostname << ": Host unknown." << std::endl;
                 exit(1);
             }
         }
 
         iaddr.getAddrInfo(AI);
         if ((conn = socket(AI->ai_family, AI->ai_socktype, 0)) < 0) {
-            perror("client: socket");
+            std::cerr << "ERROR: could not open socket to " << iaddr << std::endl;
             Ip::Address::FreeAddrInfo(AI);
             exit(1);
         }
         Ip::Address::FreeAddrInfo(AI);
 
         if (localhost && client_comm_bind(conn, iaddr) < 0) {
-            perror("client: bind");
+            std::cerr << "ERROR: could not bind socket to " << iaddr << std::endl;
             exit(1);
         }
 
         iaddr.setEmpty();
         if ( !iaddr.GetHostByName(hostname) ) {
-            fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", hostname);
+            std::cerr << "ERROR: Cannot resolve " << hostname << ": Host unknown." << std::endl;
             exit(1);
         }
 
         iaddr.port(port);
 
-        if (opt_verbose) {
-            char ipbuf[MAX_IPSTRLEN];
-            fprintf(stderr, "Connecting... %s(%s)\n", hostname, iaddr.toStr(ipbuf, MAX_IPSTRLEN));
-        }
+        debugVerbose(2, "Connecting... " << hostname << " (" << iaddr << ")");
 
         if (client_comm_connect(conn, iaddr, ping ? &tv1 : NULL) < 0) {
             char hostnameBuf[MAX_IPSTRLEN];
             iaddr.toUrl(hostnameBuf, MAX_IPSTRLEN);
-            if (errno == 0) {
-                fprintf(stderr, "client: ERROR: Cannot connect to %s: Host unknown.\n", hostnameBuf);
-            } else {
-                char tbuf[BUFSIZ];
-                snprintf(tbuf, BUFSIZ, "client: ERROR: Cannot connect to %s", hostnameBuf);
-                perror(tbuf);
-            }
+            std::cerr << "ERROR: Cannot connect to " << hostnameBuf
+                      << (!errno ?": Host unknown." : "") << std::endl;
             exit(1);
         }
-        if (opt_verbose) {
-            char ipbuf[MAX_IPSTRLEN];
-            fprintf(stderr, "Connected to: %s (%s)\n", hostname, iaddr.toStr(ipbuf, MAX_IPSTRLEN));
-        }
+        debugVerbose(2, "Connected to: " << hostname << " (" << iaddr << ")");
 
         /* Send the HTTP request */
-        fprintf(stderr, "Sending HTTP request ... ");
+        debugVerbose(2, "Sending HTTP request ... ");
         bytesWritten = mywrite(conn, msg, strlen(msg));
 
         if (bytesWritten < 0) {
-            perror("client: ERROR: write");
+            std::cerr << "ERROR: write" << std::endl;
             exit(1);
         } else if ((unsigned) bytesWritten != strlen(msg)) {
-            fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
+            std::cerr << "ERROR: Cannot send request?: " << std::endl << msg << std::endl;
             exit(1);
         }
-        fprintf(stderr, "done.\n");
+        debugVerbose(2, "done.");
 
         if (put_file) {
-            fprintf(stderr, "Sending HTTP request payload ... ");
+            debugVerbose(1, "Sending HTTP request payload ...");
             int x;
             lseek(put_fd, 0, SEEK_SET);
             while ((x = read(put_fd, buf, sizeof(buf))) > 0) {
