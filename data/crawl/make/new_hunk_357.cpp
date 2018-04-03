  int exit_code = EXIT_FAILURE;

  /* make sure CreateProcess() has Path it needs */
  sync_Path_environment ();

  /* launch command */
  hPID = process_easy (argv, envp, -1, -1);

  /* make sure launch ok */
  if (hPID == INVALID_HANDLE_VALUE)
    {
      int i;
      fprintf (stderr, _("process_easy() failed to launch process (e=%ld)\n"),
               process_last_err (hPID));
      for (i = 0; argv[i]; i++)
          fprintf (stderr, "%s ", argv[i]);
      fprintf (stderr, _("\nCounted %d args in failed launch\n"), i);
      exit (EXIT_FAILURE);
    }

  /* wait and reap last child */
  hWaitPID = process_wait_for_any (1, 0);
  while (hWaitPID)
    {
      /* was an error found on this process? */
      err = process_last_err (hWaitPID);

      /* get exit data */
      exit_code = process_exit_code (hWaitPID);

      if (err)
          fprintf (stderr, "make (e=%d, rc=%d): %s",
                   err, exit_code, map_windows32_error_to_string (err));

      /* cleanup process */
      process_cleanup (hWaitPID);

      /* expect to find only last pid, warn about other pids reaped */
      if (hWaitPID == hPID)
          break;
      else
        {
          char *pidstr = xstrdup (pid2str ((pid_t)hWaitPID));

          fprintf (stderr,
                   _("make reaped child pid %s, still waiting for pid %s\n"),
                   pidstr, pid2str ((pid_t)hPID));
          free (pidstr);
        }
    }

  /* return child's exit code as our exit code */
  exit (exit_code);

#else  /* !WINDOWS32 */

