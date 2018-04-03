  starting_directory = current_directory;

#ifdef MAKE_JOBSERVER
  /* If the jobserver_fds option is seen, make sure that -j is reasonable.
     This can't be usefully set in the makefile, and we want to verify the
     FDs are valid before any other aspect of make has a chance to start
     using them for something else.  */

  if (jobserver_fds)
    {
      /* The combination of jobserver_fds and !job_slots means we're using the
         jobserver.  If !job_slots and no jobserver_fds, we can start infinite
         jobs.  If we see both jobserver_fds and job_slots >0 that means the
         user set -j explicitly.  This is broken; in this case obey the user
         (ignore the jobserver for this make) but print a message.  If we've
         restarted, we already printed this the first time.  */

      if (!job_slots)
        jobserver_parse_arg (jobserver_fds);

      else if (! restarts)
        O (error, NILF,
           _("warning: -jN forced in submake: disabling jobserver mode."));

      if (job_slots > 0)
        {
          /* If job_slots is set now then we're not using jobserver */
          jobserver_clear ();
          free (jobserver_fds);
          jobserver_fds = NULL;
        }
    }
#endif
