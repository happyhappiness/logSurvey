
    case LNKTYPE:
      {
	struct stat file_data;
	struct stat link_data;

	if (!get_stat_data (current_stat_info.file_name, &file_data))
	  break;
	if (!get_stat_data (current_stat_info.link_name, &link_data))
	  break;
	if (!sys_compare_links (&file_data, &link_data))
	  report_difference (&current_stat_info,
			     _("Not linked to %s"),
			     quote (current_stat_info.link_name));
      }
      break;

#ifdef HAVE_READLINK
    case SYMTYPE:
      {
