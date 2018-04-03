  do
    {
      for (i = 0; 1; i++)
        {
          int res;
          if (i > bufsize - 1)
            *line = (char *)xrealloc (*line, (bufsize <<= 1));
          res = RBUF_READCHAR (rbuf, *line + i);
          /* RES is number of bytes read.  */
          if (res == 1)
            {
              if ((*line)[i] == '\n')
                {
                  (*line)[i] = '\0';
                  /* Get rid of \r.  */
                  if (i > 0 && (*line)[i - 1] == '\r')
                    (*line)[i - 1] = '\0';
                  break;
                }
            }
          else
            return FTPRERR;
        }
      if (opt.server_response)
        logprintf (LOG_ALWAYS, "%s\n", *line);
      else
        DEBUGP (("%s\n", *line));
    }
  while (!(i >= 3 && ISDIGIT (**line) && ISDIGIT ((*line)[1]) &&
           ISDIGIT ((*line)[2]) && (*line)[3] == ' '));
  strncpy (ftp_last_respline, *line, sizeof (ftp_last_respline));
  ftp_last_respline[sizeof (ftp_last_respline) - 1] = '\0';
  return FTPOK;
