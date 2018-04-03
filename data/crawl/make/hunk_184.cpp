         {
           if (errno == 0)
             /* An errno value of zero means getloadavg is just unsupported.  */
-            error (NILF,
-                   _("cannot enforce load limits on this operating system"));
+            O (error, NILF,
+               _("cannot enforce load limits on this operating system"));
           else
             perror_with_name (_("cannot enforce load limit: "), "getloadavg");
         }
