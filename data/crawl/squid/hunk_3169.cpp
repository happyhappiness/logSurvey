         groups[n] = NULL;
 
         if (NULL == username) {
-            fprintf(stderr, "Invalid Request\n");
-            goto error;
+            SEND_ERR("Invalid Request. No Username.");
+            continue;
         }
         rfc1738_unescape(username);
 
         if ((use_global ? Valid_Global_Groups(username, groups) : Valid_Local_Groups(username, groups))) {
-            printf("OK\n");
+            SEND_OK("");
         } else {
-error:
-            printf("ERR\n");
+            SEND_ERR("");
         }
-        err = 0;
     }
     return 0;
 }
