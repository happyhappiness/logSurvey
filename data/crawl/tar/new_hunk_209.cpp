      if (status < 0)
	{
	  read_error (current_stat_info.file_name);
	  report_difference (&current_stat_info, NULL);
	}
      else
	{
	  report_difference (&current_stat_info, 
			     ngettext ("Could only read %lu of %lu byte",
				       "Could only read %lu of %lu bytes",
				       bytes),
			     (unsigned long) status, (unsigned long) bytes);
