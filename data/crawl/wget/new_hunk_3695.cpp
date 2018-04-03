	logputs (LOG_VERBOSE, _("==> CWD not needed.\n"));
      else
	{
	  char *target = u->dir;

	  DEBUGP (("changing working directory\n"));

	  /* Change working directory.  To change to a non-absolute
	     Unix directory, we need to prepend initial directory
	     (con->id) to it.  Absolute directories "just work".  */

	  if (*target != '/')
	    {
	      int idlen = strlen (con->id);
	      char *ntarget = (char *)alloca (idlen + 1 + strlen (u->dir) + 1);
	      /* pwd_len == 1 means pwd = "/" */
	      sprintf (ntarget, "%s%s%s", con->id, idlen == 1 ? "" : "/",
		       target);
	      target = ntarget;
	    }

	  /* If the FTP host runs VMS, we will have to convert it to
	     VMS style as VMS does not like leading slashes.  "VMS
	     style" is [dir.subdir.subsubdir].  */
	  if (con->rs == ST_VMS)
	    {
	      char *tmpp;
	      char *ntarget = (char *)alloca (strlen (target) + 1);
	      strcpy (ntarget, target);
	      assert (*ntarget == '/');
	      *ntarget = '[';
	      for (tmpp = ntarget + 1; *tmpp; tmpp++)
		if (*tmpp == '/')
		  *tmpp = '.';
	      *tmpp++ = ']';
	      *tmpp = '\0';
	      target = ntarget;
	    }

	  if (!opt.server_response)
	    logprintf (LOG_VERBOSE, "==> CWD %s ... ", target);
	  err = ftp_cwd (&con->rbuf, target);
	  /* FTPRERR, WRITEFAILED, FTPNSFOD */
	  switch (err)
	    {
