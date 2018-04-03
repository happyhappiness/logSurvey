    return;
  CHECK_VERBOSE (o);

  FPUTS (s, fp);
  if (save_context_p)
    saved_append (s);
  if (flush_log_p)
