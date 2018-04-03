   if (prev_fail || fclose_fail)
     {
       if (fclose_fail)
-        error (NILF, _("write error: %s"), strerror (errno));
+        perror_with_name (_("write error: stdout"), "");
       else
-        error (NILF, _("write error"));
+        O (error, NILF, _("write error: stdout"));
       exit (EXIT_FAILURE);
     }
 }
