 	con->csock = -1;
 
       /* Second: Login with proper USER/PASS sequence.  */
-      logprintf (LOG_VERBOSE, _("Logging in as %s ... "), user);
+      logprintf (LOG_VERBOSE, _("Logging in as %s ... "), escnonprint (user));
       if (opt.server_response)
 	logputs (LOG_ALWAYS, "\n");
       err = ftp_login (csock, logname, passwd);
