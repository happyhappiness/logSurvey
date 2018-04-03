  if (num_written < 0)
    {
      logputs (LOG_VERBOSE, _("Failed writing HTTP request.\n"));
      free (request);
      CLOSE (sock);
      return WRITEFAILED;
    }
