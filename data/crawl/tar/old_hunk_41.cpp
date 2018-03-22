  switch (current_header->header.typeflag)
    {
    default:
      ERROR ((0, 0, _("%s: Unknown file type `%c', diffed as normal file"),
	      quotearg_colon (current_stat_info.file_name),
	      current_header->header.typeflag));
      /* Fall through.  */
