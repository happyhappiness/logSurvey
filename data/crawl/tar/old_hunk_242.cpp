	if (diff_handle < 0)
	  {
	    open_error (current_stat_info.file_name);
	    report_difference (0);
	    skip_member ();
	    break;
	  }
