#ifdef WINDOWS32
          {
            HANDLE hPID;
            int werr;
            HANDLE hcTID, hcPID;
            exit_code = 0;
            exit_sig = 0;
            coredump = 0;

            /* Record the thread ID of the main process, so that we
               could suspend it in the signal handler.  */
            if (!main_thread)
              {
                hcTID = GetCurrentThread ();
                hcPID = GetCurrentProcess ();
                if (!DuplicateHandle (hcPID, hcTID, hcPID, &main_thread, 0,
                                      FALSE, DUPLICATE_SAME_ACCESS))
                  {
                    DWORD e = GetLastError ();
                    fprintf (stderr,
                             "Determine main thread ID (Error %ld: %s)\n",
                             e, map_windows32_error_to_string(e));
                  }
                else
                  DB (DB_VERBOSE, ("Main thread handle = 0x%08lx\n",
                                   (unsigned long)main_thread));
              }

            /* wait for anything to finish */
            hPID = process_wait_for_any();
            if (hPID)
              {

                /* was an error found on this process? */
                werr = process_last_err(hPID);

                /* get exit data */
                exit_code = process_exit_code(hPID);

                if (werr)
                  fprintf(stderr, "make (e=%d): %s",
                          exit_code, map_windows32_error_to_string(exit_code));

