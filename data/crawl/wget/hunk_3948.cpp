 	logputs (LOG_VERBOSE, _("==> CWD not needed.\n"));
       else
 	{
-	  /* Change working directory.  */
-	  if (!opt.server_response)
-	    logprintf (LOG_VERBOSE, "==> CWD %s ... ", u->dir);
-	  err = ftp_cwd (&con->rbuf, u->dir);
+	  /* Change working directory. If the FTP host runs VMS and
+             the path specified is absolute, we will have to convert
+             it to VMS style as VMS does not like leading slashes */
+	  if (*(u->dir) == '/')
+	    {
+	      char *result = (char *)alloca (strlen (u->dir) + pwd_len + 10);
+	      *result = '\0';
+	      switch (host_type)
+		{
+		case ST_VMS:
+		  {
+		    char *tmp_dir, *tmpp;
+		    STRDUP_ALLOCA (tmp_dir, u->dir);
+		    for (tmpp = tmp_dir; *tmpp; tmpp++)
+		      if (*tmpp=='/')
+			*tmpp = '.';
+		    strcpy (result, pwd);
+		    /* pwd ends with ']', we have to get rid of it */
+		    result[pwd_len - 1]= '\0';
+		    strcat (result, tmp_dir);
+		    strcat (result, "]");
+		  }
+		  break;
+		case ST_UNIX:
+		  /* pwd_len == 1 means pwd = "/", but u->dir begins with '/'
+		     already */
+		  if (pwd_len > 1)
+		    strcpy (result, pwd);
+		  strcat (result, u->dir);
+		  /* These look like debugging messages to me.  */
+#if 0
+		  logprintf (LOG_VERBOSE, "\npwd=\"%s\"", pwd);
+		  logprintf (LOG_VERBOSE, "\nu->dir=\"%s\"", u->dir);
+#endif
+		  break;
+		default:
+		  abort ();
+		  break;
+		}
+	      if (!opt.server_response)
+		logprintf (LOG_VERBOSE, "==> CWD %s ... ", result);
+	      err = ftp_cwd (&con->rbuf, result);
+	    }
+	  else
+	    {
+	      if (!opt.server_response)
+		logprintf (LOG_VERBOSE, "==> CWD %s ... ", u->dir);
+	      err = ftp_cwd (&con->rbuf, u->dir);
+	    }
 	  /* FTPRERR, WRITEFAILED, FTPNSFOD */
 	  switch (err)
 	    {
