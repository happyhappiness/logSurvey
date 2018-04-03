 
   if (!hProcess)
     {
-      error (NILF, _("windows32_openpipe(): process_init_fd() failed\n"));
+      O (error, NILF, _("windows32_openpipe(): process_init_fd() failed\n"));
       return -1;
     }
 
