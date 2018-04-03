         con->csock = -1;
 
       /* Second: Login with proper USER/PASS sequence.  */
-      logprintf (LOG_VERBOSE, _("Logging in as %s ... "), escnonprint (user));
+      logprintf (LOG_VERBOSE, _("Logging in as %s ... "), 
+                 quotearg_style (escape_quoting_style, user));
       if (opt.server_response)
         logputs (LOG_ALWAYS, "\n");
       err = ftp_login (csock, logname, passwd);
