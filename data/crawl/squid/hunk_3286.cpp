 #endif
 
     if ( rc != SASL_OK ) {
-        fprintf( stderr, "error %d %s\n", rc, sasl_errstring(rc, NULL, NULL ));
-        fprintf( stdout, "ERR\n" );
+        fprintf(stderr, "FATAL: %d %s\n", rc, sasl_errstring(rc, NULL, NULL ));
         return 1;
     }
 
-    while ( fgets( line, sizeof( line ), stdin )) {
+    while ( fgets( line, HELPER_INPUT_BUFFER, stdin )) {
         username = &line[0];
         password = strchr( line, '\n' );
-        if ( !password) {
-            fprintf( stderr, "authenticator: Unexpected input '%s'\n", line );
-            fprintf( stdout, "ERR\n" );
+        if (!password) {
+            debug("ERROR: %s: Unexpected input '%s'\n", argv[0], line);
+            SEND_ERR("Unexpected Empty Input");
             continue;
         }
         *password = '\0';
         password = strchr ( line, ' ' );
-        if ( !password) {
-            fprintf( stderr, "authenticator: Unexpected input '%s'\n", line );
-            fprintf( stdout, "ERR\n" );
+        if (!password) {
+            debug("ERROR: %s: Unexpected input '%s' (no password)\n", argv[0], line );
+            SEND_ERR("No Password");
             continue;
         }
         *password++ = '\0';
