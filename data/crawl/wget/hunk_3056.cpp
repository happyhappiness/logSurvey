 	  /* No luck.  */
 	  /* #### This message SUCKS.  We should see what was the
 	     reason that nothing was retrieved.  */
-	  logprintf (LOG_VERBOSE, _("No matches on pattern `%s'.\n"), u->file);
+	  logprintf (LOG_VERBOSE, _("No matches on pattern `%s'.\n"),
+		     escnonprint (u->file));
 	}
       else /* GETONE or GETALL */
 	{
