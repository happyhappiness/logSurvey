                 }
             } else {
                 // colon used, port is extra
-                *colon++ = 0;
+                *colon = 0;
+                ++colon;
                 if ( convertHostname(optarg,serverHost) == -1 ) {
                     fprintf( stderr, "unable to resolve host %s!\n", optarg );
                     exit(1);
