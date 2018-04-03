     print it out.  */
  if (opt.server_response && (con->cmd & DO_LIST))
    {
      mkalldirs (u->local);
      fp = fopen (u->local, "r");
      if (!fp)
	logprintf (LOG_ALWAYS, "%s: %s\n", u->local, strerror (errno));
      else
	{
	  char *line;
