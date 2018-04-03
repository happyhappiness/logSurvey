      fputs (log_lines[log_line_current].content, fp);
  fflush (fp);
}

/* Redirect output to `wget-log'.  MESSIJ is printed on stdout, and
   should contain *exactly one* `%s', which will be replaced by the
   log file name.

   If logging was not enabled, MESSIJ will not be printed.  */
void
redirect_output (const char *messij)
{
  char *logfile;

  if (!save_log_p)
    return;

  logfile = unique_name (DEFAULT_LOGFILE);
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
  xfree (logfile);
  /* Dump the previous screenful of output to LOGFILE.  */
  log_dump ();
  save_log_p = 0;
}
