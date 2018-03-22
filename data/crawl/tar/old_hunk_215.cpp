	  break;
	if (!get_stat_data (current_stat_info.link_name, &link_data))
	  break;
	sys_compare_links (&stat_data, &link_data);
      }
      break;
      
