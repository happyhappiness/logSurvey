  logfp = fopen (logfile, "w");
  if (!logfp)
    {
      printf ("%s: %s: %s\n", exec_name, logfile, strerror (errno));
      /* `stdin' is magic to not print anything.  */
      logfp = stdin;
    }
  printf (messij, logfile);
  free (logfile);
  /* Dump all the previous messages to LOGFILE.  */
  log_dump ();
}
