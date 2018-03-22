      if (lseek (diff_handle, offset, SEEK_SET) < 0)
	{
	  seek_error_details (current_stat_info.file_name, offset);
	  report_difference (NULL);
	}

      /* Take care to not run out of room in our buffer.  */
