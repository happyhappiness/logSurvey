             }
         }
         if (found)
-            printf("OK\n");
+            SEND_OK("");
         else {
-error:
-            printf("ERR\n");
+            SEND_ERR("");
         }
 
         if (ld != NULL) {
