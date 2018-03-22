	{
	  report_difference (&current_stat_info, _("Size differs"));
	  skip_member ();
	  goto quit;
	}

      diff_handle = open (current_stat_info.file_name, O_RDONLY | O_BINARY);

      if (diff_handle < 0)
	{
	  open_error (current_stat_info.file_name);
	  skip_member ();
	  report_difference (&current_stat_info, NULL);
	  goto quit;
	}

      restore_times.actime = stat_data.st_atime;
      restore_times.modtime = stat_data.st_mtime;

      /* Need to treat sparse files completely differently here.  */

      if (current_stat_info.is_sparse)
	sparse_diff_file (diff_handle, &current_stat_info);
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

    case LNKTYPE:
      {
	struct stat file_data;
	struct stat link_data;

	if (!get_stat_data (current_stat_info.file_name, &file_data))
	  break;
	if (!get_stat_data (current_stat_info.link_name, &link_data))
	  break;
	if (!sys_compare_links (&file_data, &link_data))
	  report_difference (&current_stat_info,
			     _("Not linked to %s"),
			     quote (current_stat_info.link_name));
      }
      break;

#ifdef HAVE_READLINK
    case SYMTYPE:
      {
	size_t len = strlen (current_stat_info.link_name);
	char *linkbuf = alloca (len + 1);

	status = readlink (current_stat_info.file_name, linkbuf, len + 1);

	if (status < 0)
	  {
	    if (errno == ENOENT)
	      readlink_warn (current_stat_info.file_name);
	    else
	      readlink_error (current_stat_info.file_name);
	    report_difference (&current_stat_info, NULL);
	  }
	else if (status != len
		 || strncmp (current_stat_info.link_name, linkbuf, len) != 0)
	  report_difference (&current_stat_info, _("Symlink differs"));

	break;
      }
#endif

    case CHRTYPE:
    case BLKTYPE:
    case FIFOTYPE:

      /* FIXME: deal with umask.  */

      if (!get_stat_data (current_stat_info.file_name, &stat_data))
	break;

      if (current_header->header.typeflag == CHRTYPE
	  ? !S_ISCHR (stat_data.st_mode)
	  : current_header->header.typeflag == BLKTYPE
	  ? !S_ISBLK (stat_data.st_mode)
	  : /* current_header->header.typeflag == FIFOTYPE */
	  !S_ISFIFO (stat_data.st_mode))
	{
	  report_difference (&current_stat_info, _("File type differs"));
	  break;
	}

      if ((current_header->header.typeflag == CHRTYPE
	   || current_header->header.typeflag == BLKTYPE)
	  && current_stat_info.stat.st_rdev != stat_data.st_rdev)
	{
	  report_difference (&current_stat_info, _("Device number differs"));
	  break;
	}

      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
	{
	  report_difference (&current_stat_info, _("Mode differs"));
	  break;
	}

      break;

    case GNUTYPE_DUMPDIR:
      {
	char *dumpdir_buffer = get_directory_contents (current_stat_info.file_name, 0);

	if (multi_volume_option)
	  {
	    assign_string (&save_name, current_stat_info.file_name);
	    save_totsize = current_stat_info.stat.st_size;
	    /* save_sizeleft is set in read_and_process.  */
	  }

	if (dumpdir_buffer)
	  {
	    dumpdir_cursor = dumpdir_buffer;
	    read_and_process (current_stat_info.stat.st_size, process_dumpdir);
	    free (dumpdir_buffer);
	  }
	else
	  read_and_process (current_stat_info.stat.st_size, process_noop);

	if (multi_volume_option)
	  assign_string (&save_name, 0);
	/* Fall through.  */
      }

    case DIRTYPE:
    really_dir:
      if (!get_stat_data (current_stat_info.file_name, &stat_data))
	break;

      if (!S_ISDIR (stat_data.st_mode))
	{
	  report_difference (&current_stat_info, _("File type differs"));
	  break;
	}

      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
	{
	  report_difference (&current_stat_info, _("Mode differs"));
	  break;
	}

      break;

    case GNUTYPE_VOLHDR:
      break;

    case GNUTYPE_MULTIVOL:
      {
	off_t offset;

	if (current_stat_info.had_trailing_slash)
	  goto really_dir;

	if (!get_stat_data (current_stat_info.file_name, &stat_data))
	  break;

	if (!S_ISREG (stat_data.st_mode))
	  {
	    report_difference (&current_stat_info, _("File type differs"));
	    skip_member ();
	    break;
	  }

	offset = OFF_FROM_HEADER (current_header->oldgnu_header.offset);
	if (stat_data.st_size != current_stat_info.stat.st_size + offset)
	  {
	    report_difference (&current_stat_info, _("Size differs"));
	    skip_member ();
	    break;
	  }

	diff_handle = open (current_stat_info.file_name, O_RDONLY | O_BINARY);

	if (diff_handle < 0)
	  {
	    open_error (current_stat_info.file_name);
	    report_difference (&current_stat_info, NULL);
	    skip_member ();
	    break;
	  }

	if (lseek (diff_handle, offset, SEEK_SET) < 0)
	  {
	    seek_error_details (current_stat_info.file_name, offset);
	    report_difference (&current_stat_info, NULL);
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

