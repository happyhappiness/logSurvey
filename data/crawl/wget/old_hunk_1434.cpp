  statcode = resp_status (resp, &message);
  if (!opt.server_response)
    logprintf (LOG_VERBOSE, "%2d %s\n", statcode,
               message ? escnonprint (message) : "");
  else
    {
      logprintf (LOG_VERBOSE, "\n");
