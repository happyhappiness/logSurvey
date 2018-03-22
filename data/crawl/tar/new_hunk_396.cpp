static void
read_error (void)
{
  ERROR ((0, errno, _("Read error on %s"), *archive_name_cursor));

  if (record_start_block == 0)
    FATAL_ERROR ((0, 0, _("At beginning of tape, quitting now")));
