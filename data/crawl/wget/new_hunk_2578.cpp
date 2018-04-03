    {
      struct log_ln *ln = log_lines + num;
      if (ln->content)
        fputs (ln->content, fp);
      ROT_ADVANCE (num);
    }
  while (num != log_line_current);
