    quit:
      break;

    case LNKTYPE:
      {
	struct stat link_data, stat_data;

	if (!get_stat_data (current_stat_info.file_name, &stat_data))
	  break;
	if (!get_stat_data (current_stat_info.link_name, &link_data))
	  break;
	sys_compare_links (&stat_data, &link_data);
      }
      break;
      
#ifdef HAVE_READLINK
    case SYMTYPE:
      {
