      {
	off_t offset;

	if (current_stat_info.had_trailing_slash)
	  goto really_dir;

	if (!get_stat_data (current_stat_info.file_name, &stat_data))
	  break;

	if (!S_ISREG (stat_data.st_mode))
	  {
	    report_difference (_("File type differs"));
	    skip_member ();
	    break;
	  }

	offset = OFF_FROM_HEADER (current_header->oldgnu_header.offset);
	if (stat_data.st_size != current_stat_info.stat.st_size + offset)
	  {
	    report_difference (_("Size differs"));
	    skip_member ();
	    break;
	  }

	diff_handle = open (current_stat_info.file_name, O_RDONLY | O_BINARY);

	if (diff_handle < 0)
	  {
	    open_error (current_stat_info.file_name);
	    report_difference (0);
	    skip_member ();
	    break;
	  }

	if (lseek (diff_handle, offset, SEEK_SET) < 0)
	  {
	    seek_error_details (current_stat_info.file_name, offset);
	    report_difference (0);
	    break;
	  }

	if (multi_volume_option)
	  {
	    assign_string (&save_name, current_stat_info.file_name);
	    save_totsize = stat_data.st_size;
	    /* save_sizeleft is set in read_and_process.  */
	  }

	read_and_process (current_stat_info.stat.st_size, process_rawdata);

	if (multi_volume_option)
	  assign_string (&save_name, 0);

	status = close (diff_handle);
	if (status != 0)
	  close_error (current_stat_info.file_name);

	break;
      }
    }
}

void
verify_volume (void)
{
