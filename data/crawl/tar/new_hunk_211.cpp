{
  if (memcmp (buffer, dumpdir_cursor, bytes))
    {
      report_difference (&current_stat_info, _("Contents differ"));
      return 0;
    }

