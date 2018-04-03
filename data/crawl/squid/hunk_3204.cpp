         (void) fflush(p);
 
         if (pclose(p) == 0)
-            (void) printf("OK\n");
+            SEND_OK("");
         else
-            (void) printf("ERR\n");
-
+            SEND_ERR("");
     }				/* while (1) */
     return 0;
 }
