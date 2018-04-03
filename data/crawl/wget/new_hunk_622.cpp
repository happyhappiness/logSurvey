    {
      struct log_ln *ln = log_lines + num;
      if (ln->content)
        FPUTS (ln->content, fp);
      ROT_ADVANCE (num);
    }
  while (num != log_line_current);
  if (trailing_line)
    if (log_lines[log_line_current].content)
      FPUTS (log_lines[log_line_current].content, fp);
  fflush (fp);
}

