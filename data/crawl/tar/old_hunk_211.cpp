{
  if (memcmp (buffer, dumpdir_cursor, bytes))
    {
      report_difference (_("Contents differ"));
      return 0;
    }

