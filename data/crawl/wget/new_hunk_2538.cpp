  if (err != FTPOK)
    {
      /* The control connection is decidedly closed.  Print the time
         only if it hasn't already been printed.  */
      if (res != -1)
        logprintf (LOG_NOTQUIET, "%s (%s) - ", tms, tmrate);
      logputs (LOG_NOTQUIET, _("Control connection closed.\n"));
      /* If there is an error on the control connection, close it, but
         return FTPRETRINT, since there is a possibility that the
         whole file was retrieved nevertheless (but that is for
         ftp_loop_internal to decide).  */
      fd_close (csock);
      con->csock = -1;
      return FTPRETRINT;
