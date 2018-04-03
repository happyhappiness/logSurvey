 #define LINESIZE 512
                 char line[LINESIZE];
                 while ( fgets( line, LINESIZE, rfile ) != NULL ) {
-                    lineno++;
+                    ++lineno;
                     int len = strlen(line)-1;
                     if ( len+2 >= LINESIZE ) {
                         fprintf( stderr, "%s:%lu: line too long, sorry.\n",
