#ifdef WINDOWS32
          {
            HANDLE hPID;
            int err;
            exit_code = 0;
            exit_sig = 0;
            coredump = 0;

            /* wait for anything to finish */
            hPID = process_wait_for_any();
            if (hPID)
              {

                /* was an error found on this process? */
                err = process_last_err(hPID);

                /* get exit data */
                exit_code = process_exit_code(hPID);

                if (err)
                  fprintf(stderr, "make (e=%d): %s",
                          exit_code, map_windows32_error_to_string(exit_code));

