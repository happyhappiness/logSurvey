  else /* do not CWD */
    logputs (LOG_VERBOSE, _("==> CWD not required.\n"));

  /* If anything is to be retrieved, PORT (or PASV) must be sent.  */
  if (cmd & (DO_LIST | DO_RETR))
    {
