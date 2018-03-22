	      readlink_warn (current_stat_info.file_name);
	    else
	      readlink_error (current_stat_info.file_name);
	    report_difference (0);
	  }
	else if (status != len
		 || strncmp (current_stat_info.link_name, linkbuf, len) != 0)
