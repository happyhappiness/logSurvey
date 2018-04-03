#endif


/* Handle a dead child.  This handler may or may not ever be installed.

   If we're using the jobserver blocking read, we need it.  First, installing
   it ensures the read will interrupt on SIGCHLD.  Second, we close the dup'd
   read side of the pipe to ensure we don't enter another blocking read
   without reaping all the dead children.  In this case we don't need the
   dead_children count.

   If we don't have either waitpid or wait3, then make is unreliable, but we
   use the dead_children count to reap children as best we can.  In this case
   job_rfd will never be >= 0.  */

static unsigned int dead_children = 0;

RETSIGTYPE
child_handler (sig)
     int sig;
{
  ++dead_children;

  if (job_rfd >= 0)
    close (job_rfd);
  job_rfd = -1;

  if (debug_flag)
    printf (_("Got a SIGCHLD; %u unreaped children.\n"), dead_children);
}
