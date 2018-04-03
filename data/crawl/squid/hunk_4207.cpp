         }
 
         iaddr.SetEmpty();
-         if( !iaddr.GetHostByName(hostname) ) {
+        if ( !iaddr.GetHostByName(hostname) ) {
             fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", hostname);
             exit(1);
         }
