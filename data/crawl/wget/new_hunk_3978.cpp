  logfp = fopen (logfile, "w");
  if (!logfp)
    {
      /* Eek!  Opening the alternate log file has failed.  Nothing we
         can do but disable printing completely. */
      fprintf (stderr, "%s: %s: %s\n", exec_name, logfile, strerror (errno));
      /* `stdin' is magic to not print anything, ever.  */
      logfp = stdin;
    }
  fprintf (stderr, messij, logfile);
  free (logfile);
  /* Dump the previous screenful of output to LOGFILE.  */
  log_dump ();
  save_log_p = 0;
}
