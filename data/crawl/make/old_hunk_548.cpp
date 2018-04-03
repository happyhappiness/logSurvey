     have written all our tokens so do that now.  If tokens are left
     after any other error code, that's bad.  */

  if (job_fds[0] != -1 && jobserver_tokens)
    {
      if (status != 2)
        error (NILF,
