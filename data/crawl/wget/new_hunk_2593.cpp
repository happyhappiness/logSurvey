  for (; dp->accumulated >= dot_bytes; dp->accumulated -= dot_bytes)
    {
      if (dp->dots == 0)
        logprintf (LOG_VERBOSE, "\n%6sK",
                   number_to_static_string (dp->rows * ROW_BYTES / 1024));

      if (dp->dots % opt.dot_spacing == 0)
        logputs (LOG_VERBOSE, " ");
      logputs (LOG_VERBOSE, ".");

      ++dp->dots;
      if (dp->dots >= opt.dots_in_line)
        {
          ++dp->rows;
          dp->dots = 0;

          print_row_stats (dp, dltime, false);
        }
    }

  log_set_flush (true);
