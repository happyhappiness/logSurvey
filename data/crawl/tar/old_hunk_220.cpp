
	if (!S_ISREG (stat_data.st_mode))
	  {
	    report_difference (_("File type differs"));
	    skip_member ();
	    break;
	  }
