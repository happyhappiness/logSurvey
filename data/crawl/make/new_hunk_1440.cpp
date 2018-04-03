     DeleteFile (amiga_bname);        /* Ignore errors.  */
  }
#endif	/* Not Amiga */
#ifdef WIN32
  {
      HANDLE hPID;
      char* arg0;

      /* make UNC paths safe for CreateProcess -- backslash format */
      arg0 = argv[0];
      if (arg0 && arg0[0] == '/' && arg0[1] == '/')
        for ( ; arg0 && *arg0; arg0++)
          if (*arg0 == '/')
            *arg0 = '\\';

      /* make sure CreateProcess() has Path it needs */
      sync_Path_environment();

      hPID = process_easy(argv, child->environment);

      if (hPID != INVALID_HANDLE_VALUE)
        child->pid = (int) hPID;
      else {
        int i;
        unblock_sigs();
        fprintf(stderr,
          "process_easy() failed failed to launch process (e=%d)\n",
          process_last_err(hPID));
               for (i = 0; argv[i]; i++)
                 fprintf(stderr, "%s ", argv[i]);
               fprintf(stderr, "\nCounted %d args in failed launch\n", i);
      }
  } 
#endif /* WIN32 */
#endif	/* Not MSDOS.  */

  /* We are the parent side.  Set the state to
