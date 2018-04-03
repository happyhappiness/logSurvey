{
  va_list args;

  if (output_sync)
    log_working_directory (1, 1);
  else
    log_working_directory (1, 0);

  if (flocp && flocp->filenm)
    fprintf (stderr, "%s:%lu: ", flocp->filenm, flocp->lineno);
