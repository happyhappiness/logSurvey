  /* Check for status line.  */
  message = NULL;
  statcode = resp_status (resp, &message);
  hs->message = xstrdup (message);
  if (!opt.server_response)
    logprintf (LOG_VERBOSE, "%2d %s\n", statcode,
