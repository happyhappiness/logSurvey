  if (num_written < 0)
    {
      logputs (LOG_VERBOSE, _("Failed writing HTTP request.\n"));
      CLOSE (sock);
      return WRITEFAILED;
    }
