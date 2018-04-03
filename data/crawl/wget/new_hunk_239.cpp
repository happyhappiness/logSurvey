  for (; dp->accumulated >= dot_bytes; dp->accumulated -= dot_bytes)
    {
      if (dp->dots == 0)
        logprintf (LOG_PROGRESS, "\n%6sK",
                   number_to_static_string (dp->rows * ROW_BYTES / 1024));

      if (dp->dots % opt.dot_spacing == 0)
        logputs (LOG_PROGRESS, " ");
      logputs (LOG_PROGRESS, ".");

      ++dp->dots;
      if (dp->dots >= opt.dots_in_line)
