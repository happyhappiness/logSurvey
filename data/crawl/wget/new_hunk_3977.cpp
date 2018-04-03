void
log_close (void)
{
  int i;

  if (logfp != stdin)
    fclose (logfp);
  save_log_p = 0;
  for (i = 0; i < SAVED_LOG_LINES; i++)
    free_log_line (i);
  log_line_current = -1;
  trailing_line = 0;
}

/* Dump saved lines to logfp. */
static void
log_dump (void)
{
  int num = log_line_current;
  FILE *fp = logfp;

  if (num == -1)
    return;
  if (trailing_line)
    ROT_ADVANCE (num);
  do
    {
      struct log_ln *ln = log_lines + num;
      if (ln->content)
	fputs (ln->content, fp);
      ROT_ADVANCE (num);
    }
  while (num != log_line_current);
  if (trailing_line)
    if (log_lines[log_line_current].content)
      fputs (log_lines[log_line_current].content, fp);
  fflush (fp);
}

/* Redirect output to `wget-log'.  MESSIJ is printed on stdout, and
   should contain *exactly one* `%s', which will be replaced by the
   log file name.

   If logging was not enabled, MESSIJ will not be printed.  */
void
