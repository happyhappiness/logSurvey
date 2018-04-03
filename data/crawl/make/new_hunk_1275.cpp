	  coredump = 0;
#endif /* _AMIGA */
#ifdef WINDOWS32
          {
            HANDLE hPID;
            int err;

            /* wait for anything to finish */
            if (hPID = process_wait_for_any()) {

              /* was an error found on this process? */
              err = process_last_err(hPID);

              /* get exit data */
              exit_code = process_exit_code(hPID);

              if (err)
                fprintf(stderr, "make (e=%d): %s",
                  exit_code, map_windows32_error_to_string(exit_code));

              /* signal */
              exit_sig = process_signal(hPID);

              /* cleanup process */
              process_cleanup(hPID);

              coredump = 0;
            }
            pid = (int) hPID;
          }
#endif /* WINDOWS32 */
	}

      /* Check if this is the child of the `shell' function.  */
      if (!remote && pid == shell_function_pid)
