     while (1) {
         if (fgets(buf, sizeof(buf) - 1, stdin) == NULL) {
             if (ferror(stdin)) {
-                if (debug)
-                    fprintf(stderr,
-                            "%s| %s: FATAL: fgets() failed! dying..... errno=%d (%s)\n",
-                            LogTime(), PROGRAM, ferror(stdin),
-                            strerror(ferror(stdin)));
+                debug("%s| %s: FATAL: fgets() failed! dying..... errno=%d (%s)\n",
+                      LogTime(), PROGRAM, ferror(stdin),
+                      strerror(ferror(stdin)));
 
                 fprintf(stdout, "BH input error\n");
                 exit(1);	/* BIIG buffer */
