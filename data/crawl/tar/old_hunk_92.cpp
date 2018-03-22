
      if (is_dir)
	{
	  ensure_slash (&st->orig_file_name);
	  ensure_slash (&st->file_name);

	  if (exclude_caches_option
	      && check_cache_directory (st->orig_file_name))
	    {
	      if (verbose_option)
		WARN ((0, 0,
		       _("%s: contains a cache directory tag; not dumped"),
		       quotearg_colon (st->orig_file_name)));
	      return;
	    }
	  
	  if (check_exclude_tags (st->orig_file_name))
	    return;

	  ok = dump_dir (fd, st, top_level, parent_device);

	  /* dump_dir consumes FD if successful.  */
