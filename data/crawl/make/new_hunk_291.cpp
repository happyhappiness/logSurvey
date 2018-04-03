#endif

#ifdef MAKE_JOBSERVER
  /* If we have >1 slot but no jobserver-fds, then we're a top-level make.
     Set up the pipe and install the fds option for our children.  */

