                 *p = '\0';
             }
             fprintf(stdout, "AF %s %s\n", token, user);
-            debug((char *) "%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM, token, user);
+            debug((char *) "%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM, token, rfc1738_escape(user));
             if (log)
                 fprintf(stderr, "%s| %s: INFO: User %s authenticated\n", LogTime(),
-                        PROGRAM, user);
+                        PROGRAM, rfc1738_escape(user));
             goto cleanup;
         } else {
             if (check_gss_err(major_status, minor_status, "gss_accept_sec_context()", log))
