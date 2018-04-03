        int i;
        unblock_sigs();
        fprintf(stderr,
          _("process_easy() failed to launch process (e=%ld)\n"),
          process_last_err(hPID));
               for (i = 0; argv[i]; i++)
                 fprintf(stderr, "%s ", argv[i]);
