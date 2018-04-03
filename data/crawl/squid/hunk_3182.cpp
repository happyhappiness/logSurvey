         }
 
         if (j > 0) {
-            printf("OK\n");
+            SEND_OK("");
         } else {
-error:
-            printf("ERR\n");
+            SEND_ERR("");
         }
     }
     return 0;
