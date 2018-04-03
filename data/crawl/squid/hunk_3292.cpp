 
         /* Check for invalid or blank entries */
         if ((username[0] == '\0') || (password[0] == '\0')) {
-            fprintf(stderr, "Invalid Request\n");
-            puts("ERR");
+            SEND_ERR("Invalid Request");
             fflush(stdout);
             continue;
         }
