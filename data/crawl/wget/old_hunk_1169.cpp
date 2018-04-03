        *--p = '\0';

      if (opt.server_response)
        logprintf (LOG_NOTQUIET, "%s\n", escnonprint (line));
      else
        DEBUGP (("%s\n", escnonprint (line)));

      /* The last line of output is the one that begins with "ddd ". */
      if (c_isdigit (line[0]) && c_isdigit (line[1]) && c_isdigit (line[2])
