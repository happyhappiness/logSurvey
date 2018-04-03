 	logputs (LOG_VERBOSE, _("==> CWD not needed.\n"));
       else
 	{
-	  /* Change working directory. If the FTP host runs VMS and
-             the path specified is absolute, we will have to convert
-             it to VMS style as VMS does not like leading slashes */
+	  char *target = u->dir;
+
 	  DEBUGP (("changing working directory\n"));
-	  if (*(u->dir) == '/')
+
+	  /* Change working directory.  To change to a non-absolute
+	     Unix directory, we need to prepend initial directory
+	     (con->id) to it.  Absolute directories "just work".  */
+
+	  if (*target != '/')
 	    {
-	      int pwd_len = strlen (con->id);
-	      char *result = (char *)alloca (strlen (u->dir) + pwd_len + 10);
-	      *result = '\0';
-	      switch (con->rs)
-		{
-		case ST_VMS:
-		  {
-		    char *tmp_dir, *tmpp;
-		    STRDUP_ALLOCA (tmp_dir, u->dir);
-		    for (tmpp = tmp_dir; *tmpp; tmpp++)
-		      if (*tmpp=='/')
-			*tmpp = '.';
-		    strcpy (result, con->id);
-		    /* pwd ends with ']', we have to get rid of it */
-		    result[pwd_len - 1]= '\0';
-		    strcat (result, tmp_dir);
-		    strcat (result, "]");
-		  }
-		  break;
-		case ST_UNIX:
-		case ST_WINNT:
-		case ST_MACOS:
-		  /* pwd_len == 1 means pwd = "/", but u->dir begins with '/'
-		     already */
-		  if (pwd_len > 1)
-		    strcpy (result, con->id);
-		  strcat (result, u->dir);
-		  DEBUGP(("\npwd=\"%s\"", con->id));
-		  DEBUGP(("\nu->dir=\"%s\"", u->dir));
-		  break;
-		default:
-		  abort ();
-		  break;
-		}
-	      if (!opt.server_response)
-		logprintf (LOG_VERBOSE, "==> CWD %s ... ", result);
-	      err = ftp_cwd (&con->rbuf, result);
+	      int idlen = strlen (con->id);
+	      char *ntarget = (char *)alloca (idlen + 1 + strlen (u->dir) + 1);
+	      /* pwd_len == 1 means pwd = "/" */
+	      sprintf (ntarget, "%s%s%s", con->id, idlen == 1 ? "" : "/",
+		       target);
+	      target = ntarget;
 	    }
-	  else
+
+	  /* If the FTP host runs VMS, we will have to convert it to
+	     VMS style as VMS does not like leading slashes.  "VMS
+	     style" is [dir.subdir.subsubdir].  */
+	  if (con->rs == ST_VMS)
 	    {
-	      if (!opt.server_response)
-		logprintf (LOG_VERBOSE, "==> CWD %s ... ", u->dir);
-	      err = ftp_cwd (&con->rbuf, u->dir);
+	      char *tmpp;
+	      char *ntarget = (char *)alloca (strlen (target) + 1);
+	      strcpy (ntarget, target);
+	      assert (*ntarget == '/');
+	      *ntarget = '[';
+	      for (tmpp = ntarget + 1; *tmpp; tmpp++)
+		if (*tmpp == '/')
+		  *tmpp = '.';
+	      *tmpp++ = ']';
+	      *tmpp = '\0';
+	      target = ntarget;
 	    }
+
+	  if (!opt.server_response)
+	    logprintf (LOG_VERBOSE, "==> CWD %s ... ", target);
+	  err = ftp_cwd (&con->rbuf, target);
 	  /* FTPRERR, WRITEFAILED, FTPNSFOD */
 	  switch (err)
 	    {
