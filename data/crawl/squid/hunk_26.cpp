     serverPort = htons(DEFAULTPORT);
     if ( convertHostname(DEFAULTHOST,serverHost) == -1 ) {
         fprintf( stderr, "unable to resolve host %s!\n", DEFAULTHOST );
-       exit(EXIT_FAILURE);
+        exit(EXIT_FAILURE);
     }
 
     // setup line buffer