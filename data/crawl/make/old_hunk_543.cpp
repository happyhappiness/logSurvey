  /* If we're using the jobserver and this child is not the only outstanding
     job, put a token back into the pipe for it.  */

  if (job_fds[1] >= 0 && jobserver_tokens > 1)
    {
      char token = '+';
