             }
             fprintf(stdout, "AF %s %s\n", "AA==", user);
             if (debug)
-                fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM,
+                fprintf(stderr, "%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM,
                         "AA==", user);
             if (log)
-                fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(),
+                fprintf(stderr, "%s| %s: INFO: User %s authenticated\n", LogTime(),
                         PROGRAM, user);
 
         }