   }
 #else
   {
-    struct hostent *hptr = gethostbyname (host);
+    struct hostent *hptr = gethostbyname_with_timeout (host, opt.timeout);
     if (!hptr)
       {
 	if (!silent)
-	  logprintf (LOG_VERBOSE, _("failed: %s.\n"), herrmsg (h_errno));
+	  {
+	    if (errno != ETIMEDOUT)
+	      logprintf (LOG_VERBOSE, _("failed: %s.\n"), herrmsg (h_errno));
+	    else
+	      logputs (LOG_VERBOSE, _("failed: timed out.\n"));
+	  }
 	return NULL;
       }
     /* Do all systems have h_addr_list, or is it a newer thing?  If
