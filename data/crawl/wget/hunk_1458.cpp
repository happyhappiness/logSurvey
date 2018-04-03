 
   if (cmd & DO_RETR)
     {
-      /* If we're in spider mode, don't really retrieve anything.  The
-         fact that we got to this point should be proof enough that
-         the file exists, vaguely akin to HTTP's concept of a "HEAD"
-         request.  */
+      /* If we're in spider mode, don't really retrieve anything except
+	 the directory listing and verify whether the given "file" exists.  */
       if (opt.spider)
         {
+	  bool exists = false;
+	  uerr_t res;
+	  struct fileinfo *f;
+	  res = ftp_get_listing (u, con, &f);
+	  /* Set the DO_RETR command flag again, because it gets unset when 
+	     calling ftp_get_listing() and would otherwise cause an assertion 
+	     failure earlier on when this function gets repeatedly called 
+	     (e.g., when recursing).  */
+	  con->cmd |= DO_RETR;
+	  if (res == RETROK)
+	    {
+	      while (f) 
+		{
+		  if (!strcmp (f->name, u->file))
+		    {
+		      exists = true;
+		      break;
+		    }
+		  f = f->next;
+		}
+	      if (!exists)
+		{
+		  logputs (LOG_VERBOSE, "\n");
+		  logprintf (LOG_NOTQUIET, _("No such file `%s'.\n"),
+			     escnonprint (u->file));
+		}
+	    }
           fd_close (csock);
           con->csock = -1;
           fd_close (dtsock);
 util/paramcheck.pl | 17 ++++++++++++++++-
 1 file changed, 16 insertions(+), 1 deletion(-)
