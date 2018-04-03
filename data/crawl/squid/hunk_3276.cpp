         if (retval == PAM_SUCCESS && !no_acct_mgmt)
             retval = pam_acct_mgmt(pamh, 0);
         if (retval == PAM_SUCCESS) {
-            fprintf(stdout, "OK\n");
+            SEND_OK("");
         } else {
 error:
-            fprintf(stdout, "ERR\n");
+            SEND_ERR("");
         }
         /* cleanup */
         retval = PAM_SUCCESS;
