      char *p;
      char *line = fd_read_line (fd);
      if (!line)
	return FTPRERR;

      /* Strip trailing CRLF before printing the line, so that
	 escnonprint doesn't include bogus \012 and \015. */
      p = strchr (line, '\0');
      if (p > line && p[-1] == '\n')
	*--p = '\0';
      if (p > line && p[-1] == '\r')
	*--p = '\0';

      if (opt.server_response)
	logprintf (LOG_NOTQUIET, "%s\n", escnonprint (line));
      else
        DEBUGP (("%s\n", escnonprint (line)));

      /* The last line of output is the one that begins with "ddd ". */
      if (ISDIGIT (line[0]) && ISDIGIT (line[1]) && ISDIGIT (line[2])
	  && line[3] == ' ')
	{
	  strncpy (ftp_last_respline, line, sizeof (ftp_last_respline));
	  ftp_last_respline[sizeof (ftp_last_respline) - 1] = '\0';
	  *ret_line = line;
	  return FTPOK;
	}
      xfree (line);
    }
}
