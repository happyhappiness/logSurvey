  else /* do not CWD */
    logputs (LOG_VERBOSE, _("==> CWD not required.\n"));

  if ((cmd & DO_RETR) && passed_expected_bytes == 0)
    {
      if (opt.verbose)
        {
