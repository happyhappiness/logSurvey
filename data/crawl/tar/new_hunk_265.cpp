#if !MSDOS
    case LNKTYPE:
      {
	struct stat link_data;

	if (!get_stat_data (current_stat_info.file_name, &stat_data))
	  break;
	if (!get_stat_data (current_stat_info.link_name, &link_data))
	  break;

	if (stat_data.st_dev != link_data.st_dev
	    || stat_data.st_ino != link_data.st_ino)
	  {
	    char *message =
	      xmalloc (MESSAGE_BUFFER_SIZE + 4 * strlen (current_stat_info.link_name));

	    sprintf (message, _("Not linked to %s"),
		     quote (current_stat_info.link_name));
	    report_difference (message);
	    free (message);
	    break;
