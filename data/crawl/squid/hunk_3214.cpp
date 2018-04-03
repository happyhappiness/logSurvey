                 gss_display_name(&minor_status, client_name, &output_token,
                                  NULL);
 
-            if (check_gss_err(major_status, minor_status, "gss_display_name()",
-                              debug, log))
+            if (check_gss_err(major_status, minor_status, "gss_display_name()", log))
                 goto cleanup;
             /*
              *  Return dummy token AA. May need an extra return tag then AF
              */
             user = (char*)xmalloc(output_token.length + 1);
             if (user == NULL) {
-                if (debug)
-                    fprintf(stderr, "%s| %s: ERROR: Not enough memory\n", LogTime(),
-                            PROGRAM);
+                debug("%s| %s: ERROR: Not enough memory\n", LogTime(), PROGRAM);
                 fprintf(stdout, "BH Not enough memory\n");
                 goto cleanup;
             }
