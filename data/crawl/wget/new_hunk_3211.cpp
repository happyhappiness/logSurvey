
      if (con->st & ON_YOUR_OWN)
	{
	  fd_close (con->csock);
	  con->csock = -1;
	}
      if (!opt.spider)
        logprintf (LOG_VERBOSE, _("%s (%s) - `%s' saved [%ld]\n\n"),
