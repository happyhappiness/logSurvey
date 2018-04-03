     while ( (pid = waitpid( -1, &status, WNOHANG )) > 0 ) {
         if ( WIFEXITED(status) ) {
             fprintf( stderr, "child (pid=%ld) reaped, status %d\n%c",
-                      (long) pid, WEXITSTATUS(status), 0 );
+                     (long) pid, WEXITSTATUS(status), 0 );
         } else if ( WIFSIGNALED(status) ) {
             fprintf( stderr, "child (pid=%ld) died on signal %d%s\n%c",
-                      (long) pid, WTERMSIG(status),
+                     (long) pid, WTERMSIG(status),
 #ifdef WCOREDUMP
-                      WCOREDUMP(status) ? " (core generated)" : "",
+                     WCOREDUMP(status) ? " (core generated)" : "",
 #else
-                      "",
+                     "",
 #endif
-                      0 );
+                     0 );
         } else {
             fprintf( stderr, "detected dead child (pid=%ld), status %d\n%c",
-                      (long) pid, status, 0 );
+                     (long) pid, status, 0 );
         }
     }
     errno = saveerr;