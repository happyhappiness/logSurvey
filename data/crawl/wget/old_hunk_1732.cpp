
  if (cmd & DO_RETR)
    {
      /* If we're in spider mode, don't really retrieve anything.  The
         fact that we got to this point should be proof enough that
         the file exists, vaguely akin to HTTP's concept of a "HEAD"
         request.  */
      if (opt.spider)
        {
          fd_close (csock);
          con->csock = -1;
          fd_close (dtsock);
