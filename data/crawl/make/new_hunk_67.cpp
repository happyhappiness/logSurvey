                /* get exit data */
                exit_code = process_exit_code (hPID);

                /* the extra tests of exit_code are here to prevent
                   map_windows32_error_to_string from calling 'fatal',
                   which will then call reap_children again */
                if (werr && exit_code > 0 && exit_code < WSABASEERR)
                  fprintf (stderr, "make (e=%d): %s", exit_code,
                           map_windows32_error_to_string (exit_code));

                /* signal */
                exit_sig = process_signal (hPID);
