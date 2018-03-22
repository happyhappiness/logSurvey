	  break;
	if (!get_stat_data (current_stat_info.link_name, &link_data))
	  break;
	if (!sys_compare_links (&stat_data, &link_data))
	  report_difference (&current_stat_info,
			     _("Not linked to %s"),
			     quote (current_stat_info.link_name));
      }
      break;
      
