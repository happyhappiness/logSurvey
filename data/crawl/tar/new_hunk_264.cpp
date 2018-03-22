
      /* Appears to be a file.  See if it's really a directory.  */

      if (current_stat_info.had_trailing_slash)
	goto really_dir;

      if (!get_stat_data (current_stat_info.file_name, &stat_data))
	{
	  skip_member ();
	  goto quit;
	}

      if (!S_ISREG (stat_data.st_mode))
	{
	  report_difference (_("File type differs"));
	  skip_member ();
	  goto quit;
	}

      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
	report_difference (_("Mode differs"));

#if !MSDOS
      /* stat() in djgpp's C library gives a constant number of 42 as the
	 uid and gid of a file.  So, comparing an FTP'ed archive just after
	 unpack would fail on MSDOS.  */
      if (stat_data.st_uid != current_stat_info.stat.st_uid)
	report_difference (_("Uid differs"));
      if (stat_data.st_gid != current_stat_info.stat.st_gid)
	report_difference (_("Gid differs"));
#endif

      if (stat_data.st_mtime != current_stat_info.stat.st_mtime)
	report_difference (_("Mod time differs"));
      if (current_header->header.typeflag != GNUTYPE_SPARSE &&
	  stat_data.st_size != current_stat_info.stat.st_size)
	{
	  report_difference (_("Size differs"));
	  skip_member ();
	  goto quit;
	}

      diff_handle = open (current_stat_info.file_name, O_RDONLY | O_BINARY);

      if (diff_handle < 0)
	{
	  open_error (current_stat_info.file_name);
	  skip_member ();
	  report_difference (0);
	  goto quit;
	}

      restore_times.actime = stat_data.st_atime;
      restore_times.modtime = stat_data.st_mtime;

      /* Need to treat sparse files completely differently here.  */

      if (current_header->header.typeflag == GNUTYPE_SPARSE)
	diff_sparse_files ();
      else
	{
	  if (multi_volume_option)
	    {
	      assign_string (&save_name, current_stat_info.file_name);
	      save_totsize = current_stat_info.stat.st_size;
	      /* save_sizeleft is set in read_and_process.  */
	    }

	  read_and_process (current_stat_info.stat.st_size, process_rawdata);

	  if (multi_volume_option)
	    assign_string (&save_name, 0);
	}

      status = close (diff_handle);
      if (status != 0)
	close_error (current_stat_info.file_name);

      if (atime_preserve_option)
	utime (current_stat_info.file_name, &restore_times);

    quit:
      break;
