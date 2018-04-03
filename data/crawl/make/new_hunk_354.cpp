            *arg0 = '\\';

      /* make sure CreateProcess() has Path it needs */
      sync_Path_environment ();

#ifdef OUTPUT_SYNC
          /* Divert child output if output_sync in use.  Don't capture
             recursive make output unless we are synchronizing "make" mode.  */
          if (output_sync && sync_cmd)
            hPID = process_easy (argv, child->environment,
                                 child->outfd, child->errfd);
          else
#endif
            hPID = process_easy (argv, child->environment, -1, -1);

      if (hPID != INVALID_HANDLE_VALUE)
        child->pid = (pid_t) hPID;
      else
        {
          int i;
          unblock_sigs ();
          fprintf (stderr,
                   _("process_easy() failed to launch process (e=%ld)\n"),
                   process_last_err (hPID));
          for (i = 0; argv[i]; i++)
            fprintf (stderr, "%s ", argv[i]);
          fprintf (stderr, _("\nCounted %d args in failed launch\n"), i);
          goto error;
        }
  }
#endif /* WINDOWS32 */
#endif  /* __MSDOS__ or Amiga or WINDOWS32 */

  /* Bump the number of jobs started in this second.  */
  ++job_counter;
