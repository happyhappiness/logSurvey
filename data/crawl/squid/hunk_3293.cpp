         debug("Trying to validate; %s %s\n", username, password);
 
         if (Valid_User(username, password, NTGroup) == NTV_NO_ERROR)
-            puts("OK");
+            SEND_OK("");
         else
-            printf("ERR %s\n", errormsg);
-error:
+            SEND_ERR(errormsg);
         err = 0;
         fflush(stdout);
     }
