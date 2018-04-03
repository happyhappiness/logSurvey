                /* get exit data */
                exit_code = process_exit_code (hPID);

                if (werr)
                  fprintf (stderr, "make (e=%d): %s", exit_code,
                           map_windows32_error_to_string (exit_code));

                /* signal */
                exit_sig = process_signal (hPID);
