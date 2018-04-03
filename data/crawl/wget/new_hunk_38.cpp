  struct timeval to;
  int ret = 0;

  if (sock >= FD_SETSIZE)
    {
      logprintf (LOG_NOTQUIET, _("Too many fds open.  Cannot use select on a fd >= %d\n"), FD_SETSIZE);
      exit (WGET_EXIT_GENERIC_ERROR);
    }
  /* Check if we still have a valid (non-EOF) connection.  From Andrew
   * Maholski's code in the Unix Socket FAQ.  */

