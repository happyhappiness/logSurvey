
      /* Appears to be a file.  See if it's really a directory.  */

      name_length = strlen (current_file_name) - 1;
      if (current_file_name[name_length] == '/')
	goto really_dir;

      if (!get_stat_data (&stat_data))
	{
	  if (current_header->oldgnu_header.isextended)
	    skip_extended_headers ();
	  skip_file ((long) current_stat.st_size);
	  goto quit;
	}

      if (!S_ISREG (stat_data.st_mode))
	{
	  report_difference (_("Not a regular file"));
	  skip_file ((long) current_stat.st_size);
	  goto quit;
	}

      stat_data.st_mode &= 07777;
      if (stat_data.st_mode != current_stat.st_mode)
	report_difference (_("Mode differs"));

#if !MSDOS
      /* stat() in djgpp's C library gives a constant number of 42 as the
	 uid and gid of a file.  So, comparing an FTP'ed archive just after
	 unpack would fail on MSDOS.  */
      if (stat_data.st_uid != current_stat.st_uid)
	report_difference (_("Uid differs"));
      if (stat_data.st_gid != current_stat.st_gid)
	report_difference (_("Gid differs"));
#endif

      if (stat_data.st_mtime != current_stat.st_mtime)
	report_difference (_("Mod time differs"));
      if (current_header->header.typeflag != GNUTYPE_SPARSE &&
	  stat_data.st_size != current_stat.st_size)
	{
	  report_difference (_("Size differs"));
	  skip_file ((long) current_stat.st_size);
	  goto quit;
	}

      diff_handle = open (current_file_name, O_NDELAY | O_RDONLY | O_BINARY);

      if (diff_handle < 0 && !absolute_names_option)
	{
	  char *tmpbuf = xmalloc (strlen (current_file_name) + 2);

	  *tmpbuf = '/';
	  strcpy (tmpbuf + 1, current_file_name);
	  diff_handle = open (tmpbuf, O_NDELAY | O_RDONLY);
	  free (tmpbuf);
	}
      if (diff_handle < 0)
	{
	  ERROR ((0, errno, _("Cannot open %s"), current_file_name));
	  if (current_header->oldgnu_header.isextended)
	    skip_extended_headers ();
	  skip_file ((long) current_stat.st_size);
	  report_difference (NULL);
	  goto quit;
	}

      /* Need to treat sparse files completely differently here.  */

      if (current_header->header.typeflag == GNUTYPE_SPARSE)
	diff_sparse_files (current_stat.st_size);
      else
	{
	  if (multi_volume_option)
	    {
	      assign_string (&save_name, current_file_name);
	      save_totsize = current_stat.st_size;
	      /* save_sizeleft is set in read_and_process.  */
	    }

	  read_and_process ((long) (current_stat.st_size), process_rawdata);

	  if (multi_volume_option)
	    assign_string (&save_name, NULL);
	}

      status = close (diff_handle);
      if (status < 0)
	ERROR ((0, errno, _("Error while closing %s"), current_file_name));

    quit:
      break;
