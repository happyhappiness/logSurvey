         }
         if (opt_verbose) {
             char ipbuf[MAX_IPSTRLEN];
-            fprintf(stderr, "Connected to: %s (%s)\n", hostname, iaddr.NtoA(ipbuf, MAX_IPSTRLEN));
+            fprintf(stderr, "Connected to: %s (%s)\n", hostname, iaddr.toStr(ipbuf, MAX_IPSTRLEN));
         }
 
         /* Send the HTTP request */
