              Only print this message once no matter how many jobs are left.  */
           fflush (stdout);
           if (!printed)
-            error (NILF, _("*** Waiting for unfinished jobs...."));
+            O (error, NILF, _("*** Waiting for unfinished jobs...."));
           printed = 1;
         }
 
