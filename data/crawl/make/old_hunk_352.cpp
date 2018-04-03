                    DWORD e = GetLastError ();
                    fprintf (stderr,
                             "Determine main thread ID (Error %ld: %s)\n",
                             e, map_windows32_error_to_string(e));
                  }
                else
                  DB (DB_VERBOSE, ("Main thread handle = %p\n", main_thread));
              }

            /* wait for anything to finish */
            hPID = process_wait_for_any(block, &dwWaitStatus);
            if (hPID)
              {

                /* was an error found on this process? */
                werr = process_last_err(hPID);

                /* get exit data */
                exit_code = process_exit_code(hPID);

                if (werr)
                  fprintf(stderr, "make (e=%d): %s",
                          exit_code, map_windows32_error_to_string(exit_code));

                /* signal */
                exit_sig = process_signal(hPID);

                /* cleanup process */
                process_cleanup(hPID);

                coredump = 0;
              }
