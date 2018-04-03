 */
int w32_kill(int pid, int sig)
{
       return ((process_kill(pid, sig) == TRUE) ? 0 : -1);
}
#endif /* WINDOWS32 */


static void
free_job_token (child)
     struct child *child;
{
  switch (child->job_token)
  {
    case '-':
      /* If this child doesn't have a token, punt.  */
      return;

    case '+':
      /* If this child has the reserved token, take it back.  */
      my_job_token = '+';
      break;

    default:
      /* Write any other job tokens back to the pipe.  */
      while (write (job_fds[1], &child->job_token, 1) != 1)
        if (!EINTR_SET)
          pfatal_with_name (_("write jobserver"));
      break;
  }

  if (debug_flag)
    printf (_("Released token `%c' for child 0x%08lx (%s).\n"),
            child->job_token, (unsigned long int) child, child->file->name);

  child->job_token = '-';
}


/* Write an error message describing the exit status given in
   EXIT_CODE, EXIT_SIG, and COREDUMP, for the target TARGET_NAME.
   Append "(ignored)" if IGNORED is nonzero.  */
