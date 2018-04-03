static void
free_child (struct child *child)
{
  /* If this child is the only one it was our "free" job, so don't put a
     token back for it.  This child has already been removed from the list,
     so if there any left this wasn't the last one.  */

  if (job_fds[1] >= 0 && children)
    {
      char token = '+';
      int r;
