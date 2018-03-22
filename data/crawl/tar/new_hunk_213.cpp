
      if (!S_ISREG (stat_data.st_mode))
	{
	  report_difference (&current_stat_info, _("File type differs"));
	  skip_member ();
	  goto quit;
	}

      if ((current_stat_info.stat.st_mode & MODE_ALL) !=
	  (stat_data.st_mode & MODE_ALL))
	report_difference (&current_stat_info, _("Mode differs"));

      if (!sys_compare_uid (&stat_data, &current_stat_info.stat))
	report_difference (&current_stat_info, _("Uid differs"));
      if (!sys_compare_gid (&stat_data, &current_stat_info.stat))
	report_difference (&current_stat_info, _("Gid differs"));

      if (stat_data.st_mtime != current_stat_info.stat.st_mtime)
	report_difference (&current_stat_info, _("Mod time differs"));
      if (current_header->header.typeflag != GNUTYPE_SPARSE &&
	  stat_data.st_size != current_stat_info.stat.st_size)
	{
	  report_difference (&current_stat_info, _("Size differs"));
	  skip_member ();
	  goto quit;
	}
