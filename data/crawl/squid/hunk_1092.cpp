                 strcpy(buff,tbuff);
             }
         } else {
-            free(token);
+            xfree(token);
             if (debug)
                 fprintf(stderr, "%s| %s: received Kerberos token\n",
                         LogTime(), PROGRAM);
