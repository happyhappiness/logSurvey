 
             if (check_gss_err(major_status,minor_status,"gss_display_name()",debug,log) )
                 goto cleanup;
-            fprintf(stdout, "AF %s %s\n",token,(char *)output_token.value);
+            user=xmalloc(output_token.length+1);
+            if (user == NULL) {
+               if (debug)
+                  fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(), PROGRAM);
+               fprintf(stdout, "BH Not enough memory\n");
+               goto cleanup;
+            }
+            memcpy(user,output_token.value,output_token.length);
+            user[output_token.length]='\0';
+            fprintf(stdout, "AF %s %s\n",token,user);
             if (debug)
-                fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, token,(char *)output_token.value);
+                fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, token,user);
             if (log)
-                fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(), PROGRAM, (char *)output_token.value);
+                fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(), PROGRAM, user);
             goto cleanup;
         } else {
             if (check_gss_err(major_status,minor_status,"gss_accept_sec_context()",debug,log) )
