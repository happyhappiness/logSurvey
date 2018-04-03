                 *p = '\0';
             }
             fprintf(stdout, "AF %s %s\n", token, user);
-            if (debug)
-                fprintf(stderr, "%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM, token,
-                        user);
+            debug("%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM, token, user);
             if (log)
                 fprintf(stderr, "%s| %s: INFO: User %s authenticated\n", LogTime(),
                         PROGRAM, user);
             goto cleanup;
         } else {
-            if (check_gss_err(major_status, minor_status,
-                              "gss_accept_sec_context()", debug, log))
+            if (check_gss_err(major_status, minor_status, "gss_accept_sec_context()", log))
                 goto cleanup;
             if (major_status & GSS_S_CONTINUE_NEEDED) {
-                if (debug)
-                    fprintf(stderr, "%s| %s: INFO: continuation needed\n", LogTime(),
-                            PROGRAM);
+                debug("%s| %s: INFO: continuation needed\n", LogTime(), PROGRAM);
                 fprintf(stdout, "NA %s\n", token);
                 goto cleanup;
             }
