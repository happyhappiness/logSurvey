	   || current_header->header.typeflag == BLKTYPE)
	  && current_stat_info.stat.st_rdev != stat_data.st_rdev)
	{
	  report_difference (_("Device number differs"));
	  break;
	}

      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
	{
	  report_difference (_("Mode differs"));
	  break;
	}

