 	    CLOSE_INVALIDATE (sock);
 	}
       pconn.authorized = 0;
-      if (auth_finished || !(user && passwd))
-	{
-	  /* If we have tried it already, then there is not point
-	     retrying it.  */
-	  logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
-	}
-      else
+      if (!auth_finished && (user && passwd))
 	{
-	  /* IIS sometimes sends two instances of WWW-Authenticate
-	     header, one with the keyword "negotiate", and other with
-	     useful data.  Loop over all occurrences of this header
-	     and use the one we recognize.  */
+	  /* IIS sends multiple copies of WWW-Authenticate, one with
+	     the value "negotiate", and other(s) with data.  Loop over
+	     all the occurrences and pick the one we recognize.  */
 	  int wapos;
 	  const char *wabeg, *waend;
 	  char *www_authenticate = NULL;
