  }

  pl->pid = 0;
  pthread_exit ((void *) 0);
  return (NULL);
} /* void *exec_read_one }}} */

static int exec_init (void) /* {{{ */
{
  struct sigaction sa;
