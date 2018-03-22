
      if (is_dir)
	{
	  const char *tag_file_name;
	  ensure_slash (&st->orig_file_name);
	  ensure_slash (&st->file_name);

	  if (check_exclusion_tags (st->orig_file_name, &tag_file_name)
	      == exclusion_tag_all)
	    {
	      exclusion_tag_warning (st->orig_file_name, tag_file_name,
				     _("directory not dumped"));
	      return;
	    }
	  
	  ok = dump_dir (fd, st, top_level, parent_device);

	  /* dump_dir consumes FD if successful.  */
