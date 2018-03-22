
      if (!S_ISDIR (stat_data.st_mode))
	{
	  report_difference (_("File type differs"));
	  break;
	}

      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
	{
	  report_difference (_("Mode differs"));
	  break;
	}

