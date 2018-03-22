	  : /* current_header->header.typeflag == FIFOTYPE */
	  !S_ISFIFO (stat_data.st_mode))
	{
	  report_difference (&current_stat_info, _("File type differs"));
	  break;
	}

