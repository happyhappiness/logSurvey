	  : /* current_header->header.typeflag == FIFOTYPE */
	  !S_ISFIFO (stat_data.st_mode))
	{
	  report_difference (_("File type differs"));
	  break;
	}

