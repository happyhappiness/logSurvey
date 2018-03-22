{
  char typeflag;
  tar_extractor_t fun;

  fatal_exit_hook = extract_finish;

  set_next_block_after (current_header);

  if (!current_stat_info.file_name[0]
      || (interactive_option
	  && !confirm ("extract", current_stat_info.file_name)))
    {
