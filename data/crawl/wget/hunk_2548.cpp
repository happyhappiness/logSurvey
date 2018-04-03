   else if (!start)
     {
       if (action == GLOB_GLOBALL)
-	{
-	  /* No luck.  */
-	  /* #### This message SUCKS.  We should see what was the
-	     reason that nothing was retrieved.  */
-	  logprintf (LOG_VERBOSE, _("No matches on pattern `%s'.\n"),
-		     escnonprint (u->file));
-	}
+        {
+          /* No luck.  */
+          /* #### This message SUCKS.  We should see what was the
+             reason that nothing was retrieved.  */
+          logprintf (LOG_VERBOSE, _("No matches on pattern `%s'.\n"),
+                     escnonprint (u->file));
+        }
       else /* GLOB_GETONE or GLOB_GETALL */
-	{
-	  /* Let's try retrieving it anyway.  */
-	  con->st |= ON_YOUR_OWN;
-	  res = ftp_loop_internal (u, NULL, con);
-	  return res;
-	}
+        {
+          /* Let's try retrieving it anyway.  */
+          con->st |= ON_YOUR_OWN;
+          res = ftp_loop_internal (u, NULL, con);
+          return res;
+        }
     }
   freefileinfo (start);
   if (opt.quota && total_downloaded_bytes > opt.quota)
