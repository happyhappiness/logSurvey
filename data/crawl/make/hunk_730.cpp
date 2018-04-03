     {
       int i;
       fprintf(stderr,
-              _("process_easy() failed failed to launch process (e=%d)\n"),
+              _("process_easy() failed failed to launch process (e=%ld)\n"),
               process_last_err(hPID));
       for (i = 0; argv[i]; i++)
           fprintf(stderr, "%s ", argv[i]);
