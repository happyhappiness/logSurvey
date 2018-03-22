
  if (memcmp (buffer, diff_buffer, bytes))
    {
      report_difference (_("Contents differ"));
      return 0;
    }

