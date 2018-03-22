	      readlink_warn (current_stat_info.file_name);
	    else
	      readlink_error (current_stat_info.file_name);
	    report_difference (&current_stat_info, NULL);
	  }
	else if (status != len
		 || strncmp (current_stat_info.link_name, linkbuf, len) != 0)
	  report_difference (&current_stat_info, _("Symlink differs"));

	break;
      }
