         int fsize = 0;
         struct addrinfo *AI = NULL;
 
+        if (opt_verbose)
+            fprintf(stderr, "Resolving... %s\n", hostname);
+
         /* Connect to the server */
 
         if (localhost) {
