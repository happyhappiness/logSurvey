	    if (subcommand_option == UPDATE_SUBCOMMAND
		&& (name = name_scan (current_file_name), name))
	      {
		struct stat stat_data;
		enum archive_format unused;

		decode_header (current_header, &current_stat, &unused, 0);
		if (stat (current_file_name, &stat_data) < 0)
		  ERROR ((0, errno, _("Cannot stat %s"), current_file_name));
		else if (current_stat.st_mtime >= stat_data.st_mtime)
		  name->found = 1;
	      }
	    set_next_block_after (current_header);
	    if (current_header->oldgnu_header.isextended)
