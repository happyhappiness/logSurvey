        /* On Windows we simply wait for the jobserver semaphore to become
         * signalled or one of our child processes to terminate.
         */
        got_token = wait_for_semaphore_or_child_process();
        if (got_token < 0)
          {
            DWORD err = GetLastError();
            fatal (NILF, _("semaphore or child process wait: (Error %ld: %s)"),
                   err, map_windows32_error_to_string(err));
          }
#else
        /* Set interruptible system calls, and read() for a job token.  */
	set_child_handler_action_flags (1, waiting_jobs != NULL);
	got_token = read (job_rfd, &token, 1);
	saved_errno = errno;
	set_child_handler_action_flags (0, waiting_jobs != NULL);
#endif

        /* If we got one, we're done here.  */
	if (got_token == 1)
          {
            DB (DB_JOBS, (_("Obtained token for child %p (%s).\n"),
                          c, c->file->name));
