
      if (!S_ISREG (stat_data.st_mode))
	{
	  report_difference (_("File type differs"));
	  skip_member ();
	  goto quit;
	}

      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
	report_difference (_("Mode differs"));

      sys_compare_uid_gid (&stat_data, &current_stat_info.stat);

      if (stat_data.st_mtime != current_stat_info.stat.st_mtime)
	report_difference (_("Mod time differs"));
      if (current_header->header.typeflag != GNUTYPE_SPARSE &&
	  stat_data.st_size != current_stat_info.stat.st_size)
	{
	  report_difference (_("Size differs"));
	  skip_member ();
	  goto quit;
	}
