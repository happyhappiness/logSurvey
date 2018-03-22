	if (lseek (diff_handle, offset, SEEK_SET) < 0)
	  {
	    seek_error_details (current_stat_info.file_name, offset);
	    report_difference (0);
	    break;
	  }

