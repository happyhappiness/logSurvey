     {
       (void) close (retsock);
       (void) close (sock);
-      error ("exporting to %s: %s",
+      error (NILF, "exporting to %s: %s",
              host ? host->h_name : inet_ntoa (permit.addr),
              Rpc_ErrorMessage (status));
       return 1;
