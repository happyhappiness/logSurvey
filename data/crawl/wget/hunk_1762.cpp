       if (unlink (lf))
         logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
       else
-        logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), lf);
+        logprintf (LOG_VERBOSE, _("Removed %s.\n"), quote (lf));
     }
   xfree (lf);
   con->cmd &= ~DO_LIST;
