       logprintf.  */
    int save_errno = errno;
    if (sock >= 0)
      xclose (sock);
    if (print)
      logprintf (LOG_VERBOSE, "failed: %s.\n", strerror (errno));
    errno = save_errno;
