	offset = OFF_FROM_HEADER (current_header->oldgnu_header.offset);
	if (stat_data.st_size != current_stat_info.stat.st_size + offset)
	  {
	    report_difference (_("Size differs"));
	    skip_member ();
	    break;
	  }
