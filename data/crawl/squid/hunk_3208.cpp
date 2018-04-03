             err = 1;
         }
         if (err) {
-            if (debug)
-                fprintf(stderr, "%s| %s: ERROR: Oversized message\n", LogTime(),
-                        PROGRAM);
+            debug("%s| %s: ERROR: Oversized message\n", LogTime(), PROGRAM);
             fprintf(stdout, "BH Oversized message\n");
             err = 0;
             continue;
         }
 
-        if (debug)
-            fprintf(stderr, "%s| %s: DEBUG: Got '%s' from squid (length: %d).\n",
-                    LogTime(), PROGRAM, buf, length);
+        debug("%s| %s: DEBUG: Got '%s' from squid (length: %d).\n", LogTime(), PROGRAM, buf, length);
 
         if (buf[0] == '\0') {
-            if (debug)
-                fprintf(stderr, "%s| %s: ERROR: Invalid request\n", LogTime(),
-                        PROGRAM);
+            debug("%s| %s: ERROR: Invalid request\n", LogTime(), PROGRAM);
             fprintf(stdout, "BH Invalid request\n");
             continue;
         }
 
         if (strlen(buf) < 2) {
-            if (debug)
-                fprintf(stderr, "%s| %s: ERROR: Invalid request [%s]\n", LogTime(),
-                        PROGRAM, buf);
+            debug("%s| %s: ERROR: Invalid request [%s]\n", LogTime(), PROGRAM, buf);
             fprintf(stdout, "BH Invalid request\n");
             continue;
         }
