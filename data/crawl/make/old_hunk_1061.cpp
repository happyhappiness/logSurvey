#endif


/* Count the number of dead children we have.  If we can use wait3() or
   waitpid() then we'll never use this count: it's completely unnecessary.
   But we need the handler installed to interrupt the select() call for
   the jobs pipe, so we might as well keep it.  */

static unsigned int dead_children = 0;

/* Notice that a child died.
   reap_children should be called when convenient.  */
RETSIGTYPE
child_handler (sig)
     int sig;
{
  ++dead_children;

  if (debug_flag)
    printf (_("Got a SIGCHLD; %u unreaped children.\n"), dead_children);
}
