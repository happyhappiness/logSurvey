static void
free_child (struct child *child)
{
  if (!jobserver_tokens)
    fatal (NILF, "INTERNAL: Freeing child 0x%08lx (%s) but no tokens left!\n",
           (unsigned long int) child, child->file->name);

  /* If we're using the jobserver and this child is not the only outstanding
     job, put a token back into the pipe for it.  */

  if (job_fds[1] >= 0 && jobserver_tokens > 1)
    {
      char token = '+';
      int r;
