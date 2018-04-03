free_child (child)
     register struct child *child;
{
  /* If this child is the only one it was our "free" job, so don't put a
     token back for it.  */

  if (job_fds[1] >= 0 && (child != children || child->next != 0))
    {
      char *token = '+';

      /* Write a job token back to the pipe.  */

      while (write (job_fds[1], &token, 1) != 1)
        if (!EINTR_SET)
          pfatal_with_name (_("write jobserver"));

      if (debug_flag)
        printf (_("Released token for child 0x%08lx (%s).\n"),
                (unsigned long int) child, child->file->name);
    }

  if (handling_fatal_signal) /* Don't bother free'ing if about to die.  */
    return;

  if (child->command_lines != 0)
    {
      register unsigned int i;
