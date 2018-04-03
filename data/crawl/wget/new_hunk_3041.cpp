      if (!line)
	return FTPRERR;
      if (opt.server_response)
        logputs (LOG_NOTQUIET, escnonprint (line));
      else
        DEBUGP (("%s", escnonprint (line)));
      if (ISDIGIT (line[0]) && ISDIGIT (line[1]) && ISDIGIT (line[2])
	  && line[3] == ' ')
	{
