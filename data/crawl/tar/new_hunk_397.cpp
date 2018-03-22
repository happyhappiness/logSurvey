	    if (subcommand_option == UPDATE_SUBCOMMAND
		&& (name = name_scan (current_file_name), name))
	      {
		struct stat s;
		enum archive_format unused;

		decode_header (current_header, &current_stat, &unused, 0);
		chdir_do (name->change_dir);
		if (deref_stat (dereference_option, current_file_name, &s) == 0
		    && s.st_mtime <= current_stat.st_mtime)
		  add_avoided_name (current_file_name);
	      }
	    set_next_block_after (current_header);
	    if (current_header->oldgnu_header.isextended)
