      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
	report_difference (_("Mode differs"));

      sys_compare_uid_gid (&stat_data, &current_stat_info.stat);

      if (stat_data.st_mtime != current_stat_info.stat.st_mtime)
	report_difference (_("Mod time differs"));
